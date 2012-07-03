/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_TCP_SERVICE_H_
#define _CHAOS_TCP_SERVICE_H_

/*! 
 *  @file           tcp_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.17
 *  @brief          tcp service
 *  @last changed
 *
 */

#include "log_inc.h"

#include "acceptor_service.h"
#include "work_service_group.h"
#include "default_conn_strategy.h"

namespace chaos
{

namespace network
{

#define DEFAULT_WORK_THREAD_NUM     2

using namespace chaos::log;

template<typename CONN_TYPE = default_conn_strategy_t>
class tcp_service_t
{
public:
    tcp_service_t();
    virtual ~tcp_service_t();

    int initialize( 
                    const string& host_,
                    uint32_t port_,
                    connection_t::on_conn_event_t event_func_ = NULL
                    );
    int start(uint16_t work_thread_num_ = DEFAULT_WORK_THREAD_NUM);
    int stop();

    void enable_conn_heart_beat(const conn_heart_beat_param_t& param_);

private:
    acceptor_service_t<CONN_TYPE>                       m_acceptor_service;
    work_service_group_t                                m_work_service_group;
};

template<typename CONN_TYPE>
tcp_service_t<CONN_TYPE>::tcp_service_t()
{
}

template<typename CONN_TYPE>
tcp_service_t<CONN_TYPE>::~tcp_service_t()
{
}

template<typename CONN_TYPE>
int tcp_service_t<CONN_TYPE>::initialize(const string& host_, uint32_t port_, connection_t::on_conn_event_t event_func_)
{
    return m_acceptor_service.initialize(host_, port_, &m_work_service_group, event_func_);
}

template<typename CONN_TYPE>
int tcp_service_t<CONN_TYPE>::start(uint16_t work_thread_num_)
{
    //! yunjie: 两个单线程的task_service - one loop one thread, 由于
    //!         connecion_t不是线程安全的, 所以不能用一个task_service
    //!         多个线程驱动, 而且出于性能的考虑也不推荐这么做
    int ws_ret = m_work_service_group.start(work_thread_num_);
    int ac_ret = m_acceptor_service.start();
    
    if (-1 == ws_ret || -1 == ac_ret)
    {
        return -1;
    }

    return 0;
}

template<typename CONN_TYPE>
int tcp_service_t<CONN_TYPE>::stop()
{
    m_acceptor_service.stop();
    m_work_service_group.stop();

    return 0;
}

template<typename CONN_TYPE>
void tcp_service_t<CONN_TYPE>::enable_conn_heart_beat(const conn_heart_beat_param_t& param_)
{
    m_work_service_group.enable_conn_heart_beat(param_);
}

}

}

#endif //! _CHAOS_TCP_SERVICE_H_
