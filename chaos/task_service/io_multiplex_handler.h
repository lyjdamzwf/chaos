/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_IO_MULTIPLEX_HANDLER_H_
#define _CHAOS_IO_MULTIPLEX_HANDLER_H_

/*! 
 *  @file           io_multiplex_handler.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.9
 *  @brief          io multiplex handler
 *  @last changed
 *
 */

#include <sys/epoll.h>

#include <vector>
#include <set>

#include <chaos/utility/utility_inc.h>
#include <chaos/thread/thread_inc.h>

#include <chaos/task_service/task_service_define.h>

namespace chaos
{

namespace task_service
{

using namespace std;
using namespace chaos::utility;
using namespace chaos::thread;

#define EPOLL_EVENT_WAIT_NUM_ORI    32
#define EPOLL_EVENT_WAIT_NUM_MAX    4096

#define IO_EVENT_NUM_ORI            65535

#define READ_EVENT_FLAG             0x01
#define WRITE_EVENT_FLAG            0x02
#define ERROR_EVENT_FLAG            0x04
#define ALL_EVENT_FLAG              0x07

#define EPOLL_TIMEOUT               100

typedef     uint32_t                             fd_t;
typedef     void (*callback_on_event_t) (fd_t, int, void*);

enum event_type_e
{
    IO_READ_EVENT = 0xc8,      //! dec:200
    IO_WRITE_EVENT,
    IO_ERROR_EVENT
};

//! yunjie: 64位环境按8字节对齐, 65535个io_event_t约2MB
struct io_event_t
{
    io_event_t()
        :
            listen_fd(0),
            read_cb(NULL),
            read_cb_arg(NULL),
            read_persist(false),
            write_cb(NULL),
            write_cb_arg(NULL),
            write_persist(false),
            error_cb(NULL),
            error_cb_arg(NULL)
    {
    }

    io_event_t(
                fd_t                    fd_,
                callback_on_event_t     read_cb_,
                void*                   read_cb_arg_,
                bool                    read_persist_,
                callback_on_event_t     write_cb_,
                void*                   write_cb_arg_,
                bool                    write_persist_,
                callback_on_event_t     error_cb_,
                void*                   error_cb_arg_
                )
        :
            listen_fd(fd_),
            read_cb(read_cb_),
            read_cb_arg(read_cb_arg_),
            read_persist(read_persist_),
            write_cb(write_cb_),
            write_cb_arg(write_cb_arg_),
            write_persist(write_persist_),
            error_cb(error_cb_),
            error_cb_arg(error_cb_arg_)
    {
    }

    void clear()
    {
        listen_fd = 0;
        read_cb = NULL;
        read_cb_arg = NULL;
        read_persist = false;
        write_cb = NULL;
        write_cb_arg = NULL;
        write_persist = false;
        error_cb = NULL;
        error_cb_arg = NULL;
    }

    fd_t                        listen_fd;
    callback_on_event_t         read_cb;
    void*                       read_cb_arg;
    bool                        read_persist;        //! yunjie: 读事件是否持久
    callback_on_event_t         write_cb;
    void*                       write_cb_arg;
    bool                        write_persist;       //! yunjie: 写事件是否持久
    callback_on_event_t         error_cb;
    void*                       error_cb_arg;
};

class io_multiplex_handler_t : public noncopyable_t
{
public:
    io_multiplex_handler_t();
    virtual ~io_multiplex_handler_t();

    int initialize(bool lock_ = false);
    int wait_io_notification();

    int register_io_event(
                            fd_t                    fd_,
                            int                     event_type_flag_,
                            callback_on_event_t     event_cb_,
                            void*                   cb_arg_             = NULL,
                            bool                    is_persist_         = false
                         );

    int remove_fd_from_epoll(fd_t fd_);

    uint32_t fd_count() const
    {
        CHECK_LOCK(m_is_lock, m_mutex);
        uint32_t size = m_fd_set.size();

        return size;
    }

private:
    /** yunjie: 私有方法都不会涉及到锁竞争 */

    int register_io_event_i(
                            fd_t                    fd_,
                            int                     event_type_flag_,
                            callback_on_event_t     event_cb_,
                            void*                   cb_arg_             = NULL,
                            bool                    is_persist_         = false
                           );
    int remove_fd_from_epoll_i(fd_t fd_);

private:
    bool                                    m_inited;
    bool                                    m_is_lock;
    mutable mutex_t                         m_mutex;        //! yunjie: 单线程的task_service不需要使用此mutex
    fd_t                                    m_epoll_fd;
    vector<epoll_event>                     m_epoll_events; //! yunjie: 用于epoll_wait的参数
    vector<io_event_t>                      m_io_events;    //! yunjie: 根据fd可以在此vector中索引到对应的io_event(这招抄袭了libevent ^_^)
    set<fd_t>                               m_fd_set;       //! yunjie: 用于判断是否有正在监听的fd
};

}

}

#endif //! _CHAOS_IO_MULTIPLEX_HANDLER_H_
