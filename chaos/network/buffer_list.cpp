/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

/*!
 *  @file           buffer_list.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.6.23
 *  @brief          buffer list
 *  @last changed
 *
 */

#include <chaos/network/buffer_list.h>

namespace chaos
{

namespace network
{

buffer_list_t::buffer_list_t()
    :
        m_buffer_list(1),
        m_read_it(m_buffer_list.begin()),
        m_write_it(m_buffer_list.begin()),
        m_max_move_bytes(DEFAULT_MAX_MOVE_BYTES),
        m_buffer_max_limit(DEFAULT_MAX_MSG_BUFFER_SIZE),
        m_the_biggest_buffer_size(0),
        m_the_biggest_list(0)
{
}

void buffer_list_t::set_buffer_max_limit(uint32_t size_limit_)
{
    m_buffer_max_limit = size_limit_;

    for (
            iterator_t it = m_buffer_list.begin();
            it != m_buffer_list.end();
            ++it
        )
    {
        it->set_buffer_max_limit(size_limit_);
    }
}

int buffer_list_t::append(
                            const char* data_,
                            uint32_t size_
                        )
{
    const char* data = data_;
    uint32_t size = size_;
    uint32_t append_ret = 0;

    while (size)
    {
        uint32_t remain_capacity = m_write_it->remain_tail_capacity();

        //! yunjie: 查看需要移动的内存是否过大, 如果是并且有
        //          剩余空间, 那么就只拷贝一部分数据
        if (
            m_write_it->calc_append_move_bytes(size) > m_max_move_bytes
            && remain_capacity
            )
        {
            //! yunjie: 将要append的数据分割成两块
            //! yunjie: 将前面一部分append上最后一个buffer
            append_ret = m_write_it->append(data, remain_capacity);
            data += append_ret;
            size -= append_ret;
        }
        else
        {
            append_ret = m_write_it->append(data, size);
            data += append_ret;
            size -= append_ret;
        }

        if (size)
        {
            //! yunjie: 到这里说明还有数据没有拷贝完, buffer可能
            //!         由于种情况无法append, 需要添加新的buffer
            msg_buffer_t new_buffer;
            new_buffer.set_buffer_max_limit(m_buffer_max_limit);
            uint32_t last_buf_size = m_write_it->capacity();

            //! yunjie: 如果数据比上一块buffer小, 就让new_buffer
            //          继承上一块buffer的大小, 否则接下来append
            //          会扩张到数据的大小
            if (size < last_buf_size)
            {
                new_buffer.reserve(last_buf_size);
            }
            append_ret = new_buffer.append(data, size);
            data += append_ret;
            size -= append_ret;

            //! yunjie: 加入到buffer list中去, 并将write iterator
            //!         指向新的buffer
            m_buffer_list.push_back(new_buffer);
            ++m_write_it;
        }
    }

    //! yunjie: 统计buffer的状态
#if BUF_STAT
    for (
            iterator_t it = m_buffer_list.begin();
            it != m_buffer_list.end();
            ++it
        )
    {
        m_the_biggest_buffer_size = it->capacity() > m_the_biggest_buffer_size
            ? it->capacity()
            : m_the_biggest_buffer_size;
    }

    m_the_biggest_list = m_buffer_list.size() > m_the_biggest_list
            ? m_buffer_list.size()
            : m_the_biggest_list;
#endif

    return 0;
}

int buffer_list_t::recv_to_buffer(fd_t fd_, int& recv_ret_)
{
    int ret = 0;
    if (-1 == (ret = m_write_it->recv_to_buffer(fd_, recv_ret_)))
    {
        //! yunjie: buffer中没有任何空间可使用
        //！        添加新的buffer到list中

        msg_buffer_t new_buffer;
        new_buffer.set_buffer_max_limit(m_buffer_max_limit);
        uint32_t last_buf_size = m_write_it->capacity();
        new_buffer.reserve(last_buf_size);

        //! yunjie: 将socket数据读到新的buffer中
        if (-1 == (ret = new_buffer.recv_to_buffer(fd_, recv_ret_)))
        {
            //! yunjie: 内存分配错误
            return ret;
        }

        //! yunjie: 加入到buffer list中去, 并将write iterator
        //!         指向新的buffer
        m_buffer_list.push_back(new_buffer);
        ++m_write_it;
    }

    //! yunjie: 统计buffer的状态
#if BUF_STAT
    for (
            iterator_t it = m_buffer_list.begin();
            it != m_buffer_list.end();
            ++it
        )
    {
        m_the_biggest_buffer_size = it->capacity() > m_the_biggest_buffer_size
            ? it->capacity()
            : m_the_biggest_buffer_size;
    }

    m_the_biggest_list = m_buffer_list.size() > m_the_biggest_list
            ? m_buffer_list.size()
            : m_the_biggest_list;
#endif

    return ret;
}

void buffer_list_t::set_max_move_bytes(uint32_t bytes_)
{
    m_max_move_bytes = bytes_;
}

uint32_t buffer_list_t::drain_size(uint32_t size_)
{
    uint32_t ret = m_read_it->drain_size(size_);
    if (0 == m_read_it->size() && m_read_it != m_write_it)
    {
        iterator_t tmp_it = m_read_it;
        ++m_read_it;
        tmp_it->release();
        m_buffer_list.erase(tmp_it);
    }

    return ret;
}

void buffer_list_t::clear()
{
    for (
            iterator_t it = m_buffer_list.begin();
            it != m_buffer_list.end();
            ++it
        )
    {
        it->release();
    }

    m_buffer_list.clear();
}

string buffer_list_t::format_buffer_list_info() const
{
    char info[65535] = {0};
    sprintf(info,
            "----------------------- buffer list info begin -----------------------\n"
            "biggest buf size:%u biggest list :%u\n\n"
            "cur info -\n"
            ,
            m_the_biggest_buffer_size,
            m_the_biggest_list
           );
    for (
            const_iterator_t it = m_buffer_list.begin();
            it != m_buffer_list.end();
            ++it
        )
    {
        sprintf(info + strlen(info),
                "buf size:%u data size:%u\n",
                it->capacity(), it->size());
    }

    sprintf(info + strlen(info), "----------------------- buffer list info end -----------------------\n\n");
    string ret(info);

    return ret;
}

}

}
