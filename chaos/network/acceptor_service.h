/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ACCEPTOR_SERVICE_H_
#define _CHAOS_ACCEPTOR_SERVICE_H_

/*! 
 *  @file           acceptor_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.11
 *  @brief          acceptor service
 *  @last changed
 *
 */

#include "utility_inc.h"
#include "log_inc.h"
#include "task_service_inc.h"
#include "network_tool.h"
#include "work_service_group.h"
#include "connection.h"

namespace chaos
{

namespace network
{

using namespace chaos::utility;
using namespace chaos::log;
using namespace chaos::task_service;

#define DEFAULT_ACCEPTOR_SERVICE_THREAD_NUM         1

template<typename CONN_TYPE>
class acceptor_service_t : public task_service_t
{
public:
    acceptor_service_t();
    virtual ~acceptor_service_t();

public:
    //! yunjie: 如果service_ptr为NULL, 那么内部将自己new出task_service实例, 并可自动回收
    int initialize(
                    const string& host,
                    uint32_t port_,
                    work_service_group_t* work_service_group_,
                    connection_t::on_conn_event_t event_func_
                    );
    int start(int thread_num_ = DEFAULT_ACCEPTOR_SERVICE_THREAD_NUM);
    int stop();

private:
    static void on_listen_callback(fd_t, int, void*);

    int start_listen_i();
    int stop_listen_i();

private:
    bool                                        m_started;
    bool                                        m_inited;
    uint32_t                                    m_listen_address;           //! yunjie: 本机字节序
    uint32_t                                    m_listen_port;              //! yunjie: 本机字节序
    int                                         m_thread_num;
    work_service_group_t*                       m_work_service_group_ptr;
    fd_t                                        m_listen_socket;
    connection_t::on_conn_event_t               m_event_func;
};

template<typename CONN_TYPE>
acceptor_service_t<CONN_TYPE>::acceptor_service_t()
    :
        task_service_t("acceptor_service"),
        m_started(false),
        m_inited(false),
        m_listen_address(0),
        m_listen_port(0),
        m_thread_num(DEFAULT_ACCEPTOR_SERVICE_THREAD_NUM),
        m_work_service_group_ptr(NULL),
        m_listen_socket(0),
        m_event_func(NULL)
{
}

template<typename CONN_TYPE>
int acceptor_service_t<CONN_TYPE>::initialize(const string& host_, uint32_t port_, work_service_group_t* work_service_group_, connection_t::on_conn_event_t event_func_)
{
    if (m_inited)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::initialize service has inited, return."));
        return -1;
    }

    if (NULL == work_service_group_)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::initialize work_service_group is NULL, return."));
        return -1;
    }

    m_listen_address = network_tool_t::ipv4_string_to_int(host_);
    m_listen_port = port_;
    m_work_service_group_ptr = work_service_group_;
    m_event_func = event_func_;
    m_inited = true;

    return 0;
}

template<typename CONN_TYPE>
acceptor_service_t<CONN_TYPE>::~acceptor_service_t()
{
    stop();
}

template<typename CONN_TYPE>
int acceptor_service_t<CONN_TYPE>::start(int thread_num_)
{
    if (!m_inited)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start service has not inited, return."));
        return -1;
    }

    if (m_started)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start service has started, return."));
        return 0;
    }

    //! yunjie: 调用父类start函数启动线程
    if (-1 == task_service_t::start(thread_num_))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start task_service start failed, return."));
        return -1;
    }

    m_thread_num = thread_num_;

    //! yunjie: 发起一个异步事件 - 注册监听端口
    this->post(async_method_t::bind_memfunc(this, &acceptor_service_t::start_listen_i));

    m_started = true;

    return 0;
}

template<typename CONN_TYPE>
int acceptor_service_t<CONN_TYPE>::stop()
{
    if (!m_started)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::stop service has stopped, return."));
        return 0;
    }

    //! yunjie: 从epoll中移除 m_listen_socket
    this->remove_fd_from_epoll(m_listen_socket);

    //! yunjie: 关闭监听socket
    this->post(async_method_t::bind_memfunc(this, &acceptor_service_t::stop_listen_i));

    task_service_t::stop();

    m_started = false;

    return 0;
}

template<typename CONN_TYPE>
int acceptor_service_t<CONN_TYPE>::start_listen_i()
{
    int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i generate sockfd failed."));
        return -1;
    }

    int reuse = 1;
    //! yunjie: reuse选项, 关闭后不进入timewait状态
    if(-1 == setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i set socket option reuse failed."));
        TEMP_FAILURE_RETRY(::close(sockfd));

        return -1;
    }


    //! yunjie: 窗口大小设置
    int bufSize = 64 * 1024;
    if(-1 == setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &bufSize, sizeof(bufSize)))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i set socket option size of rcvbuf failed."));
        TEMP_FAILURE_RETRY(::close(sockfd));

        return -1;
    }
    if(-1 == setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &bufSize, sizeof(bufSize)))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i set socket option size of sndbuf failed."));
        TEMP_FAILURE_RETRY(::close(sockfd));

        return -1;
    }

    //! yunjie: 设置监听描述符为nonblock
    if (-1 == network_tool_t::make_socket_nonblocking(sockfd))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i make_socket_nonblocking failed"));
    }

    struct sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(m_listen_port);
    local_addr.sin_addr.s_addr = htonl(m_listen_address);
    bzero(local_addr.sin_zero, sizeof(local_addr.sin_zero));

    if(-1 == ::bind(sockfd, (struct sockaddr *)&local_addr, sizeof(local_addr)))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i bind failed."));
        TEMP_FAILURE_RETRY(::close(sockfd));

        return -1;
    }

    if(-1 == ::listen(sockfd, 128))         //! yunjie: 128是三次握手的积压队列大小, 目前系统都无视了, 大家也无视吧 
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::start_listen_i listen failed."));
        TEMP_FAILURE_RETRY(::close(sockfd));

        return -1;
    }

    m_listen_socket = sockfd;

    //! yunjie: 注册到task_service的io_multiplex中去
    this->register_io_event(
                                            m_listen_socket,
                                            READ_EVENT_FLAG,                            //! yunjie: 只监听读事件
                                            &acceptor_service_t::on_listen_callback,
                                            this,
                                            true                                       //! yunjie: 该事件是否持续, 由于是监听读事件, 所以一直需要持续
                                        );

    return 0;
}

template<typename CONN_TYPE>
int acceptor_service_t<CONN_TYPE>::stop_listen_i()
{
    //! yunjie: 关闭监听socket
    //! yunjie: 注 - SHUT_RD保证接受缓冲区的数据全被丢弃
    //！        再close将不会发送RST报文
    ::shutdown(m_listen_socket, SHUT_RD);
    TEMP_FAILURE_RETRY(::close(m_listen_socket));

    return 0;
}

template<typename CONN_TYPE>
void acceptor_service_t<CONN_TYPE>::on_listen_callback(fd_t fd_, int event_type_, void* arg_)
{
    if (NULL == arg_)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback arg_ is NULL, args-[fd:%d, event_type:%d], return", fd_, event_type_));
        return;
    }

    //! yunjie: 获得该监听socket对应的acceptor_service_t
    acceptor_service_t* as_ptr = (acceptor_service_t*)arg_;

    //! yunjie: 拿到acceptor_service_t内部的work_service_group_t
    work_service_group_t* work_group_ptr = as_ptr->m_work_service_group_ptr;
    if (NULL == work_group_ptr)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback work_group_ptr is NULL, args-[fd:%d, event_type:%d], return", fd_, event_type_));
        return;
    }

    struct sockaddr peer_addr;
    socklen_t sin_size;
    int accepted_fd = ::accept(fd_, &peer_addr, &sin_size);
    LOGDEBUG((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback accepted_fd:%d end", accepted_fd));

    if (-1 == accepted_fd)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback accept failed accepted_fd is [%d], errno:[%m] args-[fd:%d, event_type:%d], return", accepted_fd, errno, fd_, event_type_));
        return;
    }

    //! yunjie: 设置描述符为nonblock
    if (-1 == network_tool_t::make_socket_nonblocking(accepted_fd))
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback make_socket_nonblocking failed"));
    }

    //! yunjie: 为connection_t绑定work_service, 根据accepted_fd模到相应的work_service_group中对应的work_service(linux进程空间中fd从1递增)
    work_service_t* work_ptr = (work_service_t*)((*work_group_ptr)[accepted_fd % work_group_ptr->size()]);
    if (NULL == work_ptr)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback work_ptr is NULL, args-[fd:%d, event_type:%d], return", fd_, event_type_));
        return;
    }

    struct timeval now = as_ptr->m_timer_manager.get_cached_time();

    conn_ptr_t conn_ptr = new CONN_TYPE;
    if (NULL == conn_ptr)
    {
        LOGWARN((ACCEPTOR_SERVICE_MODULE, "acceptor_service_t::on_listen_callback new conn_ptr failed, args-[fd:%d, event_type:%d], return", fd_, event_type_));
        return;
    }

    conn_ptr->initialize(accepted_fd, now, work_ptr, T_PASSIVE, as_ptr->m_event_func, work_ptr->is_enable_hb());

    work_ptr->async_add_connection(conn_ptr);
}

}

}


#endif //! _CHAOS_ACCEPTOR_SERVICE_H_
