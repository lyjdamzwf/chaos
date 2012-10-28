/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TASK_SERVICE_H_
#define _CHAOS_TASK_SERVICE_H_

/*!
 *  @file           task_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.24
 *  @brief          task service
 *  @last changed
 *
 */

#include <sys/types.h>
#include <sys/socket.h>

#include <exception>

#include <chaos/utility/utility_inc.h>
#include <chaos/async_method/async_method_inc.h>
#include <chaos/thread/thread_inc.h>
#include <chaos/log/log_inc.h>

#include <chaos/task_service/timer_manager.h>
#include <chaos/task_service/task_queue.h>
#include <chaos/task_service/io_multiplex_handler.h>

#define PTHREAD_COND_VAR    1
#define SLEEP               2
#define PIPE                3
#define SOCKET_PAIR         4
#define EVENTFD             5

#define COMMUNICATION_MODE  3

//! yunjie: 根据内核版本选择最优化IPC方式
#ifdef HAVE_CONFIG_H
#include <chaos/conf.h>
#undef COMMUNICATION_MODE
#if (KER_V1 > 2) || (KER_V1 == 2 && KER_V2 > 6) || (KER_V1 == 2  && KER_V2 == 6 && KER_V3 >= 27)
#define COMMUNICATION_MODE  5
#else
#define COMMUNICATION_MODE  3
#endif
#endif

#if COMMUNICATION_MODE == EVENTFD
#include <sys/eventfd.h>
#endif

namespace chaos
{

namespace task_service
{

using namespace chaos::utility;
using namespace chaos::async_method;
using namespace chaos::thread;
using namespace chaos::log;

#ifndef DEFAULT_TASK_SERVICE_THREAD_NUM
#define DEFAULT_TASK_SERVICE_THREAD_NUM     1
#endif

#ifndef ALL_THREAD_MASK
#define ALL_THREAD_MASK                     0xffffffff
#endif

#ifndef MIN_TASK_FETCH_NUM
#define MIN_TASK_FETCH_NUM                  32
#endif

#ifndef MAX_TASK_FETCH_NUM
#define MAX_TASK_FETCH_NUM                  65535
#endif

#ifndef TIMEDOUT_US
#define TIMEDOUT_US                         50000   //! yunjie: 50毫秒
#endif

#ifndef DEFAULT_SERVICE_NAME
#define DEFAULT_SERVICE_NAME                "default_service_name"
#endif

class post_failed_exception_t : public std::exception
{
public:
    post_failed_exception_t()
        :
            m_what("task_service_t post failed exception occurred")
    {
    }

    post_failed_exception_t(const char* what_)
        :
            m_what(what_)
    {
    }

    virtual ~post_failed_exception_t() throw() {}

    const char *what() const throw()
    {
        return m_what.c_str();
    }

private:
    string                          m_what;
};

class task_service_t : private noncopyable_t
{
public:
    task_service_t(const string& service_name_ = DEFAULT_SERVICE_NAME);
    virtual ~task_service_t();

    struct start_thread_t : public thread_group_t::callback_t
    {
        start_thread_t(task_service_t& task_service_)
            : m_task_service(task_service_)
        {
        }

        virtual void exec(thread_t* thd_)
        {
            if (NULL != thd_)
            {
                async_method_t thread_method = bindfunc(&m_task_service, &task_service_t::exec_task, thd_);
                thd_->start(thread_method);
            }
        }

        task_service_t&                  m_task_service;
    };

    struct send_cond_signal_t : public thread_group_t::callback_t
    {
        send_cond_signal_t(pthread_t pid_ = ALL_THREAD_MASK)
            : pid(pid_)
        {
        }

        virtual void exec(thread_t* thd_)
        {
            if (NULL != thd_)
            {
                LOGTRACE(("task_service_t", "send_cond_signal_t::exec() begin"));

                if (ALL_THREAD_MASK == pid || thd_->get_thread_id() == pid)
                {
                    thd_->cond_signal();
                }

                LOGTRACE(("task_service_t", "send_cond_signal_t::exec() end"));
            }
        }

        pthread_t   pid;
    };

public:
    virtual int start(int32_t thread_num_ = DEFAULT_TASK_SERVICE_THREAD_NUM);
    virtual int stop();
    int post_async_stop_signal();
    int clear_all_task();

    //! yunjie:
    //! ext_data_ -使用者可以借助ext_data来改变投递规则
    //! is_allow_exec_local_ - 如果当前线程属于task_service的线程组, 就立即执行
    virtual int post(
                        async_method_t          async_method_,
                        void*                   ext_data_               = NULL,
                        task_prior_e            prior_                  = TASK_PRIOR_NORMAL,
                        bool                    is_allow_exec_local_    = true
                    );

    void register_timer(
                        uint32_t                        interval_,
                        const time_event_callback_t&    callback_,
                        bool                            persist_    = false,
                        time_t                          start_time_ = 0
                       );

    void register_io_event(
                            fd_t                    fd_,
                            int                     event_type_flag_,
                            callback_on_event_t     callback_       = NULL,
                            void*                   cb_arg_         = NULL,
                            bool                    is_persist_     = false
                         );

    bool is_run_on_service();

    void remove_fd_from_epoll(fd_t fd_);

    bool is_recv_stop_signal() const
    {
        return m_stop_signal;
    }

    const char* get_name() const { return m_service_name.c_str(); }

    //! yunjie: 非线程安全
    timeval get_cached_time()
    {
        return m_timer_manager.get_cached_time();
    }

protected:
    virtual void exec_task(thread_t* thd_);
    void set_stop_signal(bool signal_);

protected:
    bool                                    m_started;
    string                                  m_service_name;
    volatile bool                           m_stop_signal;      //! yunjie: true - 已发送停止信号, false - 初始/运行 状态
    int32_t                                 m_thread_num;
    thread_group_t                          m_thread_group;
    task_queue_t                            m_task_queue;
    atomic_val_t<uint32_t>                  m_fetch_num_per_loop;
    timer_manager_t                         m_timer_manager;
    io_multiplex_handler_t                  m_io_handler;

#if COMMUNICATION_MODE == PIPE || COMMUNICATION_MODE == SOCKET_PAIR || COMMUNICATION_MODE == EVENTFD
    //! yunjie: 用于IPC通信的fd
    int                                     m_comm_fds[2];
#endif

};

}

}

#endif //! _CHAOS_TASK_SERVICE_H_
