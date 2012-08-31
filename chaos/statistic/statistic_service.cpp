/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

/*!
 *  @file           statistic_service.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.7.7
 *  @brief          statistic service
 *  @last changed
 *
 */

#include <chaos/log/log_inc.h>
using namespace chaos::log;

#include <chaos/statistic/statistic_service.h>

namespace chaos
{

namespace statistic
{

statistic_service_t::statistic_service_t() :
    m_started(false),
    m_service_ptr(NULL),
    m_is_own(false),
    m_timer_expiration(DEFAULT_TIMER_EXPIRATION)
{
}

statistic_service_t::~statistic_service_t()
{
    stop();
}

int statistic_service_t::set_timeout(int seconds_)
{
    m_timer_expiration = seconds_;

    return 0;
}

int statistic_service_t::start(task_service_t* service_ptr_)
{
    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::start begin"));

    if (m_started)
    {
        LOGWARN((STATISTIC_MOUDLE, "statistic_service_t::start "
                    "service has been started, return"));
        return 0;
    }

    if (NULL == service_ptr_)
    {
        m_service_ptr = new task_service_t("statistic service");
        if (NULL == m_service_ptr)
        {
            LOGWARN((STATISTIC_MOUDLE, "statistic_service_t::start "
                        "new service failed, return"));
            return -1;
        }

        m_service_ptr->start();
        m_is_own = true;
    }
    else
    {
        //! yunjie: 如果是外部的service, 启动权交给外部,
        //！        这里不需要启动
        m_service_ptr = service_ptr_;
        m_is_own = false;
    }

    m_service_ptr->register_timer(
                                m_timer_expiration,
                                bind_memfunc(this, &statistic_service_t::timeout_func_i),
                                false
                                );
    m_started = true;

    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::start end"));
    return 0;
}

int statistic_service_t::stop()
{
    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::stop begin"));

    if (!m_started)
    {
        LOGWARN((STATISTIC_MOUDLE, "statistic_service_t::stop "
                    "service has been stoped, return"));
        return 0;
    }

    if (m_is_own)
    {
        m_service_ptr->stop();
        SAFE_DELETE(m_service_ptr);
    }

    m_started = false;

    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::stop end"));
    return 0;
}

int statistic_service_t::timeout_func_i()
{
    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::timeout_func_i begin"));

    if (m_started)
    {
        struct timeval now = m_service_ptr->get_cached_time();

        struct tm tmp;
        localtime_r(&now.tv_sec, &tmp);

        char buff[16384];
        snprintf(buff, sizeof(buff), "[%04d/%02d/%02d %02d:%02d:%02d]  timeout=[%d s] statistic record:\n",
                tmp.tm_year + 1900, tmp.tm_mon + 1, tmp.tm_mday, tmp.tm_hour, tmp.tm_min, tmp.tm_sec,
                m_timer_expiration);

        LOGINFO((STATISTIC_MOUDLE, "STAT INFO - %s", buff));

        {
            //! yunjie: 遍历perf table
            perf_table_t::iterator it = m_perf_table.begin();
            while (it != m_perf_table.end())
            {
                const string& op_name = it->first;
                performance_info_t& refer = it->second;
                uint64_t per_cost, req_per_sec;

                if (0 == refer.sum)
                {
                    per_cost = 0;
                }
                else
                {
                    per_cost = refer.total_cost / refer.sum;
                }
                req_per_sec = (per_cost == 0) ? 0 : (1000000 / per_cost);

                //! yunjie: 判断是统计性能还是统计次数
                if (0 != req_per_sec)
                {
                    snprintf(buff, sizeof(buff), "max:[%lu us], min:[%lu us], per:[%lu us], rps:[%lu], exe:[%lu times]",
                            refer.max_cost, refer.min_cost, per_cost, req_per_sec, refer.sum);
                }
                else
                {
                    snprintf(buff, sizeof(buff), "count:[%lu]", refer.sum);
                }

                LOGINFO((STATISTIC_MOUDLE, "\t%s : %s\n", op_name.c_str(), buff));

                if (refer.is_persist)
                {
                    ++it;
                }
                else
                {
                    m_perf_table.erase(it++);
                }
            }
        }

        {
            //! yunjie: 遍历tp table
            tp_table_t::iterator it = m_tp_table.begin();
            while (it != m_tp_table.end())
            {
                const string& op_name = it->first;
                throughput_info_t& refer = it->second;

                uint64_t elapsed_sec;
                if (0 == (elapsed_sec = refer.end_time - refer.start_time))
                {
                    snprintf(buff, sizeof(buff), "elapsed time:[%lu h, %lu m, %lu s] "
                            "total tp:[%lu]",
                            elapsed_sec / 60 / 60,
                            elapsed_sec / 60,
                            elapsed_sec,
                            refer.total_val
                            );
                }
                else
                {
                    snprintf(buff, sizeof(buff), "elapsed time:[%lu h, %lu m, %lu s] "
                            "total tp:[%lu] tp per sec:[%lu]",
                            elapsed_sec / 60 / 60,
                            elapsed_sec / 60,
                            elapsed_sec,
                            refer.total_val,
                            refer.total_val / elapsed_sec
                            );

                }

                LOGINFO((STATISTIC_MOUDLE, "\t%s : %s\n", op_name.c_str(), buff));

                if (refer.is_persist)
                {
                    ++it;
                }
                else
                {
                    m_tp_table.erase(it++);
                }
            }
        }

        m_service_ptr->register_timer(
                                        m_timer_expiration,
                                        bind_memfunc(this, &statistic_service_t::timeout_func_i),
                                        false
                                    );
    }

    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::timeout_func_i end"));
    return 0;
}

void statistic_service_t::async_perf_stat_cost(
                                                const string&       op_,
                                                uint64_t            cost_,
                                                bool                is_persist_
                                              )
{
    if (NULL != m_service_ptr)
    {
        m_service_ptr->post(
                bind_memfunc(
                                this,
                                &statistic_service_t::sync_perf_stat_cost_i,
                                op_,
                                cost_,
                                is_persist_
                                            )
                            );
    }
}

void statistic_service_t::async_action_increment(
                                                    const string&       action_,
                                                    size_t              inc_,
                                                    bool                is_persist_
                                                )
{
    if (NULL != m_service_ptr)
    {
        m_service_ptr->post(
                bind_memfunc(
                                this,
                                &statistic_service_t::sync_action_increment_i,
                                action_,
                                inc_,
                                is_persist_
                                            )
                            );
    }
}

void statistic_service_t::async_stat_throughput(
                                                const string&   action_,
                                                uint64_t        value_,
                                                bool            is_persist_
                                               )
{
    if (NULL != m_service_ptr)
    {
        m_service_ptr->post(
                bind_memfunc(
                                this,
                                &statistic_service_t::sync_stat_throughput_i,
                                action_,
                                value_,
                                is_persist_
                                            )
                            );
    }
}

statistic_service_t::performance_info_t& statistic_service_t::find_perf_info_i(const string& op_name_)
{
    perf_table_t::iterator it = m_perf_table.find(op_name_);
    if(it != m_perf_table.end())
    {
        return it->second;
    }

    performance_info_t& ret = m_perf_table[op_name_];

    ret.max_cost   = 0;
    ret.min_cost   = 0;
    ret.total_cost = 0;
    ret.sum        = 0;
    ret.is_persist = false;

    return ret;
}

statistic_service_t::throughput_info_t& statistic_service_t::find_tp_info_i(const string& op_name_)
{
    tp_table_t::iterator it = m_tp_table.find(op_name_);
    if(it != m_tp_table.end())
    {
        return it->second;
    }

    throughput_info_t& ret = m_tp_table[op_name_];

    return ret;
}

int statistic_service_t::sync_perf_stat_cost_i(
                                                const string&   op_,
                                                uint64_t        cost_,
                                                bool            is_persist_
                                              )
{
    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::sync_perf_stat_cost_i begin"));

    performance_info_t& refer = find_perf_info_i(op_);
    if (cost_ > refer.max_cost)
    {
        refer.max_cost = cost_;
    }

    if (0 == refer.min_cost)
    {
        refer.min_cost = cost_;
    }
    else if (cost_ < refer.min_cost)
    {
        refer.min_cost = cost_;
    }

    refer.total_cost += cost_;
    refer.sum++;
    refer.is_persist = is_persist_;

    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::sync_perf_stat_cost_i end"));
    return 0;
}

int statistic_service_t::sync_action_increment_i(
                                                    const string&       action_,
                                                    size_t              inc_,
                                                    bool                is_persist_
                                                )
{
    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::sync_action_increment_i begin"));

    performance_info_t& refer = find_perf_info_i(action_);

    refer.sum += inc_;
    refer.is_persist = is_persist_;

    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::sync_action_increment_i end"));
    return 0;
}

int statistic_service_t::sync_stat_throughput_i(
                                                const string&   action_,
                                                uint64_t        value_,
                                                bool            is_persist_
                                               )
{
    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::sync_stat_throughput_i begin"));

    throughput_info_t& refer = find_tp_info_i(action_);
    struct timeval now = m_service_ptr->get_cached_time();

    if (0 == refer.start_time)
    {
        refer.start_time = now.tv_sec;
    }

    refer.end_time = now.tv_sec;
    refer.total_val += value_;
    refer.is_persist = is_persist_;

    LOGTRACE((STATISTIC_MOUDLE, "statistic_service_t::sync_stat_throughput_i end"));
    return 0;
}

}

}
