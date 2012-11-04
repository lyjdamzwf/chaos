/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TIME_MANAGER_H_
#define _CHAOS_TIME_MANAGER_H_

/*!
 *  @file           time_event.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.29
 *  @brief          time manager
 *  @last changed
 *
 */

#include <sys/time.h>

#include <queue>

#include <chaos/utility/utility_inc.h>
#include <chaos/thread/thread_inc.h>
#include <chaos/async_method/async_method_inc.h>

#include <chaos/task_service/timer_container.h>

namespace chaos
{

namespace task_service
{

using namespace std;
using namespace chaos::utility;
using namespace chaos::thread;
using namespace chaos::async_method;

class timer_manager_t : private noncopyable_t
{
public:
    typedef timer_container_t                          time_heap_t;

public:
    timer_manager_t();
    virtual ~timer_manager_t();

public:
    int initialize(bool lock_ = false);

    void register_timer(
                        uint32_t                        interval_,
                        const time_event_callback_t&    callback_,
                        bool                            persist_ = false,
                        time_t                          start_time_ = 0
                        );

    void exec();

    void clear();

    struct timeval get_cached_time();

    void flush_time();

    uint32_t size();

private:
    /** yunjie: 私有方法都不会涉及到锁竞争 */

    void register_timer_i(const time_event_sptr_t& event_);

    void clear_i();

    struct timeval get_cached_time_i();

    void flush_time_i();

private:
    bool                                            m_inited;
    time_heap_t                                     m_time_heap;
    struct timeval                                  m_cached_time;
    bool                                            m_is_lock;
    mutex_t                                         m_mutex;    //! yunjie: 目前只用来在多线程驱动下的task_service中保护m_cached_time
};

}

}


#endif //! _CHAOS_TIME_MANAGER_H_
