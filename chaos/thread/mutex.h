/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_MUTEX_H_
#define _CHAOS_MUTEX_H_

/*! 
 *  @file           mutex.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.19
 *  @brief          mutex
 *  @last changed
 *
 */

#include <pthread.h>

#include "noncopyable.h"

namespace chaos
{

namespace thread
{

using namespace chaos::utility;

class mutex_t : private noncopyable_t
{
public:
    mutex_t(int kind_ = PTHREAD_MUTEX_FAST_NP)
    {
        pthread_mutexattr_t attr;
        ::pthread_mutexattr_init(&attr);
        ::pthread_mutexattr_settype(&attr, kind_);
        ::pthread_mutex_init(&m_mutex, &attr);
    }

    ~mutex_t()
    {
        ::pthread_mutex_destroy(&m_mutex);
    }

    inline void lock()
    {
        ::pthread_mutex_lock(&m_mutex);
    }

    inline void unlock()
    {
        ::pthread_mutex_unlock(&m_mutex);
    }

    pthread_mutex_t * get_mutex()
    {
        return &m_mutex;
    }

private:
    pthread_mutex_t                 m_mutex;
};

class scope_mutex_lock_t : private noncopyable_t
{
public:

    scope_mutex_lock_t(mutex_t &m_) : m_lock(m_)
    {
        m_lock.lock();
    }

    ~scope_mutex_lock_t()
    {
        m_lock.unlock();
    }

private:
    mutex_t&                        m_lock;
};

class scope_mutex_holder_t : private noncopyable_t
{
public:
    scope_mutex_holder_t()
        :
            m_lock_ptr(NULL)
    {
    }

    ~scope_mutex_holder_t()
    {
        if (NULL != m_lock_ptr)
        {
            m_lock_ptr->unlock();
        }
    }

    void set_ptr_and_lock(mutex_t* ptr_)
    {
        if (NULL == ptr_)
        {
            return;
        }

        if (NULL != m_lock_ptr)
        {
            m_lock_ptr->unlock();
        }

        m_lock_ptr = ptr_;
        m_lock_ptr->lock();
    }

    void reset_and_unlock()
    {
        if (NULL == m_lock_ptr)
        {
            return;
        }

        m_lock_ptr->unlock();
        m_lock_ptr = NULL;
    }

    bool is_lock() const
    {
        return (NULL != m_lock_ptr);
    }

private:
    mutex_t*                        m_lock_ptr;

};

}

}

#endif //! _CHAOS_MUTEX_H_

