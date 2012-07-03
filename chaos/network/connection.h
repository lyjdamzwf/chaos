/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_CONNECTION_H_
#define _CHAOS_CONNECTION_H_

/*! 
 *  @file           connection.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.16
 *  @brief          connection_t对象对应chaos tcp_server中的所有socket, 
 *                  connection_t的所有'非'public static的方法都是只运行在
 *                  与其绑定的work_service(单线程)上的, 所以connection_t
 *                  内部不需要加锁.
 *                  外部使用者如需对connection进行操作(如发送数据), 那么
 *                  可以指定conn_id_t然后通过public static方法进行异步执
 *                  行, 可见public static方法均是提供给外部使用的.
 *  @last changed
 *
 */

#include <errno.h>
#include <string>

#include <list>

#include "utility_inc.h"
#include "task_service_inc.h"
#include "log_inc.h"
#include "buffer_list.h"
#include "network_tool.h"

namespace chaos
{

namespace network
{

using namespace std;

using namespace chaos::utility;
using namespace chaos::task_service;
using namespace chaos::log;

class work_service_t;

typedef std::string                  packet_wrapper_t;

struct conn_id_t
{
    friend class connection_t;
    friend class active_connection_t;

    conn_id_t()
        :
            socket(0),
            service_ptr(NULL)
    {
        memset(&timestamp, 0, sizeof(struct timeval));
    }

    conn_id_t(fd_t socket_, struct timeval& timestamp_, work_service_t* service_ptr_)
        :
            socket(socket_),
            timestamp(timestamp_),
            service_ptr(service_ptr_)
    {
    }

    bool operator==(const conn_id_t& conn_id_) const
    {
        return socket == conn_id_.socket
            && timestamp.tv_sec == conn_id_.timestamp.tv_sec
            && timestamp.tv_usec == conn_id_.timestamp.tv_usec;
    }

    fd_t                    socket;
    struct timeval          timestamp;

    //! yunjie: 外部使用者无法获得work_service
private:
    work_service_t*         service_ptr;
};

enum conn_status_e
{
    ST_UNINIT = 0,
    ST_INITED,
    ST_ESTABLISHED,
    ST_CLOSED,
    ST_UNKNOWN
};

enum conn_type_e
{
    T_ACTIVE = 0,
    T_PASSIVE,
    T_UNKNOWN
};

enum conn_event_e
{
    EV_ACCEPTED_COMPLETE = 0,
    EV_CONNECT_SUCCESS,
    EV_PASSIVE_CLOSED,
    EV_ACTIVE_CLOSED,
    EV_TIMEOUT_CLOSED,
    EV_ERROR_OCCURRED,
    EV_DECONSTRUCT,
    EV_UNKNOWN
};


class connection_t
{
public:
    typedef connection_t*                           inner_conn_ptr_t;
    typedef                                     void (*on_conn_event_t)(conn_event_e conn_event_, conn_status_e conn_status_, conn_id_t conn_id_);

    //! ------------------------------------ static function begin ------------------------------------   

public:
    //! yunjie: 当socket状态变化时调用
    static void on_peer_event(fd_t fd_, int event_type_, void* arg_);

    static int async_close(const struct conn_id_t& conn_id_, bool is_del_from_hb_ = true, conn_event_e close_type_ = EV_ACTIVE_CLOSED);

    static int async_send(const struct conn_id_t& conn_id_, const packet_wrapper_t& msg_);
    static int async_send(const struct conn_id_t& conn_id_, const char* msg_, uint32_t size_);



protected:
    static int sync_close_i(const struct conn_id_t& conn_id_, bool is_del_from_hb_, conn_event_e close_type_);

    //! yunjie: 由于async_method目前还不支持重载, 所以要不同函数名
    static int sync_send_packet_wrapper_i(
                            const struct conn_id_t& conn_id_,
                            const packet_wrapper_t& msg_ 
                          );
    static int sync_send_data_i(
                            const struct conn_id_t& conn_id_,
                            const char* msg_,
                            uint32_t size_
                          );

    //! ------------------------------------ static function end ------------------------------------   



    //! ------------------------------------ member function begin ------------------------------------   

public:
    connection_t();
    virtual ~connection_t();

    virtual void initialize(fd_t socket_, struct timeval timestamp_, work_service_t* work_service_, conn_type_e conn_type_, on_conn_event_t event_func_, bool enable_hb_ = false);

    conn_status_e get_status() const
    {
        return m_conn_status;
    }

    fd_t native_socket() const
    {
        return m_socket;
    }

    const struct conn_id_t& get_conn_id() const
    {
        return m_conn_id;
    }

    const struct timeval& get_timestamp() const
    {
        return m_timestamp;
    }

    work_service_t* get_service_ptr() const
    {
        return m_service_ptr;
    }

    bool is_enable_hb() const
    {
        return m_enable_hb;
    }

protected:
    virtual void on_read_complete(buffer_list_t& buffer_) {}
    virtual void on_write_complete(uint32_t transferred_size_) {}

protected:
    //! yunjie: 当epoll有读事件时回调
    int on_recv_data();

    //! yunjie: 当epoll有写事件时回调
    int on_send_data();

    //! yunjie: 当connection的socket fd在epoll处理时发生error时回调
    int on_error_occur();

    int start_drive_send_i();

    int close_i();

    //! ------------------------------------ member function end ------------------------------------   

protected:
    fd_t                                            m_socket;
    struct timeval                                  m_timestamp;
    work_service_t*                                 m_service_ptr;
    conn_id_t                                       m_conn_id;

    conn_type_e                                     m_conn_type;
    conn_status_e                                   m_conn_status;

    //! yunjie: 连接发生变化时调用
    on_conn_event_t                                 m_conn_event_callback;

    buffer_list_t                                   m_read_buffer;
    buffer_list_t                                   m_send_buffer;
    bool                                            m_sending_flag;
    bool                                            m_enable_hb;
};

typedef connection_t::inner_conn_ptr_t              conn_ptr_t;

}

}


#endif //! _CHAOS_CONNECTION_H_
