/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TIMER_CONTAINER_H_
#define _CHAOS_TIMER_CONTAINER_H_

/*! 
 *  @file           timer_container.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.1
 *  @brief          timer container
 *  @last changed
 *
 */

#include <queue>

#include "task_service_define.h"
#include "base_container.h"

namespace chaos
{

namespace task_service
{

using namespace std;

struct time_event_t
{

    time_event_t()
        :
            start_time(0),
            interval(0),
            last_exec_time(0),
            timestamp(0),
            persist(false)
    {
    }

    time_event_t(time_t                     start_time_,
                 uint32_t                   interval_,
                 time_t                     last_exec_time_,
                 time_t                     timestamp_,
                 time_event_callback_t      callback_,
                 bool                       persist_
                )
        :
            start_time(start_time_),
            interval(interval_),
            last_exec_time(last_exec_time_),
            timestamp(timestamp_),
            callback(callback_),
            persist(persist_)
    {
    }

    void exec()
    {
        callback();
    }

    void release()
    {
        callback.release();
    }

    bool operator<(const time_event_t& event_) const
    {
        //! yunjie: 由于stl的priority_queue默认是最大堆, 所以这里要取反
        return !(this->timestamp < event_.timestamp);
    }

    void dump()
    {
        printf("start_time:%lu, interval:%d, timestamp:%lu, persist:%d\n",
                start_time, interval, timestamp, persist
              );
    }

    time_t                              start_time;                 //! yunjie: 注册的定时器开始基点, 并不是执行时间点, start_time + interval才是callback的执行时间点.
    uint32_t                            interval;                   //! yunjie: 注册的定时间间隔时间.
    time_t                              last_exec_time;             //! yunjie: 上一次定时器执行时间点, 如果是persist, 每次loop都会更新.
    time_t                              timestamp;                  //! yunjie: 未来的执行时间点, 主要用于作为minheap的key比较.
    time_event_callback_t               callback;                   //! yunjie: 用户注册, 触发时间事件时执行的回调.
    bool                                persist;                    //! yunjie: true - 执行callback后不会从minheap中删除timeevent, false - 执行callback后会删除timeevent, 需要重新注册.
};

//! yunjie: 为了适配高版本g++对嵌套模板参数的类型检查更为严格
template<typename T>
class __heap_t__ : public std::priority_queue<T>
{
};

class timer_container_t : public base_container_t<time_event_t*, __heap_t__>
{
public:
    timer_container_t()
    {
    }

    ~timer_container_t()
    {
    }

    bool empty() const
    {
        CHECK_LOCK(m_is_lock, m_mutex);
        bool ret = m_container_arr[TASK_PRIOR_NORMAL].empty();

        return ret;
    }

    int fetch_task(
                    container_t&                     out_task_,
                    uint32_t&                        out_all_task_num_,
                    uint32_t                         fetch_count_,
                    cond_checker_t*                  checker_,
                    task_prior_e                     prior_ = TASK_PRIOR_NORMAL
                  )
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        if (NULL == checker_)
        {
            return -1;
        }

        if (m_container_arr[prior_].empty() || 0 == fetch_count_)
        {
            return 0;
        }

        uint32_t fetched_count = 0;

        //! yunjie: 将容器的当前元素个数传给外部变量
        out_all_task_num_ = m_container_arr[prior_].size();
        fetch_condition_t cond_func = checker_->cond_func;

        while (!m_container_arr[prior_].empty())
        {
            time_event_t* recent_event = m_container_arr[prior_].top();
            
            if (cond_func != NULL)
            {
                //! yunjie: 条件检查失败, 做各种相应操作
                if (!cond_func(recent_event, checker_->ext_data))
                {
                    switch (checker_->failed_op)
                    {
                        case FETCH_BREAK:
                            goto BREAK_FLAG;
                        case FETCH_RETURN:
                            return fetched_count;
                        case FETCH_CONTINUE:
                            continue;
                    }
                }
            }
                
            out_task_.push(recent_event);
            ++fetched_count;
            m_container_arr[prior_].pop();
            
            //! yunjie: 已获取指定数量的task, 退出循环
            if (fetched_count >= fetch_count_)
            {
                break;
            }
        }
BREAK_FLAG:
 
        return fetched_count;
    }

    void push(time_event_t* event_)
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        m_container_arr[TASK_PRIOR_NORMAL].push(event_);
    }

    void clear(task_prior_e prior_ = TASK_PRIOR_NORMAL)
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        while (!m_container_arr[prior_].empty())
        {
            time_event_t* event = m_container_arr[prior_].top();
            event->release();
            m_container_arr[prior_].pop();
            SAFE_DELETE(event);
        }
    }

    uint32_t size(task_prior_e prior_ = TASK_PRIOR_NORMAL)
    {
        CHECK_LOCK(m_is_lock, m_mutex);

        return m_container_arr[prior_].size();
    }
};

}

}

#endif //! _CHAOS_TIMER_CONTAINER_H_
