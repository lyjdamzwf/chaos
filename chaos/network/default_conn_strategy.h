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
    default_conn_strategy_t()
        :
            m_header_readed_bytes(0),
            m_is_split(false),
            m_body_readed_bytes(0)
    {
        memset(m_packet_header_buffer, 0, sizeof(m_packet_header_buffer));
    }

    virtual ~default_conn_strategy_t()
    {
        clear();
    }

protected:
    virtual void on_read_complete(buffer_list_t& buffer_)
    {
        LOGTRACE((CONNECTION_MODULE, "default_conn_strategy_t::on_read_complete arg-[readable_size:%d]", buffer_.size()));
        parse_packet(buffer_);
    }

    virtual void on_write_complete(uint32_t transferred_size_)
    {
        LOGTRACE((CONNECTION_MODULE, "default_conn_strategy_t::on_write_complete arg-[transferred_size:%d]", transferred_size_));
    }

    int parse_packet(buffer_list_t& buffer_)
    {
        LOGTRACE((CONNECTION_MODULE, "default_conn_strategy_t::parse_packet arg-[readable_size:%d] begin", buffer_.size()));

        while (buffer_.size())
        {
            uint32_t header_remain_bytes = HEADER_SIZE - m_header_readed_bytes;

            //! yunjie: 包头还没读完整
            if (header_remain_bytes > 0)
            {
                uint32_t header_copy_bytes = (header_remain_bytes > buffer_.size() ? buffer_.size() : header_remain_bytes);
                memcpy(&m_packet_header_buffer[m_header_readed_bytes], buffer_.data(), header_copy_bytes);
                buffer_.drain_size(header_copy_bytes);
                m_header_readed_bytes += header_copy_bytes;
            }

            //! yunjie: 包头读完, 开始处理包体
            if (HEADER_SIZE == m_header_readed_bytes)
            {
                packet_header_t& header = *(packet_header_t*)m_packet_header_buffer;
                uint32_t data_len = header.data_len;

                if (!data_len)
                {
                    handle_packet(header, NULL, 0);
                    clear();
                    continue;
                }

                //! yunjie: 包体处理
                if (buffer_.size())
                {
                    uint32_t body_remain_bytes = data_len - m_body_readed_bytes;

                    //! yunjie: 当前的数据包是否被分割处理
                    if (!m_is_split)
                    {
                        if (buffer_.size() >= data_len)
                        {
                            //! yunjie: 整个数据包都在同一块buffer, 零拷贝给上层 
                            handle_packet(header, buffer_.data(), data_len);
                            buffer_.drain_size(data_len);
                            clear();
                            continue;
                        }
                        else if (buffer_.is_full())
                        {
                            //! yunjie: buffer没有可用空间了, 并且数据包仍不完整
                            if (m_packet_body_buffer.capacity() < data_len)
                            {
                                m_packet_body_buffer.reserve(data_len);
                            }

                            /**
                             * 不需要检查是否reserve成功, 失败会抛出length_error exception
                            if (m_packet_body_buffer.capacity() < data_len)
                            {
                                LOGTRACE((CONNECTION_MODULE, "default_conn_strategy_t::parse_packet new body buffer failed"));
                                return -1;
                            }
                            */

                            uint32_t body_copy_bytes = buffer_.size();
                            memcpy(&m_packet_body_buffer[m_body_readed_bytes], buffer_.data(), body_copy_bytes);
                            buffer_.drain_size(body_copy_bytes);
                            m_body_readed_bytes += body_copy_bytes;
                            m_is_split = true;
                        }
                        else
                        {
                            //! yunjie: 继续等待足够的数据包
                            return 0;
                        }
                    }
                    else
                    {
                        uint32_t body_copy_bytes = (body_remain_bytes > buffer_.size() ? buffer_.size() : body_remain_bytes);
                        memcpy(&m_packet_body_buffer[m_body_readed_bytes], buffer_.data(), body_copy_bytes);
                        buffer_.drain_size(body_copy_bytes);
                        m_body_readed_bytes += body_copy_bytes;

                        if (data_len == m_body_readed_bytes)
                        {
                            handle_packet(header, &m_packet_body_buffer[0], data_len);
                            clear();
                            continue;
                        }
                    }
                }
            }
        }

        LOGTRACE((CONNECTION_MODULE, "default_conn_strategy_t::parse_packet arg-[readable_size:%d] end", buffer_.size()));
        return 0;
    }

    virtual void handle_packet(const packet_header_t& packet_header_, const char* data_ptr_, uint32_t data_size_)
    {
    }

    void clear()
    {
        memset(m_packet_header_buffer, 0, sizeof(m_packet_header_buffer));
        m_header_readed_bytes = 0;
        m_is_split = false;
        if (m_packet_body_buffer.capacity() > (16 * 1024))
        {
            m_packet_body_buffer.resize(16 * 1024, 0);
        }
        m_body_readed_bytes = 0;
    }

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
