/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_WORK_SERVICE_H_
#define _CHAOS_WORK_SERVICE_H_

/*!
 *  @file           work_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.17
 *  @brief          work service
 *  @last changed
 *
 */

#include <vector>
#include <list>

#include <chaos/utility/utility_inc.h>
#include <chaos/log/log_inc.h>
#include <chaos/task_service/task_service_inc.h>
#include <chaos/heart_beat/heart_beat_inc.h>

#include <chaos/network/network_tool.h>
#include <chaos/network/connection.h>

namespace chaos
{

namespace network
{

using namespace std;
using namespace chaos::utility;
using namespace chaos::log;
using namespace chaos::task_service;
using namespace chaos::heart_beat;

#ifndef DEFAULT_CONN_VCT_SIZE
#define DEFAULT_CONN_VCT_SIZE       65535
#endif

//! yunjie: heart_beat中对conn_id_t的hash函数
class hash_conn_id_t
{
public:
    size_t operator()(const conn_id_t& conn_id_) const
    {
        return conn_id_.socket;
    }
};

typedef         void(*conn_timedout_callback_t)(conn_ptr_t&);

class work_service_t;
struct conn_heart_beat_param_t
{
    conn_heart_beat_param_t()
        :
            timeout_flag(false),
            timeout(0),
            max_limit_flag(false),
            max_limit(0)
    {
    }

    bool                                    timeout_flag;
    uint32_t                                timeout;
    bool                                    max_limit_flag;
    uint32_t                                max_limit;
};

typedef     bool (*broadcast_filter_t) (const conn_id_t&, void*);

class work_service_t : public task_service_t
{
public:
    work_service_t(const string& service_name_ = DEFAULT_SERVICE_NAME);
    virtual ~work_service_t();

    //! yunjie: heart_beat相关
    static void conn_timedout_callback(conn_id_t& conn_id_);
    int start_heart_beat_service(const conn_heart_beat_param_t& param_);

    int start(int32_t thread_num_ = DEFAULT_TASK_SERVICE_THREAD_NUM);
    int stop();

    int async_add_connection(conn_ptr_t conn_ptr_);
    int async_del_connection(const conn_id_t& conn_id_);

    int async_broadcast(
                        const packet_wrapper_t&     msg_,
                        broadcast_filter_t          filter_ = NULL
                       );
    int async_broadcast(
                        const char*                 msg_,
                        uint32_t                    size_,
                        broadcast_filter_t          filter_ = NULL
                       );

    void async_add_hb_element(conn_id_t& conn_id_);
    void async_update_hb_element(conn_id_t& conn_id_);
    void async_del_hb_element(conn_id_t& conn_id_);

    conn_ptr_t get_conn(const conn_id_t& conn_id_);

    bool is_enable_hb() const
    {
        return m_enable_conn_heart_beat;
    }

private:
    int sync_close_all_conn_i();

    int sync_add_connection_i(conn_ptr_t conn_ptr_);
    int sync_del_connection_i(const conn_id_t& conn_id_);

    int sync_broadcast_packet_wrapper_i(
                                        const packet_wrapper_t&     msg_,
                                        broadcast_filter_t          filter_ = NULL
                                        );
    int sync_broadcast_data_i(
                                const char*                 msg_,
                                uint32_t                    size_,
                                broadcast_filter_t          filter_ = NULL
                             );


private:
    vector<conn_ptr_t>                                                  m_conn_vct;
    bool                                                                m_enable_conn_heart_beat;
    heart_beat_service_t<conn_id_t, hash_conn_id_t>                     m_conn_heart_beat;
};


}

}

#endif //! _CHAOS_WORK_SERVICE_H_

