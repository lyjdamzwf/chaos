/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include <errno.h>

#include <chaos/task_service/io_multiplex_handler.h>

/*!
 *  @file           io_multiplex_handler.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.9
 *  @brief          io multiplex handler
 *  @last changed
 *
 */

namespace chaos
{

namespace task_service
{

io_multiplex_handler_t::io_multiplex_handler_t()
    :
        m_inited(false),
        m_is_lock(false),
        m_epoll_fd(0)
{
}

io_multiplex_handler_t::~io_multiplex_handler_t()
{
}

int io_multiplex_handler_t::initialize(bool lock_)
{
    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::initialize arg-[lock:%d] begin.", lock_));

    if (m_inited)
    {
        LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::initialize io multiplex handler has inited, return."));
        return -1;
    }

    m_is_lock = lock_;

    //! yunjie: 32000参数对linux 2.6 内核之后的版本已经无效.
    if ((int)(m_epoll_fd = ::epoll_create(32000)) == -1)
    {
        LOGERROR((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::initialize epoll_create failed, errno:[%m] return.", errno));

        return -1;
    }

    m_epoll_events.resize(EPOLL_EVENT_WAIT_NUM_ORI);
    if (EPOLL_EVENT_WAIT_NUM_ORI != m_epoll_events.size())
    {
        LOGERROR((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::initialize m_epoll_events resize to %lu, failed, return.", EPOLL_EVENT_WAIT_NUM_ORI));
        return -1;
    }

    m_io_events.resize(IO_EVENT_NUM_ORI);
    if (IO_EVENT_NUM_ORI != m_io_events.size())
    {
        LOGERROR((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::initialize m_io_events resize to %lu failed, return.", IO_EVENT_NUM_ORI));
        return -1;
    }

    m_inited = true;

    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::initialize arg-[lock:%d] end.", lock_));
    return 0;
}

int io_multiplex_handler_t::wait_io_notification()
{
    //! LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification begin."));

    CHECK_LOCK(m_is_lock, m_mutex);

    if (0 == m_fd_set.size())   //! yunjie: 避免没有监听的fd也要system call陷入内核
    {
        return 0;
    }

    int res = ::epoll_wait(
                            m_epoll_fd,
                            &m_epoll_events[0],
                            m_epoll_events.size(),
                            EPOLL_TIMEOUT
                          );

    //! yunjie: epoll_wait 非正常返回值处理.
    if (res == -1)
    {
        LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification epoll_wait failed, res:[%d]", res));
        return (0);
    }

    for (int i = 0; i < res; i++)
    {
        int what = m_epoll_events[i].events;                        //! yunjie: 当前循环epoll事件类型
        fd_t fd = m_epoll_events[i].data.fd;                        //! yunjie: 当前循环epoll需要处理的fd

        if (fd < 0 || fd >= m_io_events.size())                     //! yunjie: 非正常边界
        {
            LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification invaild file descriptor fd:[%d]", fd));
            continue;
        }

        struct io_event_t& io_event = m_io_events[fd];          //! yunjie: 通过索引的方式取得该fd所对应的io_event_t对象

        struct epoll_event epev = {0, {0}};
        epev.data.fd = io_event.listen_fd;

        /* yunjie: EPOLLPRI - 表示对应的文件描述符有紧急的数据可读(这里应该表示有带外数据到来).
         *         EPOLLERR - 表示对应的文件描述符发生错误.
         *         EPOLLHUP - 表示对应的文件描述符被挂断.
         */
        if (what & (EPOLLHUP|EPOLLERR))                         //! yunjie: 对于该fd的错误现象进行处理, 进行回调.
        {
            //! yunjie: 从epoll中删除关联的socket
            /** yunjie: 删除操作交给使用者去决定
            if (remove_fd_from_epoll_i(io_event.listen_fd) == -1)
            {
                LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification remove_fd_from_epoll_i failed fd:%d.", io_event.listen_fd));
                continue;
            }
            */

            if (NULL != io_event.error_cb)
            {
                io_event.error_cb(fd, IO_ERROR_EVENT, io_event.error_cb_arg);
            }
        }
        else
        {
            int epoll_operate = 0;
            if (what & EPOLLIN)                                 //! yunjie: 读事件
            {
                if (NULL != io_event.read_cb)
                {
                    io_event.read_cb(fd, IO_READ_EVENT, io_event.read_cb_arg);       //! yunjie: 调用读回调
                }

                //! yunjie: 如果读事件不是persist的, 需要进行epoll信息的修改
                //! yunjie: 注意, 此时的io_event有可能已经被callback clear, 所以要来判断fd是否不为0
                if (io_event.listen_fd && !io_event.read_persist)
                {
                    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification read event is not persist, remove it from epoll."));

                    //! yunjie: 如果有注册写事件, 那么不能直接删除epoll和socket的关联, 需要修改epoll信息, 否则就直接从epoll中删除socket的关联
                    if (NULL != io_event.write_cb)
                    {
                        epoll_operate = EPOLL_CTL_MOD;
                        epev.events = EPOLLOUT;

                        if (::epoll_ctl(m_epoll_fd, epoll_operate, io_event.listen_fd, &epev) == -1)
                        {
                            LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification system call epoll_ctl failed fd:%d.", io_event.listen_fd));
                            continue;
                        }
                    }
                    else
                    {
                        if (remove_fd_from_epoll_i(io_event.listen_fd) == -1)
                        {
                            LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification remove_fd_from_epoll_i failed fd:%d.", io_event.listen_fd));
                            continue;
                        }
                    }

                    io_event.read_cb = NULL;
                    io_event.read_cb_arg = NULL;
                    io_event.read_persist = false;
                }
            }

            if (what & EPOLLOUT)                                //! yunjie: 写事件
            {
                if (NULL != io_event.write_cb)
                {
                    io_event.write_cb(fd, IO_WRITE_EVENT, io_event.write_cb_arg);     //! yunjie: 调用写回调
                }

                //! yunjie: 如果写事件不是persist的, 需要进行epoll信息的修改
                //! yunjie: 注意, 此时的io_event有可能已经被callback clear, 所以要来判断fd是否不为0
                if (io_event.listen_fd && !io_event.write_persist)
                {
                    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification write event is not persist, remove it from epoll."));

                    //! yunjie: 如果有注册读事件, 那么不能直接删除epoll和socket的关联, 需要修改epoll信息, 否则就直接从epoll中删除socket的关联
                    if (NULL != io_event.read_cb)
                    {
                        epoll_operate = EPOLL_CTL_MOD;
                        epev.events = EPOLLIN;

                        if (::epoll_ctl(m_epoll_fd, epoll_operate, io_event.listen_fd, &epev) == -1)
                        {
                            LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification system call epoll_ctl failed fd:%d.", io_event.listen_fd));
                            continue;
                        }
                    }
                    else
                    {
                        if (remove_fd_from_epoll_i(io_event.listen_fd) == -1)
                        {
                            LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification remove_fd_from_epoll_i failed fd:%d.", io_event.listen_fd));
                            continue;
                        }
                    }

                    io_event.write_cb = NULL;
                    io_event.write_cb_arg = NULL;
                    io_event.write_persist = false;
                }
            }
        }
    }

    //! yunjie: 对m_epoll_events进行扩张, 这样的话可以尽可能通过一次epoll_wait我们能获得更多的fd, 减少内核线程的切换, 提高性能.
    int epoll_events_size = m_epoll_events.size();
    if (res == epoll_events_size && epoll_events_size < EPOLL_EVENT_WAIT_NUM_MAX)
    {
        uint32_t new_size = epoll_events_size << 1;
        m_epoll_events.resize(new_size);      //! yunjie: 成倍扩张, 由于初始值对齐到8(32), 所以最终极限扩张值必定是EPOLL_EVENT_WAIT_NUM_MAX(4096)
        LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_io_notification m_epoll_events resize to %lu.", new_size));
    }

    //! LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::wait_notification end"));
    return res;
}

int io_multiplex_handler_t::register_io_event(
                                                fd_t                    fd_,
                                                int                     event_type_flag_,
                                                callback_on_event_t     event_cb_,
                                                void*                   cb_arg_,
                                                bool                    is_persist_
                                             )
{
    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event arg-[fd:%lu] begin", fd_));

    CHECK_LOCK(m_is_lock, m_mutex);

    int ret = register_io_event_i(fd_, event_type_flag_, event_cb_, cb_arg_, is_persist_);

    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event end"));
    return ret;
}


int io_multiplex_handler_t::remove_fd_from_epoll(fd_t fd_)
{
    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::remove_fd_from_epoll begin"));

    CHECK_LOCK(m_is_lock, m_mutex);

    int ret = remove_fd_from_epoll_i(fd_);

    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::remove_fd_from_epoll end"));
    return ret;
}


int io_multiplex_handler_t::register_io_event_i(
                                                fd_t                    fd_,
                                                int                     event_type_flag_,
                                                callback_on_event_t     event_cb_,
                                                void*                   cb_arg_,
                                                bool                    is_persist_
                                               )
{
    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event_i args-[fd:%lu, event_flag:%lu] begin", fd_, event_type_flag_));

    if (NULL == event_cb_)
    {
        LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event_i event_cb_ equals NULL"));
        //! return -1;
    }

    //! yunjie: 判断是否要扩张m_io_event容器
    if (fd_ >= m_io_events.size())
    {
        m_io_events.resize(fd_);
        if (m_io_events.size() != fd_)
        {
            LOGERROR((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event_i m_io_events resize to %lu failed, return.", fd_));
            /**
            if (-1 == remove_fd_from_epoll_i(fd_))    //! yunjie: 删除之前添加到epoll的监听事件
            {
                LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event_i remove_fd_from_epoll_i failed, socket:[%d].", fd_));
                return -1;
            }
            */

            return -1;
        }
    }

    int epoll_ctl_op = EPOLL_CTL_ADD;
    struct io_event_t& old_event = m_io_events[fd_];
    old_event.listen_fd = fd_;
    int events = 0;

    //! yunjie: 注册新的读事件
    if (event_type_flag_ & READ_EVENT_FLAG)
    {
        events |= EPOLLIN;
        if (NULL != old_event.read_cb)            //! yunjie: 之前是否已经注册过, 如果是就必须使用EPOLL_CTL_MOD标志
        {
            epoll_ctl_op = EPOLL_CTL_MOD;
        }

        //! yunjie: 如果原来有注册过的写事件, 那么也要重新注册
        if (NULL != old_event.write_cb)
        {
            epoll_ctl_op = EPOLL_CTL_MOD;
            events |= EPOLLOUT;
        }
    }

    //! yunjie: 注册新的写事件
    if (event_type_flag_ & WRITE_EVENT_FLAG)
    {
        events |= EPOLLOUT;
        if (NULL != old_event.write_cb)            //! yunjie: 之前是否已经注册过, 如果是就必须使用EPOLL_CTL_MOD标志
        {
            epoll_ctl_op = EPOLL_CTL_MOD;
        }

        //! yunjie: 如果原来有注册过的读事件, 那么也要重新注册
        if (NULL != old_event.read_cb)
        {
            epoll_ctl_op = EPOLL_CTL_MOD;
            events |= EPOLLIN;
        }
    }

    //! yunjie: 调用epoll_ctl添加fd监听
    struct epoll_event epev = {0, {0}};
    epev.data.fd = fd_;         //! yunjie: user data域
    epev.events = events;

    //! yunjie: EPOLL_CTL_ADD操作具有"覆盖替代性", 如果是ERROR事件仍调用epoll_ctl，将会将原来注册的取消, 导致不正常行为
    if (event_type_flag_ & READ_EVENT_FLAG || event_type_flag_ & WRITE_EVENT_FLAG)
    {
        if (::epoll_ctl(m_epoll_fd, epoll_ctl_op, fd_, &epev) == -1)
        {
            LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event_i system call epoll_ctl failed. args-[ADD:%d, MOD:%d, DEL:%d, cur_op:%d, EPOLLOUT:%d, EPOLLIN:%d, cur_event:%d]",
                        EPOLL_CTL_ADD,
                        EPOLL_CTL_MOD,
                        EPOLL_CTL_DEL,
                        epoll_ctl_op,
                        EPOLLOUT,
                        EPOLLIN,
                        events
                    ));
            return -1;
        }
    }

    //! yunjie: 给对应的io_event_t的读事件赋值
    if (event_type_flag_ & READ_EVENT_FLAG)
    {
        old_event.read_cb = event_cb_;
        old_event.read_cb_arg = cb_arg_;
        old_event.read_persist = is_persist_;
    }

    //! yunjie: 给对应的io_event_t的写事件赋值
    if (event_type_flag_ & WRITE_EVENT_FLAG)
    {
        old_event.write_cb = event_cb_;
        old_event.write_cb_arg = cb_arg_;
        old_event.write_persist = is_persist_;
    }

    //! yunjie: 给对应的io_event_t的错误处理事件赋值
    if (event_type_flag_ & ERROR_EVENT_FLAG)
    {
        old_event.error_cb = event_cb_;
        old_event.error_cb_arg = cb_arg_;
    }

    //! yunjie: 添加已成功监听fd到m_fd_set
    m_fd_set.insert(fd_);

    LOGTRACE((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::register_io_event_i end."));
    return 0;
}

int io_multiplex_handler_t::remove_fd_from_epoll_i(fd_t fd_)
{
    if (-1 == ::epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd_, NULL))    //! yunjie: 删除之前添加到epoll的监听事件, 这里的epoll_event参数可以忽略
    {
        LOGWARN((IO_MULTIPLEX_MODULE, "io_multiplex_handler_t::remove_fd_from_epoll_i remove fd from epoll failed socket:[%d] errno:[%m].", fd_, errno));
        return -1;
    }

    struct io_event_t& old_event = m_io_events[fd_];
    old_event.clear();

    m_fd_set.erase(fd_);

    return 0;
}

}

}
