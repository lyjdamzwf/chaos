/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_STATISTIC_SERVICE_H_
#define _CHAOS_STATISTIC_SERVICE_H_

/*!
 *  @file           statistic_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.7.7
 *  @brief          statistic service
 *  @last changed
 *
 */

#include <stdint.h>
#include <string>
#include <fstream>
#include <map>
using namespace std;

#include <chaos/async_method/async_method_inc.h>
#include <chaos/utility/utility_inc.h>
#include <chaos/task_service/task_service_inc.h>

using namespace chaos::async_method;
using namespace chaos::utility;
using namespace chaos::task_service;

namespace chaos
{

namespace statistic
{

#define DEFAULT_TIMER_EXPIRATION 3600

class statistic_service_t
{
public:
    //! yunjie: 主要记录以函数为粒度的性能统计
    //!         cost单位为微妙
    struct performance_info_t
    {
        uint64_t         max_cost;
        uint64_t         min_cost;
        uint64_t         total_cost;
        uint64_t         sum;
        bool             is_persist;
    };

    //! yunjie: 主要记录某各接口或业务的吞吐量信息
    struct throughput_info_t
    {
        uint64_t        start_time;
        uint64_t        end_time;
        uint64_t        total_val;
        bool            is_persist;
    };

    typedef map<string, performance_info_t>             perf_table_t;
    typedef map<string, throughput_info_t>              tp_table_t;

public:
    statistic_service_t();
    ~statistic_service_t();

    int start(task_service_t* service_ptr_ = NULL);
    int stop();
    int set_timeout(int seconds_);

    void async_perf_stat_cost(
                                const string&       op_,
                                uint64_t            cost_,
                                bool                is_persist_ = false
                             );

    void async_action_increment(
                                const string&       action_,
                                size_t              inc_        = 1,
                                bool                is_persist_ = false
                               );

    void async_stat_throughput(
                                const string&   action_,
                                uint64_t        value_,
                                bool            is_persist_ = false
                              );

private:
    //! yunjie: 私有方法都跑在m_service_ptr上
    int timeout_func_i();

    int sync_perf_stat_cost_i(
                                const string&   op_,
                                uint64_t        cost_,
                                bool            is_persist_
                             );

    int sync_action_increment_i(
                                const string&       action_,
                                size_t              inc_,
                                bool                is_persist_
                               );

    int sync_stat_throughput_i(
                                const string&   action_,
                                uint64_t        value_,
                                bool            is_persist_
                              );

    performance_info_t& find_perf_info_i(const string& op_name_);
    throughput_info_t& find_tp_info_i(const string& op_name_);

private:
    bool                                    m_started;
    task_service_t*                         m_service_ptr;
    bool                                    m_is_own;
    int                                     m_timer_expiration;

private:
    perf_table_t                            m_perf_table;
    tp_table_t                              m_tp_table;
};

class performance_guard_t
{
public:
    performance_guard_t(
                        statistic_service_t&    service_,
                        const char *            info_       = "",
                        bool                    is_persist_ = false
                       )
        :
            m_service(service_),
            m_info(info_),
            m_is_persist(is_persist_)
    {
        gettimeofday(&m_begin_tv, NULL);
    }

    ~performance_guard_t()
    {
        struct timeval end_tv;
        gettimeofday(&end_tv, NULL);

        uint64_t cost_us = (end_tv.tv_sec - m_begin_tv.tv_sec) * 1000 * 1000 + (end_tv.tv_usec - m_begin_tv.tv_usec);
        m_service.async_perf_stat_cost(m_info, cost_us, m_is_persist);
    }

private:
    statistic_service_t&            m_service;
    struct timeval                  m_begin_tv;
    std::string                     m_info;
    bool                            m_is_persist;
};

#define PERF_GUARD(service, info) \
performance_guard_t ___perf_guard_1104___(service, info, false);

#define ACT_CNT_STAT(service, info) \
service.async_action_increment(info, 1, true);

#define TP_STAT(service, info, val) \
service.async_stat_throughput(info, val, true);

}

}

#endif //! _CHAOS_STATISTIC_SERVICE_H_
