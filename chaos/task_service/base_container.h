/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_BASE_CONTAINER_H_
#define _CHAOS_BASE_CONTAINER_H_

/*! 
 *  @file           base_container.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.2
 *  @brief          base container
 *  @last changed
 *
 */

#include "thread_inc.h"
#include "task_service_define.h"

namespace chaos
{

namespace task_service
{

using namespace chaos::thread;

enum cond_failed_e
{
    FETCH_BREAK = 0,
    FETCH_RETURN,
    FETCH_CONTINUE
};

//! yunjie: CONTAINER模板参数是嵌套模板参数, 用class声明
template<typename ELEMENT, template<typename T> class CONTAINER >
class base_container_t
{
public:
    typedef         CONTAINER<ELEMENT>              container_t;
    typedef         bool (*fetch_condition_t) (const ELEMENT&, void* ext_data_);

    struct cond_checker_t
    {
        cond_checker_t()
            :
                cond_func(NULL),
                ext_data(NULL),
                failed_op(FETCH_BREAK)
        {
        }

        cond_checker_t(fetch_condition_t func_,
                       void*             ext_data_,
                       cond_failed_e     failed_op_
                      )
            :
                cond_func(func_),
                ext_data(ext_data_),
                failed_op(failed_op_)
        {
        }

        fetch_condition_t   cond_func;
        void*               ext_data;
        cond_failed_e       failed_op;
    };

public:
    base_container_t()
        :
            m_inited(false),
            m_is_lock(false)
    {
    }

    virtual ~base_container_t()
    {
    }

    int initialize(bool is_lock_)
    {
        if (m_inited)
        {
            return -1;
        }

        m_is_lock = is_lock_;

        return 0;
    }

    virtual int fetch_task(CONTAINER<ELEMENT>&          out_task_,
                           uint32_t&                    out_all_task_num_,
                           uint32_t                     fetch_count_,
                           cond_checker_t*              checker_ = NULL,
                           task_prior_e                 prior_ = TASK_PRIOR_NORMAL
                          ) = 0;

    virtual void clear(task_prior_e prior_ = TASK_PRIOR_NORMAL) = 0;

    bool is_lock() const
    {
        return m_is_lock;
    }

protected:
    bool                                                m_inited;
    bool                                                m_is_lock;
    mutable mutex_t                                     m_mutex; 
    CONTAINER<ELEMENT>                                  m_container_arr[TASK_PRIOR_COUNT];
};

}

}

#endif //! _CHAOS_TIMER_CONTAINER_H_

