/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TASK_SERVICE_GROUP_H_
#define _CHAOS_TASK_SERVICE_GROUP_H_

/*!
 *  @file           task_service_group.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.15
 *  @brief          task service group
 *  @last changed
 *
 */

#include <vector>

#include <chaos/task_service/task_service.h>

namespace chaos
{

namespace task_service
{

using namespace std;

#define DEFAULT_THREAD_NUM_PER_SERVICE      1

class task_service_group_t : private noncopyable_t
{
public:
    typedef     vector<task_service_t*>              task_service_container_t;

    task_service_group_t(const string& service_name_ = DEFAULT_SERVICE_NAME);
    virtual ~task_service_group_t();


    virtual int start(
                        int task_service_num_,
                        int thread_num_per_service_ = DEFAULT_THREAD_NUM_PER_SERVICE
                     );
    virtual int stop();
    task_service_t* operator[](uint32_t index_);
    int size() const
    {
        return m_task_service_group.size();
    }

    //! yunjie: ext_data可以给子类实现用来判断post到哪一个task_service队列中去
    //! virtual int post(const async_method_t& async_method_, void* ext_data_ = NULL, task_prior_e prior_ = TASK_PRIOR_NORMAL, bool allow_exec_local_ = true) = 0;

protected:
    //! yunjie: 子类可实现自己的new_service, 返回子类对象
    virtual task_service_t* new_service();

protected:
    bool                                                m_started;
    string                                              m_service_name;
    task_service_container_t                            m_task_service_group;
};

}

}

#endif //! _CHAOS_TASK_SERVICE_GROUP_H_
