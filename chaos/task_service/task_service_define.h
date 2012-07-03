/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TASK_SERVICE_DEFINE_H_
#define _CHAOS_TASK_SERVICE_DEFINE_H_

/*! 
 *  @file           task_serviec_define.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.17
 *  @brief          task service define
 *  @last changed
 *
 */

namespace chaos
{

namespace task_service
{

using namespace async_method;

#define CHECK_LOCK(lock_flag, mutex) \
        scope_mutex_holder_t mutex_holder; \
        if (lock_flag) \
        { \
            mutex_holder.set_ptr_and_lock(&mutex); \
        }

enum task_prior_e
{
    TASK_PRIOR_LOW = 0,
    TASK_PRIOR_NORMAL,
    TASK_PRIOR_HIGH,
    TASK_PRIOR_COUNT
}; 

typedef     async_method_t      time_event_callback_t;

}

}


#endif //! _CHAOS_TASK_SERVICE_DEFINE_H_
