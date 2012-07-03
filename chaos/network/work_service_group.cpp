/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include "work_service_group.h"

/*! 
 *  @file           work_service_group.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.14
 *  @brief          work service
 *  @last changed
 *
 */

namespace chaos
{

namespace network
{

work_service_group_t::work_service_group_t()
    :
        task_service_group_t("work_service")        //! yunjie: 调用父类构造, 初始化service name
{
    
}

work_service_group_t::~work_service_group_t()
{
}

void work_service_group_t::enable_conn_heart_beat(const conn_heart_beat_param_t& param_)
{
    m_conn_heart_beat_param = param_;
}

int work_service_group_t::start(int task_service_num_, int thread_num_per_service_)
{
    int ret = 0;
    if ((ret = task_service_group_t::start(task_service_num_, thread_num_per_service_)))
    {
        return ret;
    }

    if (
        m_conn_heart_beat_param.timeout_flag
        && m_conn_heart_beat_param.timeout
        )
    {
        for (
                task_service_container_t::iterator it = m_task_service_group.begin();
                it != m_task_service_group.end();
                ++it
            )
        {
            work_service_t* work_ptr = (work_service_t*)(*it);
            if (NULL != work_ptr)
            {
                work_ptr->start_heart_beat_service(m_conn_heart_beat_param);
            }
        }
    }

    return ret;
}

task_service_t* work_service_group_t::new_service()
{
    return new work_service_t(m_service_name);
}

}

}
