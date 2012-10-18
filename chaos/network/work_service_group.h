/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_WORK_SERVICE_GROUP_H_
#define _CHAOS_WORK_SERVICE_GROUP_H_

/*!
 *  @file           work_service_group.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.14
 *  @brief          work service
 *  @last changed
 *
 */

#include <chaos/network/work_service.h>

namespace chaos
{

namespace network
{

class work_service_group_t : public task_service_group_t
{
public:
    work_service_group_t();
    virtual ~work_service_group_t();

    //! yunjie: enable_conn_heart_beat要在start之前调用才会生效
    void enable_conn_heart_beat(const conn_heart_beat_param_t& param_);

    int start(
                int task_service_num_,
                int thread_num_per_service_ = DEFAULT_THREAD_NUM_PER_SERVICE
             );

    int async_broadcast(
                        packet_wrapper_t&           msg_,
                        bool                        auto_clear_,
                        broadcast_filter_t          filter_ = NULL
                       );
    int async_broadcast(
                        const char*                 msg_,
                        uint32_t                    size_,
                        broadcast_filter_t          filter_ = NULL
                       );

protected:
    //! yunjie: 父类的virtual方法
    task_service_t* new_service();

private:
    conn_heart_beat_param_t                     m_conn_heart_beat_param;
};

}

}

#endif //! _CHAOS_WORK_SERVICE_GROUP_H_
