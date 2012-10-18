/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_MSG_BUFFER_H_
#define _CHAOS_MSG_BUFFER_H_

/*!
 *  @file           msg_buffer.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.16
 *  @brief          msg buffer
 *  @last changed   2012.6.21
 *
 */

#include <stdint.h>
#include <assert.h>
#include <string>

#include <chaos/utility/utility_inc.h>
#include <chaos/task_service/task_service_inc.h>

#include <chaos/network/network_tool.h>

namespace chaos
{

namespace network
{

using namespace utility;
using namespace task_service;

#define MIN_MSG_BUFFER_SIZE     1024
#define DEFAULT_MAX_MSG_BUFFER_SIZE     (16*1024)
//! #define MIN_MSG_BUFFER_SIZE     8
//! #define DEFAULT_MAX_MSG_BUFFER_SIZE     20

using namespace std;

class msg_buffer_t : public memory_holder_t
{
public:
    msg_buffer_t();
    ~msg_buffer_t();

    msg_buffer_t(const msg_buffer_t& rhs_);
    const msg_buffer_t& operator=(const msg_buffer_t& rhs_);

    void clone(msg_buffer_t& obj_);

    //! yunjie: 返回有效数据块的指针
    inline const char* data() const
    {
        return m_heap_buffer + m_data_offset;
    }

    //! yunjie: 返回内存块指针
    inline const char* space() const
    {
        return m_heap_buffer;
    }

    //! yunjie: 返回有效数据块的大小
    inline uint32_t size() const
    {
        return m_data_size;
    }

    //! yunjie: 返回内存块总大小
    inline uint32_t capacity() const
    {
        return m_heap_size;
    }

    //! yunjie: 返回头部剩余空间
    inline uint32_t remain_head_capacity() const
    {
        return m_data_offset;
    }

    //! yunjie: 返回尾部剩余空间
    inline uint32_t remain_tail_capacity() const
    {
        return m_heap_size - m_data_offset - m_data_size;
    }

    //! yunjie: 是否已经没有任何可用空间了
    inline bool is_full() const
    {
        return (0 == remain_head_capacity() + remain_tail_capacity());
    }

    inline void set_no_limit()
    {
        m_is_limit = false;
    }

    inline bool set_buffer_max_limit(uint32_t size_limit_)
    {
        if (size_limit_ < MIN_MSG_BUFFER_SIZE || size_limit_ < m_heap_size)
        {
            return false;
        }

        m_buffer_max_limit = size_limit_;
        m_is_limit = true;

        return true;
    }

    //! yunjie: -1表示分配内存失败, 0表示成功, 但
    //!         不一定能分配到指定长度, 之后请调用
    //!         remain_capacity()查看
    int reserve(uint32_t size_);

    //! yunjie: 返回真正append的字节数
    uint32_t append(const void* data_, uint32_t size_);
    uint32_t append(uint32_t size_, char val_);

    //! yunjie: 返回真正prepend的字节数
    uint32_t prepend(const void* data_, uint32_t size_);
    uint32_t prepend(uint32_t size_, char val_);

    //! yunjie: 返回-1表示buffer已经没有任何空间可以使用
    int recv_to_buffer(fd_t fd_, int& recv_ret_);

    //! yunjie: 返回实际删除的字节数
    uint32_t drain_size(uint32_t size_);

    //! yunjie: 计算需要移动的数据字节数
    uint32_t calc_move_bytes(uint32_t size_);

    //! yunjie: 重置数据变量并释放内存块
    void release();

    //! yunjie: 危险操作, 会重置指针, 但不会释放
    //          多线程buffer swap时需要该功能
    void reset();

    void loop_2_printf_all();
    void loop_2_printf_data();

private:
    inline bool is_init_i() const
    {
        return (NULL != m_heap_buffer);
    }

    int init_buffer_i(uint32_t size_);

    void adjust_space_for_tail_i(uint32_t size_);
    void adjust_space_for_head_i(uint32_t size_);

    int expand_i(uint32_t size_, uint32_t copy_offset_ = 0);

    void append_i(const char* src_, uint32_t size_);

    void prepend_i(const char* src_, uint32_t size_);

    inline char* write_ptr_i() const
    {
        return m_heap_buffer + m_data_offset + m_data_size;
    }

    void marshal_i(uint32_t offset_ = 0);

private:
    char*                       m_heap_buffer;
    uint32_t                    m_heap_size;
	uint32_t                    m_data_offset;      //! yunjie: 数据的初始地址偏移
	uint32_t                    m_data_size;        //! yunjie: 数据的大小
    bool                        m_is_limit;         //! yunjie: 是否限制内存块最大长度
    uint32_t                    m_buffer_max_limit;
};

}

}

#endif //! _CHAOS_MSG_BUFFER_H_
