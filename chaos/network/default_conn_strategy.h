/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_DEFAULT_CONN_STRATEGY_H_
#define _CHAOS_DEFAULT_CONN_STRATEGY_H_

/*!
 *  @file           default_conn_strategy.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.17
 *  @brief          default conn strategy
 *  @last changed
 *
 */

#include <chaos/network/connection.h>

namespace chaos
{

namespace network
{

typedef uint16_t                header_cmd_t;
typedef uint16_t                header_ext_t;
typedef uint32_t                header_datalen_t;

#define HEADER_SIZE     (sizeof(header_cmd_t) + sizeof(header_ext_t) + sizeof(header_datalen_t))

struct packet_header_t
{
    packet_header_t()
        :
            cmd(0),
            ext(0),
            data_len(0)
    {
    }

    header_cmd_t            cmd;
    header_ext_t            ext;
    header_datalen_t        data_len;
};

class default_conn_strategy_t : public connection_t
{
public:
    default_conn_strategy_t();
    virtual ~default_conn_strategy_t();

protected:
    void on_read_complete(buffer_list_t& buffer_);

    void on_write_complete(uint32_t transferred_size_);

    int parse_packet(buffer_list_t& buffer_);

    virtual void handle_packet(
                                const packet_header_t&  packet_header_,
                                const char*             data_ptr_,
                                uint32_t                data_size_
                               ) = 0;

    void clear();

protected:
    char                            m_packet_header_buffer[HEADER_SIZE];
    uint16_t                        m_header_readed_bytes;

    //! yunjie: 数据包是否被分割在两个buffer中
    bool                            m_is_split;
    vector<char>                    m_packet_body_buffer;
    uint32_t                        m_body_readed_bytes;
};


}

}


#endif //! _CHAOS_DEFAULT_CONN_STRATEGY_H_
