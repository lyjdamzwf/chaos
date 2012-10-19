/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include <netinet/tcp.h>

#include <chaos/network/connection.h>
#include <chaos/network/work_service.h>

/*!
 *  @file           connection.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.16
 *  @brief          connection
 *  @last changed
 *
 */

namespace chaos
{

namespace network
{

//! ------------------------------------ static function begin ------------------------------------

void connection_t::on_peer_event(fd_t fd_, int event_type_, void* arg_)
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::on_peer_event args-[fd:%d, event_type:%d] begin", fd_, event_type_));

    conn_ptr_t conn = (conn_ptr_t)arg_;
    if (NULL == conn)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::on_peer_event arg_ is NULL, return. args-[fd:%d, event_type:%d]", fd_, event_type_));
        return;
    }

    task_service_t* service_ptr = conn->get_service_ptr();
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::on_peer_event service_ptr is NULL, return. args-[fd:%d, event_type:%d]", fd_, event_type_));
        return;
    }

    switch (event_type_)
    {
        case IO_READ_EVENT:
        {
            conn->on_recv_data();
        }
        break;
        case IO_WRITE_EVENT:
        {
            conn->on_send_data();
        }
        break;
        case IO_ERROR_EVENT:
        {
            conn->on_error_occur();
        }
        break;
        default:
        {
            LOGWARN((CONNECTION_MODULE, "connection_t::on_peer_event event_type error args-[fd:%d, event_type:%d]", fd_, event_type_));
        }
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::on_peer_event args-[fd:%d, event_type:%d] end", fd_, event_type_));
}

int connection_t::async_close(const struct conn_id_t& conn_id_, bool is_del_from_hb_, conn_event_e close_type_)
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::async_close args-[fd:%d] begin", conn_id_.socket));

    work_service_t* service_ptr = conn_id_.service_ptr;
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::async_close error args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    //! yunjie: sync_close_i操作必须放到队列中执行, 因为其中会delete connection_t对象, 所以最后一个参数为false
    service_ptr->post(bindfunc(&connection_t::sync_close_i, conn_id_, is_del_from_hb_, close_type_), NULL, TASK_PRIOR_NORMAL, false);

    LOGTRACE((CONNECTION_MODULE, "connection_t::async_close args-[fd:%d] end", conn_id_.socket));
    return 0;
}

int connection_t::async_send(const struct conn_id_t& conn_id_, packet_wrapper_t& msg_, bool auto_clear_)
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::async_send begin"));

    work_service_t* service_ptr = conn_id_.service_ptr;
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::async_send service_ptr is NULL, return."));
        return -1;
    }

    service_ptr->post(bindfunc(&connection_t::sync_send_wrapper_i, conn_id_, msg_, auto_clear_));

    if (auto_clear_)
    {
        msg_.reset();
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::async_send end"));
    return 0;
}

int connection_t::async_send(const struct conn_id_t& conn_id_, const char* msg_, uint32_t size_)
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::async_send begin"));

    work_service_t* service_ptr = conn_id_.service_ptr;
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::async_send service_ptr is NULL, return."));
        return -1;
    }

    if (service_ptr->is_run_on_service())
    {
        //! yunjie: 本线程既直接调用, 传递指针
        sync_send_i(conn_id_, msg_, size_);
    }
    else
    {
        //! yunjie: 为保证数据跨线程安全性, 包装成packet_wrapper_t, post异步消息
        packet_wrapper_t msg_wrapper(msg_, size_);
        service_ptr->post(bindfunc(&connection_t::sync_send_wrapper_i, conn_id_, msg_wrapper, true));
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::async_send end"));
    return 0;
}

int connection_t::sync_close_i(const struct conn_id_t& conn_id_, bool is_del_from_hb_, conn_event_e close_type_)
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::sync_close_i args-[fd:%d] begin", conn_id_.socket));

    work_service_t* service_ptr = conn_id_.service_ptr;
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_close_i error, return. args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    conn_ptr_t conn_ptr = service_ptr->get_conn(conn_id_);
    if (NULL == conn_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_close_i connection not found, it maybe closed, return. args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    if (ST_CLOSED == conn_ptr->get_status())
    {
        LOGTRACE((CONNECTION_MODULE, "connection_t::sync_close_i connection has closed, return. args-[fd:%d]", conn_id_.socket));
        return 0;
    }

    //! yunjie: 关闭connection的socket fd, 从epoll中移除
    conn_ptr->close_i();

    if (is_del_from_hb_ && conn_ptr->is_enable_hb())
    {
        //! yunjie: 从heart_beart中删除connection
        service_ptr->async_del_hb_element(conn_ptr->m_conn_id);
    }

    //! yunjie: connection的一些数据要先拷贝出来,
    //!         因为之后的async_del_connection会
    //!         delete connection对象
    conn_status_e conn_status = conn_ptr->get_status();
    on_conn_event_t event_callback = conn_ptr->m_conn_event_callback;
    void* user_data = conn_ptr->m_user_data;

    //! yunjie: 释放操作有可能是在本线程直接执行, 所以必须放最后
    if (EV_DECONSTRUCT != close_type_)
    {
        //! yunjie: 从管理中移除connection并释放(delete)
        //!         注: 其实这里的async_del_connection是同步执行的,
        //!         因为sync_close_i肯定是在work线程上工作的, 所以
        //!         不需要在投递消息到队列异步执行
        service_ptr->async_del_connection(conn_id_);
    }

    //! yunjie: 在delete之后callback被调用, 否则可能会有许多运行时警告
    if (NULL != event_callback)
    {
        //! yunjie: 调用用户注册的回调
        event_callback(close_type_, conn_status, conn_id_, user_data);
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::sync_close_i args-[fd:%d] end", conn_id_.socket));
    return 0;
}

int connection_t::sync_send_wrapper_i(
                                        const struct conn_id_t& conn_id_,
                                        packet_wrapper_t&       msg_,
                                        bool                    auto_clear_
                                     )
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::sync_send_wrapper_i args-[fd:%d] begin", conn_id_.socket));

    SAFE_FREE_HOLDER(auto_clear_, msg_);

    work_service_t* service_ptr = conn_id_.service_ptr;
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_send_wrapper_i error, return. args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    conn_ptr_t conn_ptr = service_ptr->get_conn(conn_id_);
    if (NULL == conn_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_send_wrapper_i close failed, because connection not found, return. args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    if (ST_CLOSED == conn_ptr->get_status())
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_send_wrapper_i connection has closed, return. args-[fd:%d]", conn_id_.socket));
        return 0;
    }

    conn_ptr->m_write_buffer.append(msg_.data(), msg_.size());
    conn_ptr->start_drive_send_i();

    LOGTRACE((CONNECTION_MODULE, "connection_t::sync_send_wrapper_i args-[fd:%d] end", conn_id_.socket));
    return 0;
}

int connection_t::sync_send_i(
                                    const struct conn_id_t& conn_id_,
                                    const char* msg_,
                                    uint32_t size_
                                   )
{
    work_service_t* service_ptr = conn_id_.service_ptr;
    if (NULL == service_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_send_i error, return. args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    conn_ptr_t conn_ptr = service_ptr->get_conn(conn_id_);
    if (NULL == conn_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_send_i close failed, because connection not found, return. args-[fd:%d]", conn_id_.socket));
        return -1;
    }

    if (ST_CLOSED == conn_ptr->get_status())
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::sync_send_i connection has closed, return. args-[fd:%d]", conn_id_.socket));
        return 0;
    }

    conn_ptr->m_write_buffer.append(msg_, size_);
    conn_ptr->start_drive_send_i();

    return 0;
}

//! ------------------------------------ static function end ------------------------------------





//! ------------------------------------ member function begin ------------------------------------

connection_t::connection_t()
    :
        m_socket(0),
        m_service_ptr(NULL),
        m_conn_type(T_UNKNOWN),
        m_conn_status(ST_UNKNOWN),
        m_conn_event_callback(NULL),
        m_sending_flag(false),
        m_enable_hb(false),
        m_user_data(NULL)
{
    memset(&m_timestamp, 0, sizeof(struct timeval));
}

connection_t::~connection_t()
{
    if (NULL != m_conn_event_callback)
    {
        m_conn_event_callback(EV_DECONSTRUCT, m_conn_status, m_conn_id, m_user_data);
    }

    //! yunjie: 释放I/O缓冲区内存
    m_read_buffer.clear();
    m_write_buffer.clear();
}


int connection_t::initialize(fd_t socket_, struct timeval timestamp_, work_service_t* work_service_, conn_type_e conn_type_, on_conn_event_t event_func_, network_config_t* config_, bool enable_hb_)
{
    int ret = 0;

    //! yunjie: 设置描述符为nonblock
    if (-1 == network_tool_t::make_socket_nonblocking(socket_))
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::initialize make_socket_nonblocking failed"));
        ret = -1;
    }

    //! yunjie: 初始化成员
    m_socket = socket_;
    m_timestamp.tv_sec = timestamp_.tv_sec;
    m_timestamp.tv_usec = timestamp_.tv_usec;
    m_service_ptr = work_service_;

    //! yunjie: conn id
    m_conn_id.socket = socket_;
    m_conn_id.timestamp.tv_sec = timestamp_.tv_sec;
    m_conn_id.timestamp.tv_usec = timestamp_.tv_usec;
    m_conn_id.service_ptr = work_service_;

    m_conn_type = conn_type_;
    m_conn_status = ST_ESTABLISHED;

    m_conn_event_callback = event_func_;

    m_config_holder.set_config(config_);

    m_enable_hb = enable_hb_;

    //! yunjie: 设置I/O缓冲区的最大字节数
    m_write_buffer.set_buffer_max_limit((*m_config_holder).max_send_buffer_size);
    m_read_buffer.set_buffer_max_limit((*m_config_holder).max_read_buffer_size);

    //! yunjie: 初始化套接字选项
    if (T_ACTIVE == conn_type_)
    {
        //! yunjie: 窗口大小设置
        int sndbuf_size = (*m_config_holder).tcp_sndbuf_size;
        if(-1 == ::setsockopt(m_socket, SOL_SOCKET, SO_SNDBUF, &sndbuf_size, sizeof(sndbuf_size)))
        {
            LOGWARN((CONNECTION_MODULE, "connection_t::initialize set socket option size of sndbuf failed."));
            TEMP_FAILURE_RETRY(::close(m_socket));
            ret = -1;
        }

        int rcvbuf_size = (*m_config_holder).tcp_rcvbuf_size;
        if(-1 == ::setsockopt(m_socket, SOL_SOCKET, SO_RCVBUF, &rcvbuf_size, sizeof(rcvbuf_size)))
        {
            LOGWARN((CONNECTION_MODULE, "connection_t::initialize set socket option size of rcvbuf failed."));
            TEMP_FAILURE_RETRY(::close(m_socket));
            ret = -1;
        }
    }

    //! yunjie: 屏蔽nagling算法,防止数据量小的指令被打包发送
    if ((*m_config_holder).is_enable_tcp_nodelay)
    {
        int nodelay = 1;
        if(::setsockopt(m_socket, IPPROTO_TCP, TCP_NODELAY, (void*)&nodelay, sizeof(nodelay)))
        {
            LOGWARN((CONNECTION_MODULE, "connection_t::initialize set nodelay failed socket:[%u]", m_socket));
            ret = -1;
        }
    }

    //! yunjie: connection初始化完毕, 回调通知上层
    if (NULL != m_conn_event_callback)
    {
        m_conn_event_callback(EV_INIT_COMPLETE, m_conn_status, m_conn_id, m_user_data);
    }

    //! yunjie: 注册到event loop中
    work_service_->async_add_connection(this);

    if (m_enable_hb)
    {
        m_service_ptr->async_add_hb_element(m_conn_id);
    }

    //! yunjie: connection已加入到event loop中, 回调通知上层
    if (NULL != m_conn_event_callback)
    {
        conn_event_e conn_ev;
        if (T_PASSIVE == m_conn_type)
        {
            conn_ev = EV_ACCEPTED_COMPLETE;
        }
        else if (T_ACTIVE == m_conn_type)
        {
            conn_ev = EV_CONNECT_SUCCESS;
        }
        else
        {
            conn_ev = EV_UNKNOWN;
        }

        m_conn_event_callback(conn_ev, m_conn_status, m_conn_id, m_user_data);
    }

    return ret;
}

int connection_t::on_recv_data()
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::on_recv_data begin"));

    if (m_enable_hb)
    {
        m_service_ptr->async_update_hb_element(m_conn_id);
    }

    int recv_ret = 0;
    int ret = m_read_buffer.recv_to_buffer(m_socket, recv_ret);
    if (-1 == ret)
    {
        //! yunjie: 内存分配失败, 必须回调callback, 否则buffer满了将陷入死循环
        LOGWARN((CONNECTION_MODULE, "connection_t::on_recv_data recv_to_buffer failed socket fd:[%u] read buf data size:[%u]",
                m_socket,
                m_read_buffer.size()
                ));

        on_read_complete(m_read_buffer);

        return 0;
    }

    if (0 == recv_ret)
    {
        LOGWARN((CONNECTION_MODULE, "connection_t::on_recv_data recv_ret == 0 socket fd:[%u]", m_socket));

        async_close(m_conn_id, true, EV_PASSIVE_CLOSED);

        return 0;
    }
    else if (recv_ret < 0)
    {
        //! yunjie: 如果不是EAGAIN或EINTR, 那么就调用callback返回错误信息
        if (errno != EAGAIN && errno != EINTR)
        {
            if (NULL != m_conn_event_callback)
            {
                m_conn_event_callback(EV_ERROR_OCCURRED, m_conn_status, m_conn_id, m_user_data);
            }
        }

        LOGWARN((CONNECTION_MODULE, "connection_t::on_recv_data recv_ret:[%d] socket fd:[%u] errno:[%s]", recv_ret, m_socket, STRERR));

        return 0;
    }
    else
    {
        //! yunjie: 使用者可以实现的虚方法
        on_read_complete(m_read_buffer);
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::on_recv_data end"));
    return 0;
}

int connection_t::on_send_data()
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::on_send_data begin"));

    if (m_enable_hb)
    {
        m_service_ptr->async_update_hb_element(m_conn_id);
    }

    uint32_t transferred_size = 0;

    while (m_write_buffer.size())
    {
        uint32_t msg_size = m_write_buffer.size();
        int32_t ret = ::send(m_socket, m_write_buffer.data(), msg_size, 0);

        if (0 == ret)
        {
            LOGWARN((CONNECTION_MODULE, "connection_t::on_send_data send ret == 0 socket fd:[%u]", m_socket));

            async_close(m_conn_id, true, EV_PASSIVE_CLOSED);
            return 0;
        }
        else if (ret < 0)
        {
            if (EINTR == errno)
            {
                //! yunjie: 立刻重新send
                LOGWARN((CONNECTION_MODULE, "connection_t::on_send_data recv EINTR send ret:[%d] socket fd:[%u] errno:[%s]",
                            ret, m_socket, STRERR
                        ));
                continue;
            }
            else if (EAGAIN == errno)
            {
                //! yunjie: 重新注册I/O事件
                m_service_ptr->register_io_event(
                        m_socket,
                        WRITE_EVENT_FLAG,
                        &connection_t::on_peer_event,
                        (void*)this,
                        false
                        );
            }
            else
            {
                //! yunjie: 非EINTR,非EAGAIN, 调用上层错误处理函数
                if (NULL != m_conn_event_callback)
                {
                    m_conn_event_callback(EV_ERROR_OCCURRED, m_conn_status, m_conn_id, m_user_data);
                }
            }

            LOGWARN((CONNECTION_MODULE, "connection_t::on_send_data send ret:[%d] socket fd:[%u] errno:[%s]",
                        ret, m_socket, STRERR
                    ));
            break;
        }
        else
        {
            transferred_size += ret;

            m_write_buffer.drain_size(ret);

            if (ret != (int32_t)msg_size)
            {
                m_service_ptr->register_io_event(
                        m_socket,
                        WRITE_EVENT_FLAG,
                        &connection_t::on_peer_event,
                        (void*)this,
                        false
                        );
                break;
            }
        }
    }

    if (transferred_size)
    {
        //! yunjie: 使用者可以实现的虚方法
        on_write_complete(transferred_size);
    }

    if (!m_write_buffer.size())
    {
        m_sending_flag = false;
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::on_send_data end"));
    return 0;
}

int connection_t::on_error_occur()
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::on_error_occur begin"));

    if (NULL != m_conn_event_callback)
    {
        //! yunjie: 调用用户注册的回调
        m_conn_event_callback(EV_ERROR_OCCURRED, m_conn_status, m_conn_id, m_user_data);
    }

    LOGTRACE((CONNECTION_MODULE, "connection_t::on_error_occur end"));
    return 0;
}

int connection_t::start_drive_send_i()
{
    if (!m_sending_flag)
    {
        //! yunjie: 注册写事件, 非persist
        m_service_ptr->register_io_event(
                                        m_socket,
                                        WRITE_EVENT_FLAG,
                                        &connection_t::on_peer_event,
                                        (void*)this,
                                        false
                                        );

        m_sending_flag = true;

        return 0;
    }

    return 1;
}

int connection_t::close_i()
{
    LOGTRACE((CONNECTION_MODULE, "connection_t::close_i begin"));

    //! yunjie: 从epoll中删除对fd的管理
    m_service_ptr->remove_fd_from_epoll(m_socket);

    ::close(m_socket);

    m_conn_status = ST_CLOSED;
    m_read_buffer.clear();
    m_write_buffer.clear();

    LOGTRACE((CONNECTION_MODULE, "connection_t::close_i end"));
    return 0;
}

//! ------------------------------------ member function end ------------------------------------

}

}
