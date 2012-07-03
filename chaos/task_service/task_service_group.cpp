/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include "task_service_group.h"

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

namespace chaos
{

namespace task_service
{

task_service_group_t::task_service_group_t(const string& service_name_)
    :
        m_started(false),
        m_service_name(service_name_)
{
}

task_service_group_t::~task_service_group_t()
{
    stop();
}

task_service_t* task_service_group_t::new_service()
{
    return new task_service_t(m_service_name);
}

int task_service_group_t::start(int task_service_num_, int thread_num_per_service_)
{
    if (m_started)
    {
            LOGWARN((TASK_SERVICE_MODULE, "task_service_group_t::start task service has started, return."));
            return 0;
    }

    for (int i = 0; i < task_service_num_; ++i)
    {
        task_service_t* task_service_ptr = new_service();
        if (NULL == task_service_ptr)
        {
            LOGWARN((TASK_SERVICE_MODULE, "task_service_group_t::start new task_service_t failed, return."));
            return -1;
        }

        if (-1 == task_service_ptr->start(thread_num_per_service_))
        {
            LOGWARN((TASK_SERVICE_MODULE, "task_service_group_t::start task_service start failed, return."));

            for (task_service_container_t::iterator it = m_task_service_group.begin();
                 it != m_task_service_group.end();
                 ++it
                )
            {
                (*it)->stop();
                SAFE_DELETE(*it);
            }

            m_task_service_group.clear();

            return -1;
        }

        m_task_service_group.push_back(task_service_ptr);
    }

    m_started = true;

    return 0;
}

int task_service_group_t::stop()
{
    if (!m_started)
    {
        LOGWARN((TASK_SERVICE_MODULE, "task_service_group_t::stop task service has stopped, return."));
        return 0;
    }

    for (uint32_t i = 0; i < m_task_service_group.size(); ++i)
    {
        task_service_t*& task_service_ptr = m_task_service_group[i];
        if (NULL == task_service_ptr)
        {
            LOGWARN((TASK_SERVICE_MODULE, "task_service_group_t::stop task service is NULL, return."));
            return -1;
        }

        if (-1 == task_service_ptr->stop())
        {
            LOGWARN((TASK_SERVICE_MODULE, "task_service_group_t::stop task_service stop failed."));
        }

        SAFE_DELETE(task_service_ptr);
    }

    m_task_service_group.clear();
    m_started = false;

    return 0;
}

task_service_t* task_service_group_t::operator[](uint32_t index_)
{
    if (index_ >= m_task_service_group.size())
    {
        return NULL;
    }
    else
    {
        return m_task_service_group[index_];
    }
}

}

}
