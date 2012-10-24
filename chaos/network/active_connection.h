/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ACTIVE_CONNECTION_H_
#define _CHAOS_ACTIVE_CONNECTION_H_

/*!
 *  @file           active_connection.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.6.20
 *  @brief          active connection
 *  @last changed
 *
 */

#include <chaos/network/connection.h>
#include <chaos/network/work_service.h>

namespace chaos
{

namespace network
{

class active_connection_t : public connection_t
{

public:
    template<typename CONN_TYPE>
    static int sync_connect(
                                const string& host_,
                                uint32_t port_,
                                work_service_t* service_ptr_,
                                struct conn_id_t& out_,
                                on_conn_event_t event_func_ = NULL,
                                network_config_t* config_ = NULL,
                                bool is_add_to_hb_ = true
                            );
};

template<typename CONN_TYPE>
int active_connection_t::sync_connect(
                                        const string& host_,
                                        uint32_t port_,
                                        work_service_t* service_ptr_,
                                        struct conn_id_t& out_,
                                        on_conn_event_t event_func_,
                                        network_config_t* config_ptr_,
                                        bool is_add_to_hb_
                                    )
{
    LOGTRACE((CONNECTION_MODULE, "active_connection_t::sync_connect begin"));

    if (NULL == service_ptr_)
    {
        LOGWARN((CONNECTION_MODULE, "active_connection_t::sync_connect constructor or service_ptr is NULL, return."));
        return -1;
    }

    int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        LOGWARN((CONNECTION_MODULE, "active_connection_t::sync_connect generate sockfd failed errno:[%s].", STRERR));
        return -1;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_);
    servaddr.sin_addr.s_addr = htonl(network_tool_t::ipv4_string_to_int(host_));

    if (::connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        LOGWARN((CONNECTION_MODULE, "active_connection_t::sync_connect connect failed errno:[%s].", STRERR));
        return -1;
    }

    struct timeval now;
    gettimeofday(&now, NULL);
    conn_ptr_t conn_ptr = construct<CONN_TYPE>();
    if (NULL == conn_ptr)
    {
        LOGWARN((CONNECTION_MODULE, "active_connection_t::sync_connect conn_ptr is NULL, return."));
        return -1;
    }

    conn_ptr->initialize(sockfd, now, service_ptr_, T_ACTIVE, event_func_, config_ptr_, is_add_to_hb_);

    out_.socket = sockfd;
    out_.timestamp = now;
    out_.service_ptr = service_ptr_;

    LOGTRACE((CONNECTION_MODULE, "active_connection_t::sync_connect end"));
    return 0;
}

}

}

#endif
