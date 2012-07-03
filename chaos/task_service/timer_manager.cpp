/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include "timer_manager.h"

/*! 
 *  @file           timer_manager.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.31
 *  @brief          timer manager
 *  @last changed
 *
 */

namespace chaos
{

namespace task_service
{

static bool time_event_fetch_condition(time_event_t* const & event_, void* ext_data_)
{
    if (NULL == ext_data_)
    {
        return false;
    }

    time_t now = *(time_t*)ext_data_;
    if (now < event_->timestamp)
    {
        return false;
    }

    return true;
}

timer_manager_t::timer_manager_t()
    :
        m_inited(false),
        m_is_lock(false)
{
    memset((void*)&m_cached_time, 0, sizeof(struct timeval));
}

timer_manager_t::~timer_manager_t()
{
}

int timer_manager_t::initialize(bool lock_)
{
    if (m_inited)
    {
        LOGWARN((TIMER_MANAGER_MODULE, "timer_manager_t::initialize timer manager has inited, return."));
        return -1;
    }

    //! yunjie: 这个标志是控制timer_manager_t内的mutex, 而非m_time_heap, 两者保护的资源不同
    m_is_lock = lock_;

    //! yunjie: 初始化时间堆, 参数false表示堆的任何操作都不加锁, 因此是m_time_heap线程不安全的, 线程安全性全部由timer_manager来控制
    m_time_heap.initialize(false);

    m_inited = true;

    return 0;
}

void timer_manager_t::register_timer(uint32_t                       interval_,
                                     const time_event_callback_t&   callback_,
                                     bool                           persist_,
                                     time_t                         start_time_
                                    )
{
    CHECK_LOCK(m_is_lock, m_mutex);

    time_t local_start_time = start_time_;

    if (!local_start_time)
    {
        local_start_time = get_cached_time_i().tv_sec;
    }

    time_event_t* time_event = new time_event_t(
                                                        local_start_time,
                                                        interval_,
                                                        0,
                                                        local_start_time + interval_,
                                                        callback_,
                                                        persist_
                                                    );
    if (NULL == time_event)
    {
        LOGWARN((TIMER_MANAGER_MODULE, "timer_manager_t::register_timer new time_event_t failed"));
        return;
    }

    //! yunjie: 这里不需要加锁, m_time_heap被初始化为线程安全的
    register_timer_i(time_event);
}

void timer_manager_t::exec()
{
    CHECK_LOCK(m_is_lock, m_mutex);

    if (!m_inited)
    {
        LOGWARN((TIMER_MANAGER_MODULE, "timer_manager_t::exec timer manager has not been inited."));
        return;
    }

    time_t now = get_cached_time_i().tv_sec;

    timer_container_t::container_t tasks;
    uint32_t all_task_num = 0;

    //! yunjie: 用于在fetch_task过程中检测time event是否满足执行条件
    struct timer_container_t::cond_checker_t checker(time_event_fetch_condition, (void*)&now, FETCH_BREAK);

    //! yunjie: 一次性抓取足够的需要被执行的time事件.
    m_time_heap.fetch_task(tasks, all_task_num, 0xffffffff, &checker);

    while (!tasks.empty())
    {
        struct time_event_t* event = tasks.top();
        event->exec();

        if (event->persist)
        {
            event->last_exec_time = now;
            event->timestamp = now + event->interval;

            //! yunjie: 这时注册的event在该loop中将不会被检测.
            register_timer_i(event);
        }
        else
        {
            //! yunjie: release会对内部的async_method_t进行内存释放, 不是persist事件才能调用
            event->release();
            SAFE_DELETE(event);
        }

        tasks.pop();
    }
}

void timer_manager_t::clear()
{
    CHECK_LOCK(m_is_lock, m_mutex);

    clear_i();
}

void timer_manager_t::flush_time()
{
    CHECK_LOCK(m_is_lock, m_mutex);

    flush_time_i();
}

struct timeval timer_manager_t::get_cached_time()
{
    CHECK_LOCK(m_is_lock, m_mutex);

    struct timeval ret = get_cached_time_i();

    return ret;
}


uint32_t timer_manager_t::size()
{
    CHECK_LOCK(m_is_lock, m_mutex);

    return m_time_heap.size();
}

void timer_manager_t::register_timer_i(time_event_t* event_)
{
    m_time_heap.push(event_);
}

void timer_manager_t::clear_i()
{
    m_time_heap.clear();
}

struct timeval timer_manager_t::get_cached_time_i()
{
    if (!m_cached_time.tv_sec)
    {
        flush_time_i();
    }

    return m_cached_time;
}

void timer_manager_t::flush_time_i()
{
    gettimeofday(&m_cached_time, NULL);
}

}

}

