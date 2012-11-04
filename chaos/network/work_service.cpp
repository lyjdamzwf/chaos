/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include <chaos/network/work_service.h>

/*!
 *  @file           work_service.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.17
 *  @brief          work service
 *  @last changed
 *
 */

namespace chaos
{

namespace network
{


work_service_t::work_service_t(const string& service_name_)
    :
        task_service_t(service_name_),
        m_enable_conn_heart_beat(false)
{
    m_conn_vct.resize(DEFAULT_CONN_VCT_SIZE, NULL);
}

work_service_t::~work_service_t()
{
    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::~work_service_t"));
}

void work_service_t::conn_timedout_callback(conn_id_t& conn_id_)
{
    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::conn_timedout_callback begin"));

    connection_t::async_close(conn_id_, false, EV_TIMEOUT_CLOSED);

    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::conn_timedout_callback end"));
}

int work_service_t::start_heart_beat_service(const conn_heart_beat_param_t& param_)
{
    m_conn_heart_beat.set_callback_function(work_service_t::conn_timedout_callback);
    m_conn_heart_beat.set_timeout(param_.timeout_flag, param_.timeout);
    m_conn_heart_beat.set_max_limit(param_.max_limit_flag, param_.max_limit);
    m_enable_conn_heart_beat = true;
    m_conn_heart_beat.initialize(this);

    return m_conn_heart_beat.start();
}

int work_service_t::start(int32_t thread_num_)
{
    task_service_t::start(thread_num_);

    return 0;
}

int work_service_t::stop()
{
    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::stop begin"));

    this->post(bindfunc(this, &work_service_t::sync_close_all_conn_i));

    if (m_enable_conn_heart_beat)
    {
        m_conn_heart_beat.stop();
        m_enable_conn_heart_beat = false;
    }

    //! yunjie: 发送线程停止信号并pthread_join
    task_service_t::stop();

    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::stop end"));
    return 0;
}


int work_service_t::async_add_connection(const conn_sptr_t& conn_sptr_)
{
    this->post(bindfunc(this, &work_service_t::sync_add_connection_i, conn_sptr_));

    return 0;
}


int work_service_t::async_del_connection(const conn_id_t& conn_id_)
{
    this->post(bindfunc(this, &work_service_t::sync_del_connection_i, conn_id_));

    return 0;
}

int work_service_t::async_broadcast(
                                    const packet_wrapper_t&     msg_,
                                    broadcast_filter_t          filter_
                                   )
{
    this->post(
            bindfunc(
                this,
                &work_service_t::sync_broadcast_packet_wrapper_i,
                msg_,
                filter_
                )
            );

    return 0;
}


int work_service_t::async_broadcast(
                                    const char*                 msg_,
                                    uint32_t                    size_,
                                    broadcast_filter_t          filter_
                                   )
{
    if (is_run_on_service())
    {
        //! yunjie: 在本线程上, 不需拷贝数据, 直接调用传入数据指针
        sync_broadcast_data_i(msg_, size_, filter_);
    }
    else
    {
        packet_wrapper_t msg_wrapper(msg_, size_);
        this->post(
                bindfunc(
                    this,
                    &work_service_t::sync_broadcast_packet_wrapper_i,
                    msg_wrapper,
                    filter_
                    )
                );
    }

    return 0;
}

void work_service_t::async_add_hb_element(conn_id_t& conn_id_)
{
    m_conn_heart_beat.async_add_element(conn_id_);
}

void work_service_t::async_update_hb_element(conn_id_t& conn_id_)
{
    m_conn_heart_beat.async_update_element(conn_id_);
}

void work_service_t::async_del_hb_element(conn_id_t& conn_id_)
{
    m_conn_heart_beat.async_del_element(conn_id_);
}

conn_sptr_t work_service_t::get_conn(const conn_id_t& conn_id_)
{
    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::get_conn  begin"));

    fd_t peer_socket = conn_id_.socket;
    if (peer_socket >= m_conn_vct.size())
    {
        LOGWARN((WORK_SERVICE_MODULE, "work_service_t::get_conn fd is too big, return."));
        return NULL;
    }

    conn_sptr_t& conn_sptr = m_conn_vct[peer_socket];

    if (NULL != conn_sptr)
    {
        //! yunjie: 防止fd回绕, 根据时间戳判断是否的确是同一个connection,
        //          有可能这个connection是新生成的"替身"连接
        if (
                conn_id_.timestamp.tv_sec != conn_sptr->get_timestamp().tv_sec
                ||
                conn_id_.timestamp.tv_usec != conn_sptr->get_timestamp().tv_usec
           )
        {
            LOGWARN((WORK_SERVICE_MODULE,
                        "work_service_t::get_conn connection timestamp error, return. arg-[fd:%d]",
                        peer_socket
                   ));
            return NULL;
        }
    }


    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::get_conn  end"));
    return conn_sptr;
}


int work_service_t::sync_close_all_conn_i()
{
    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::sync_close_all_conn_i begin"));

    for (vector<conn_sptr_t>::iterator it = m_conn_vct.begin(); it != m_conn_vct.end(); ++it)
    {
        conn_sptr_t conn_sptr = *it;
        if (NULL != conn_sptr)
        {
            //! yunjie: 参数false - 由于是进程关闭时才会sync_close_all_conn_i
            //          所以不需要在关闭connection时从heart beat中删除. 否则
            //          会有大量"heart beat element not found"的警告日志
            connection_t::async_close(conn_sptr->get_conn_id(), false);
        }
    }

    LOGTRACE((WORK_SERVICE_MODULE, "work_service_t::sync_close_all_conn_i end"));
    return 0;
}

int work_service_t::sync_add_connection_i(const conn_sptr_t& conn_sptr_)
{
    LOGTRACE((WORK_SERVICE_MODULE,
                "work_service_t::sync_add_connection_i arg-[fd:%d] begin",
                conn_sptr_->native_socket()
            ));

    if (is_recv_stop_signal())
    {
        //! yunjie: 如果收到停止信号, 那么不再接受新连接
        LOGWARN((WORK_SERVICE_MODULE, "work_service_t::sync_add_connection_i has recv stop signal, return"));
        return -1;
    }

    task_service_t* service_ptr = conn_sptr_->get_service_ptr();
    fd_t peer_socket = conn_sptr_->native_socket();

    if (peer_socket >= m_conn_vct.size())
    {
        m_conn_vct.resize(peer_socket);
        if (m_conn_vct.size() != peer_socket)
        {
            LOGWARN((WORK_SERVICE_MODULE,
                        "work_service_t::sync_add_connection_i resize m_conn_vct failed arg-[fd:%d] return.",
                        peer_socket
                   ));
            return -1;
        }
    }

    conn_sptr_t& conn_sptr = m_conn_vct[peer_socket];
    if (NULL != conn_sptr)
    {
        LOGWARN((WORK_SERVICE_MODULE,
                    "work_service_t::sync_add_connection_i fd conflict arg-[fd:%d] return.",
                    peer_socket
               ));

        //! yunjie: 不需要在这里close socket, 析构时保证
        conn_sptr.reset();
    }
    conn_sptr = conn_sptr_;

    //! yunjie: 注册读事件, 为persist
    service_ptr->register_io_event(
                                    peer_socket,
                                    READ_EVENT_FLAG,
                                    &connection_t::on_peer_event,
                                    (void*)conn_sptr_.get(),
                                    true
                                );

    //! yunjie: 注册错误处理事件, 无视persist
    service_ptr->register_io_event(
                                    peer_socket,
                                    ERROR_EVENT_FLAG,
                                    &connection_t::on_peer_event,
                                    (void*)conn_sptr_.get()
                                );

    LOGTRACE((WORK_SERVICE_MODULE,
                "work_service_t::sync_add_connection_i arg-[fd:%d] end",
                conn_sptr_->native_socket()
            ));
    return 0;
}

int work_service_t::sync_del_connection_i(const conn_id_t& conn_id_)
{
    LOGTRACE((WORK_SERVICE_MODULE,
                "work_service_t::sync_del_connection_i arg-[fd:%d] begin",
                conn_id_.socket
            ));

    fd_t peer_socket = conn_id_.socket;
    if (peer_socket >= m_conn_vct.size())
    {
        LOGWARN((WORK_SERVICE_MODULE,
                    "work_service_t::sync_del_connection_i fd is too big, return. arg-[fd:%d]",
                    peer_socket
               ));
        return -1;
    }

    conn_sptr_t& conn_sptr = m_conn_vct[peer_socket];

    if (NULL == conn_sptr)
    {
        LOGWARN((WORK_SERVICE_MODULE,
                    "work_service_t::sync_del_connection_i the connection not found, return. arg-[fd:%d]",
                    peer_socket
               ));
        return -1;
    }

    //! yunjie: 防止fd回绕, 根据时间戳判断是否的确是同一个connection,
    //          有可能这个connection是新生成的"替身"连接
    if (
        conn_id_.timestamp.tv_sec != conn_sptr->get_timestamp().tv_sec
        ||
        conn_id_.timestamp.tv_usec != conn_sptr->get_timestamp().tv_usec
       )
    {
        LOGWARN((WORK_SERVICE_MODULE,
                    "work_service_t::sync_del_connection_i connection timestamp error, return. arg-[fd:%d]",
                    peer_socket
               ));
        return -1;
    }

    //! yunjie: 将conn_sptr置为NULL
    conn_sptr.reset();

    LOGTRACE((WORK_SERVICE_MODULE,
                "work_service_t::sync_del_connection_i arg-[fd:%d] end",
                conn_id_.socket
            ));
    return 0;
}

int work_service_t::sync_broadcast_packet_wrapper_i(
        const packet_wrapper_t&     msg_,
        broadcast_filter_t          filter_
        )
{
    for (vector<conn_sptr_t>::iterator it = m_conn_vct.begin(); it != m_conn_vct.end(); ++it)
    {
        conn_sptr_t conn_sptr = *it;

        if (NULL != conn_sptr)
        {
            const conn_id_t& conn_id = conn_sptr->get_conn_id();
            if (filter_)
            {
                if (!filter_(conn_id, conn_sptr->get_userdata()))
                    continue;
            }

            connection_t::sync_send_wrapper_i(
                        conn_id,
                        msg_
                    );
        }
    }

    return 0;
}

int work_service_t::sync_broadcast_data_i(
        const char*                 msg_,
        uint32_t                    size_,
        broadcast_filter_t          filter_
        )
{
    for (vector<conn_sptr_t>::iterator it = m_conn_vct.begin(); it != m_conn_vct.end(); ++it)
    {
        conn_sptr_t conn_sptr = *it;

        if (NULL != conn_sptr)
        {
            const conn_id_t& conn_id = conn_sptr->get_conn_id();
            if (filter_)
            {
                if (!filter_(conn_id, conn_sptr->get_userdata()))
                    continue;
            }

            connection_t::sync_send_i(
                        conn_id,
                        msg_,
                        size_
                    );

        }
    }

    return 0;
}

}

}
