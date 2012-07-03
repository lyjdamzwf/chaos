/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_NETWORK_TOOL_H_
#define _CHAOS_NETWORK_TOOL_H_

/*! 
 *  @file           network_tool.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.11
 *  @brief          network tool
 *  @last changed
 *
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>

namespace chaos
{

namespace network
{

class network_tool_t
{
public:
    static uint32_t ipv4_string_to_int(const string& ipv4_str_)
    {
        uint32_t ret = 0;
        ret = ntohl(inet_addr(ipv4_str_.c_str()));      //! yunjie: inet_addr的返回值是已经经过网络字节顺序处理了

        return ret;
    }

    static int ipv4_int_to_string(uint32_t ipv4_int_, string& out_)
    {
        struct in_addr addr;
        memset(&addr, 0, sizeof(in_addr));
        addr.s_addr = htonl(ipv4_int_);                 //! yunjie: 转换成网络字节序的大端模式
        out_ = inet_ntoa(addr);

        return 0;
    }

    static int make_socket_nonblocking(int socket_)
    {
        if (fcntl(socket_, F_SETFL, O_NONBLOCK) == -1)
        {
            return -1;
        }

        return 0;
    }
};

}

}

#endif //! _CHAOS_NETWORK_TOOL_H_
