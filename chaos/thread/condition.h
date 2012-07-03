/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_CONDITION_H_
#define _CHAOS_CONDITION_H_

/*! 
 *  @file           condition.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.19
 *  @brief          condition
 *  @last changed
 *
 */

#include <sys/time.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include "noncopyable.h"
#include "mutex.h"

namespace chaos
{

namespace thread
{

class condition_t: private noncopyable_t
{
public:
    condition_t()
    {
        ::pthread_cond_init(&m_cond, NULL);
    }
    ~condition_t()
    {
        ::pthread_cond_destroy(&m_cond);
    }

    void broadcast()
    {
        ::pthread_cond_broadcast(&m_cond);
    }

    void signal()
    {
        ::pthread_cond_signal(&m_cond);
    }

    void wait(mutex_t& mutex_)
    {
        ::pthread_cond_wait(&m_cond, mutex_.get_mutex());
    }

    void wait(mutex_t& mutex_, const struct timeval& now_, uint64_t timeout_second_, uint64_t timeout_microsecond_)
    {
        struct timespec timeout;
        memset(&timeout, 0, sizeof(struct timespec));

        uint64_t ns_sum = (timeout_microsecond_ + now_.tv_usec) * 1000;
        if (ns_sum >= 1000000000)
        {
            timeout.tv_sec = (now_.tv_sec + timeout_second_ + 1);
            timeout.tv_nsec = ns_sum - 1000000000;
        }
        else
        {
            timeout.tv_sec = (now_.tv_sec + timeout_second_);
            timeout.tv_nsec = ns_sum;
        }

        ::pthread_cond_timedwait(&m_cond, mutex_.get_mutex(), &timeout);
    }

private:

    pthread_cond_t m_cond;	// 系统条件变量
};

}

}

#endif //! _CHAOS_CONDITION_H_
