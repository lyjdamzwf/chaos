/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_NETWORK_CONFIG_H_
#define _CHAOS_NETWORK_CONFIG_H_

#include <chaos/utility/utility_inc.h>

/*!
 *  @file           network_config.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.7.14
 *  @brief          network config
 *  @last changed
 *
 */

using namespace chaos::utility;

namespace chaos
{

namespace network
{

struct network_config_t
{
    network_config_t()
        :
            tcp_sndbuf_size(64 * 1024),
            tcp_rcvbuf_size(64 * 1024),
            max_send_buffer_size(16 * 1024),
            max_recv_buffer_size(16 * 1024),
            tcp_nodelay(false)
    {
    }

    //! yunjie: tcp协议栈的发送/接收缓冲区大小
    int32_t             tcp_sndbuf_size;
    int32_t             tcp_rcvbuf_size;

    //! yunjie: chaos应用层的发送/接收缓冲区最大限制
    int32_t             max_send_buffer_size;
    int32_t             max_recv_buffer_size;

    //! yunjie: 是否打开TCP_NODELAY选项(关闭nagle)
    bool                tcp_nodelay;
};

static network_config_t     default_config;

struct config_holder_t : private noncopyable_t
{
    config_holder_t()
        :
            config_ptr(NULL)
    {
    }

    ~config_holder_t()
    {
    }

    void set_config(network_config_t* config_)
    {
        config_ptr = config_;
    }

    const network_config_t& operator *()
    {
        if (NULL == config_ptr)
        {
            return default_config;
        }
        else
        {
            return *config_ptr;
        }
    }

private:
    network_config_t*           config_ptr;
};

}

}

#endif //! _CHAOS_NETWORK_CONFIG_H_
