/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TASK_QUEUE_H_
#define _CHAOS_TASK_QUEUE_H_

/*! 
 *  @file           task_queue.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.17
 *  @brief          task queue
 *  @last changed
 *
 */

#include <deque>

#include "thread_inc.h"
#include "async_method_inc.h"
#include "base_container.h"
#include "task_service_define.h"

namespace chaos
{

namespace task_service
{

using namespace std;
using namespace chaos::thread;

//! yunjie: 为了适配高版本g++对嵌套模板参数的类型检查更为严格
template<typename T>
class __deque_t__ : public std::deque<T>
{
};

class task_queue_t : public base_container_t<async_method_t, __deque_t__>
{
public:
    void push(const async_method_t& task_, task_prior_e prior_ = TASK_PRIOR_NORMAL)
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        m_container_arr[prior_].push_back(task_);
    }

    int fetch_task(
                    container_t&                out_task_,
                    uint32_t&                   all_task_num_,
                    uint32_t                    task_num_,
                    cond_checker_t*             checker         = NULL,
                    task_prior_e                prior_          = TASK_PRIOR_NORMAL
                  )
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        async_method_t empty_method;
        container_t& task_queue = m_container_arr[prior_];

        if (task_queue.empty())
        {
            return 0;
        }

        all_task_num_ = task_queue.size();

        if (task_num_ > task_queue.size())
        {
            for (
                    deque<async_method_t>::iterator it = task_queue.begin();
                    it < task_queue.end();
                    ++it
                )
            {
                out_task_.push_back(*it);
            }

            task_queue.clear();
        }
        else
        {
            for (
                    deque<async_method_t>::iterator it = task_queue.begin();
                    it < task_queue.begin() + task_num_;
                    ++it
                )
            {
                out_task_.push_back(*it);
            }
            task_queue.erase(task_queue.begin(), task_queue.begin() + task_num_);
        }

        return 0;
    }

    bool empty(task_prior_e prior_ = TASK_PRIOR_NORMAL) const
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        bool ret = m_container_arr[prior_].empty();

        return ret;
    }

    void clear_all_queue()
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        for (int i = 0; i < TASK_PRIOR_COUNT; ++i)
        {
            m_container_arr[i].clear();
        }
    }

    void clear(task_prior_e prior_ = TASK_PRIOR_NORMAL)
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        m_container_arr[prior_].clear();
    }

    int size(task_prior_e prior_ = TASK_PRIOR_NORMAL) const
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        int ret = m_container_arr[prior_].size();

        return ret;
    }
};

}

}

#endif //! _CHAOS_TASK_QUEUE_H_
