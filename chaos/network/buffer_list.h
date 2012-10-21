/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_BUFFER_LIST_H_
#define _CHAOS_BUFFER_LIST_H_

/*!
 *  @file           buffer_list.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.6.23
 *  @brief          buffer list
 *  @last changed
 *
 */

#include <list>
using namespace std;

#include <chaos/network/msg_buffer.h>

#ifndef BUF_STAT
#define BUF_STAT 1
#endif

namespace chaos
{

namespace network
{

#define DEFAULT_MAX_MOVE_BYTES      (16*1024)

class buffer_list_t
{
public:
    typedef list<msg_buffer_t>::iterator                iterator_t;
    typedef list<msg_buffer_t>::const_iterator          const_iterator_t;

public:
    buffer_list_t();

    //! yunjie: 当前read iterator指向的buffer数据地址
    const char* data() const
    {
        return m_read_it->data();
    }

    //! yunjie: 当前read iterator指向的buffer的数据字节数
    uint32_t size() const
    {
        return m_read_it->size();
    }

    //! yunjie: 当前read iterator指向的buffer的剩余可使
    //！        用空间字节数
    uint32_t remain_tail_capacity() const
    {
        return m_read_it->remain_tail_capacity();
    }

    //! yunjie: 当前read iterator指向的buffer是否已经
    //！        没有任何可用空间
    bool is_full() const
    {
        return m_read_it->is_full();
    }

    void set_buffer_max_limit(uint32_t size_limit_);

    int append(
                const char* data_,
                uint32_t size_
                );
    int recv_to_buffer(fd_t fd_, int& recv_ret_);
    void set_max_move_bytes(uint32_t bytes_);
    uint32_t drain_size(uint32_t size_);
    void clear();

    string format_buffer_list_info() const;

private:
    list<msg_buffer_t>                  m_buffer_list;
    iterator_t                          m_read_it;
    iterator_t                          m_write_it;
    uint32_t                            m_max_move_bytes;
    uint32_t                            m_buffer_max_limit;

    //! yunjie: 统计信息
    uint32_t                            m_the_biggest_buffer_size;
    uint32_t                            m_the_biggest_list;
};

}

}

#endif //! _CHAOS_BUFFER_LIST_H_
