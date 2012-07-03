/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_THREAD_H_
#define _CHAOS_THREAD_H_

/*! 
 *  @file           thread.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.18
 *  @brief          thread
 *  @last changed
 *
 */

#include <string>
#include <vector>

#include "utility_inc.h"
#include "async_method_inc.h"
#include "log_inc.h"

#include "mutex.h"
#include "condition.h"
#include "rwlock.h"

namespace chaos
{

namespace thread
{

using namespace std;
using namespace chaos::utility;
using namespace chaos::async_method;
using namespace chaos::log;

//! yunjie: 线程类封装
class thread_t: private noncopyable_t
{
public:
    typedef             void* (*thread_func_t) (void*);

public:
    thread_t(const string& name_ = string("thread_t"), bool joinable_ = true)
        : m_name(name_), 
          m_joinable(joinable_),
          m_thread(0), 
          m_alive(false), 
          m_complete(false)
{
}

    virtual ~thread_t() 
    {
        m_thread_func.release();
    }

    /* 获取当前线程编号 */
    static pthread_t get_current_thread_id() { return ::pthread_self(); }

    /* 使线程睡眠指定时间(秒) */
    static void sleep(const long sec_) { ::sleep(sec_); }

    /* 使线程睡眠指定时间(毫秒) */
    static void msleep(const long msec_) { ::usleep(1000 * msec_); }

    /* 使线程睡眠指定时间(微妙) */
    static void usleep(const long usec_) { ::usleep(usec_); }

    /* 检查线程是否在运行状态 */
    const bool is_alive() const { return m_alive; }

    /* 检查线程是否是joinable的 */
    const bool is_joinable() const { return m_joinable; }
    const bool is_final() { return m_complete; }
    void final() { m_complete = true; }

    void join();
    bool start(async_method_t func_);

    void cond_wait();
    void cond_wait(struct timeval& now_, uint64_t timeout_second_, uint64_t timeout_microsecond_);
    void cond_signal();


    static void *thread_func(void *arg);

    bool operator == (const thread_t* other_) const
    {
        return pthread_equal(m_thread, other_->m_thread) != 0;
    }

    bool operator != (const thread_t *other_) const
    {
        return !operator==(other_);
    }

    const std::string& get_thread_name() const { return m_name; }

    const pthread_t& get_thread_id() const { return m_thread; }

private:
    string                          m_name;		    /* 线程名称 */
    mutex_t                         m_lock;			/* 互斥锁   */
    condition_t                     m_cond;			/* 条件变量 */

    bool                            m_joinable;	    /* 线程Joinable属性 */
    pthread_t                       m_thread;		/* 线程编号 */

    volatile bool                   m_alive;		/* 线程是否在运行 */
    volatile bool                   m_complete;		/* 线程是否将结束 */

    async_method_t                  m_thread_func;
};

}

}

#endif /*_CHAOS_THREAD_H_ */
