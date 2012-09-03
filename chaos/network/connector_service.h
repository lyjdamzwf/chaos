/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_CONNECTOR_SERVICE_H_
#define _CHAOS_CONNECTOR_SERVICE_H_

/*!
 *  @file           connector_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.7.8
 *  @brief          connector service
 *  @last changed
 *
 */

#include <chaos/log/log_inc.h>

#include <chaos/network/work_service_group.h>
#include <chaos/network/default_conn_strategy.h>
#include <chaos/network/network_config.h>
#include <chaos/network/active_connection.h>

namespace chaos
{

namespace network
{

#define DEFAULT_CS_WORK_THREAD_NUM  2
#define DEFAULT_RECONNECT_INTERVAL  3   //! yunjie: 重连间隔3秒

template<typename CONN_TYPE = default_conn_strategy_t>
class connector_service_t
{
public:
    connector_service_t();
    virtual ~connector_service_t();

    int start(uint16_t work_thread_num_ = DEFAULT_CS_WORK_THREAD_NUM);
    int stop();

    void enable_conn_heart_beat(const conn_heart_beat_param_t& param_);

    int async_connect(
                        const string&                   host_,
                        uint32_t                        port_,
                        connection_t::on_conn_event_t   event_func_ = NULL,
                        bool                            is_add_to_hb_ = true
                    );

    int async_broadcast(
                        const packet_wrapper_t&     msg_,
                        broadcast_filter_t          filter_ = NULL
                       );
    int async_broadcast(
                        const char*                 msg_,
                        uint32_t                    size_,
                        broadcast_filter_t          filter_ = NULL
                       );


    void set_reconnect_interval(int reconnect_interval_)
    {
        m_reconnect_interval = reconnect_interval_;
    }

    void set_network_config(network_config_t config_ = network_config_t())
    {
        m_network_config = config_;
    }

private:
    int sync_connect_i(
                        const string&                   host_,
                        uint32_t                        port_,
                        work_service_t*                 service_ptr_,
                        connection_t::on_conn_event_t   event_func_,
                        bool                            is_add_to_hb_
                    );

    int get_service_index_i()
    {
        m_service_index = (++m_service_index >= m_work_service_group.size()
                            ? 0 : m_service_index);

        return m_service_index;
    }

private:
    bool                                                m_started;
    work_service_group_t                                m_work_service_group;
    int                                                 m_service_index;

    //! yunjie: 重连接个时间, -1表示不进行重连
    int                                                 m_reconnect_interval;
    network_config_t                                    m_network_config;
};

template<typename CONN_TYPE>
connector_service_t<CONN_TYPE>::connector_service_t()
    :
        m_started(false),
        m_service_index(0),
        m_reconnect_interval(DEFAULT_RECONNECT_INTERVAL)
{
}

template<typename CONN_TYPE>
connector_service_t<CONN_TYPE>::~connector_service_t()
{

}

template<typename CONN_TYPE>
int connector_service_t<CONN_TYPE>::start(uint16_t work_thread_num_)
{
    LOGTRACE((CONNECTOR_SERVICE, "connector_service_t::start"
                    " arg-[work_thread_num:%u] begin",
                    work_thread_num_
            ));

    if (m_started)
    {
        LOGWARN((CONNECTOR_SERVICE, "connector_service_t::start"
                    " service has started, return."
                ));
        return 0;
    }

    int ret = m_work_service_group.start(work_thread_num_);
    m_started = true;

    LOGTRACE((CONNECTOR_SERVICE, "connector_service_t::start"
                    " arg-[work_thread_num:%u] end",
                    work_thread_num_
            ));
    return ret;
}

template<typename CONN_TYPE>
int connector_service_t<CONN_TYPE>::stop()
{
    LOGTRACE((CONNECTOR_SERVICE, "connector_service_t::stop begin"));

    if (!m_started)
    {
        LOGWARN((CONNECTOR_SERVICE, "connector_service_t::stop"
                    " service has stopped, return."
                ));
        return 0;
    }

    m_work_service_group.stop();
    m_started = false;

    LOGTRACE((CONNECTOR_SERVICE, "connector_service_t::stop end"));
    return 0;
}

template<typename CONN_TYPE>
void connector_service_t<CONN_TYPE>::enable_conn_heart_beat(const conn_heart_beat_param_t& param_)
{
    m_work_service_group.enable_conn_heart_beat(param_);
}

template<typename CONN_TYPE>
int connector_service_t<CONN_TYPE>::async_connect(
                                                    const string&                   host_,
                                                    uint32_t                        port_,
                                                    connection_t::on_conn_event_t   event_func_,
                                                    bool                            is_add_to_hb_
                                                )
{
    int service_index = get_service_index_i();
    work_service_t* service_ptr = (work_service_t*)(m_work_service_group[service_index]);

    service_ptr->post(
                        bind_memfunc(
                                    this,
                                    &connector_service_t<CONN_TYPE>::sync_connect_i,
                                    host_,
                                    port_,
                                    service_ptr,
                                    event_func_,
                                    is_add_to_hb_
                                                    )
                    );

    return 0;
}

template<typename CONN_TYPE>
int connector_service_t<CONN_TYPE>::sync_connect_i(
                                                    const string&                   host_,
                                                    uint32_t                        port_,
                                                    work_service_t*                 service_ptr_,
                                                    connection_t::on_conn_event_t   event_func_,
                                                    bool                            is_add_to_hb_
                                                )
{
    LOGTRACE((CONNECTOR_SERVICE, "connector_service_t::sync_connect_i"
                " args-[host:%s, port:%u] begin",
                host_.c_str(), port_
            ));

    conn_id_t conn_id;
    int ret = active_connection_t::sync_connect<CONN_TYPE>(
                host_,
                port_,
                service_ptr_,
                conn_id,
                event_func_,
                &m_network_config,
                is_add_to_hb_
                );

    if (-1 == ret)
    {
        LOGWARN((CONNECTOR_SERVICE, "sync_connect failed."));

        //! yunjie: 回调通知上层连接失败
        event_func_(EV_CONNECT_FAILED, ST_UNINIT, conn_id_t(), NULL);

        if (-1 != m_reconnect_interval)
        {
            //! yunjie: 进行重连
            int service_index = get_service_index_i();
            work_service_t* service_ptr = (work_service_t*)(m_work_service_group[service_index]);

            service_ptr->register_timer(
                                            m_reconnect_interval,
                                            bind_memfunc(
                                                            this,
                                                            &connector_service_t<CONN_TYPE>::sync_connect_i,
                                                            host_,
                                                            port_,
                                                            service_ptr,
                                                            event_func_,
                                                            is_add_to_hb_
                                                                        ),
                                            false
                                        );

        }

        return -1;
    }

    LOGTRACE((CONNECTOR_SERVICE, "connector_service_t::sync_connect_i"
                " args-[host:%s, port:%u] end",
                host_.c_str(), port_
            ));
    return 0;
}

template<typename CONN_TYPE>
int connector_service_t<CONN_TYPE>::async_broadcast(
                                                const packet_wrapper_t&     msg_,
                                                broadcast_filter_t          filter_
                                              )
{
    m_work_service_group.async_broadcast(msg_, filter_);

    return 0;
}

template<typename CONN_TYPE>
int connector_service_t<CONN_TYPE>::async_broadcast(
                                                const char*                 msg_,
                                                uint32_t                    size_,
                                                broadcast_filter_t          filter_
                                             )
{
    m_work_service_group.async_broadcast(msg_, size_, filter_);

    return 0;
}

}

}

#endif //! _CHAOS_CONNECTOR_SERVICE_H_
