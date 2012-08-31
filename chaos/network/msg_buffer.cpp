/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

/*!
 *  @file           msg_buffer.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.16
 *  @brief          msg buffer
 *  @last changed   2012.6.21
 *
 */

#include <iostream>
#include <chaos/network/msg_buffer.h>

namespace chaos
{

namespace network
{

msg_buffer_t::msg_buffer_t()
    :
        m_heap_buffer(NULL),
        m_heap_size(0),
        m_data_offset(0),
        m_data_size(0),
        m_buffer_max_limit(DEFAULT_MAX_MSG_BUFFER_SIZE)
{
}

msg_buffer_t::~msg_buffer_t()
{
}

int msg_buffer_t::reserve(uint32_t size_)
{
    int ret = 0;
    if (!is_init_i())  //! yunjie: 第一次分配
    {
        ret = init_buffer_i(size_);
    }
    else
    {
        ret = expand_i(size_);
    }

    return ret;
}

uint32_t msg_buffer_t::append(const void* data_, uint32_t size_)
{
    uint32_t ret = 0;

    if (!is_init_i())  //! yunjie: 第一次分配
    {
        if (-1 == init_buffer_i(size_))
        {
            //! yunjie: mem error
            return 0;
        }
    }
    else if (size_ > remain_free_tail_space_i())      //! yunjie: 尾部剩余的堆空间不足
    {
        //! yunjie: 判断头尾空闲内存的总和是否足够
        if (remain_free_head_space_i() +  remain_free_tail_space_i() >= size_)
        {
            //! yunjie: 将数据内存块对齐到头
            marshal_i();
        }
        else
        {
            if (-1 == expand_i(size_ + m_heap_size))
            {
                //! yunjie: mem error or param error
                return 0;
            }
        }
    }

    ret = append_i((char*)data_, size_);

    return ret;
}

int msg_buffer_t::recv_to_buffer(fd_t fd_, int& recv_ret_)
{
    if (!is_init_i())  //! yunjie: 第一次分配
    {
        if (-1 == init_buffer_i(MIN_MSG_BUFFER_SIZE))
        {
            //! yunjie: mem error
            return -1;
        }
    }

    //! yunjie: 被读取了一部分, 如果尾部没有空间就进行marshal
    uint32_t remain_free_tail_space = remain_free_tail_space_i();
    if (0 == remain_free_tail_space)
    {
        marshal_i();

        if (0 == (remain_free_tail_space = remain_free_tail_space_i()))
        {
            return -1;
        }
    }

    recv_ret_ = ::recv(fd_, write_ptr_i(), remain_free_tail_space, 0);

    if (recv_ret_ < 0)
    {
        return 0;
    }

    m_data_size += recv_ret_;

    if ((uint32_t)recv_ret_ == remain_free_tail_space)
    {
        //! yunjie: marshal and expand
        marshal_i();
        if (-1 == expand_i(m_heap_size << 1))
        {
            //! yunjie: mem error or param error
        }
    }

    return 0;
}

uint32_t msg_buffer_t::drain_size(uint32_t size_)
{
    uint32_t ret = 0;

    if (size_ >= m_data_size)
    {
        ret = m_data_size;
        m_data_offset = 0;
        m_data_size = 0;
    }
    else
    {
        ret = size_;
        m_data_offset += size_;
        m_data_size -= size_;
    }

    return ret;
}

uint32_t msg_buffer_t::calc_move_bytes(uint32_t size_)
{
    if (NULL != m_heap_buffer && size_ > remain_free_tail_space_i())      //! yunjie: 尾部剩余的堆空间不足
    {
        if (remain_free_head_space_i() +  remain_free_tail_space_i() >= size_)
        {
            //! yunjie: 有效数据的marshal
            return m_data_size;
        }
        else
        {
            //! yunjie: 将会拷贝整个内存块
            return m_heap_size;
        }
    }

    return 0;
}

void msg_buffer_t::clear()
{
    if (NULL != m_heap_buffer)
    {
        free(m_heap_buffer);
        m_heap_buffer = NULL;
    }

    m_heap_size = 0;
    m_data_offset = 0;
    m_data_size = 0;
}

void msg_buffer_t::loop_2_printf_all()
{
    printf("------------ loop_2_printf_all ------------\n");
    printf("buffer:%p buffer size:%d data offset:%d data size:%d\n",
            m_heap_buffer,
            m_heap_size,
            m_data_offset,
            m_data_size
            );
    if (m_heap_buffer == NULL)
    {
        return;
    }

    for (size_t i = 0; i < m_heap_size; i++)
    {
        std::cout << i << ":" << (int)m_heap_buffer[i] << std::endl;
    }
    printf("------------ loop_2_printf_all ------------\n\n");
}

void msg_buffer_t::loop_2_printf_data()
{
    printf("------------ loop_2_printf_data ------------\n");
    printf("buffer:%p buffer size:%d data offset:%d data size:%d\n",
            m_heap_buffer,
            m_heap_size,
            m_data_offset,
            m_data_size
            );

    if (m_heap_buffer == NULL)
    {
        return;
    }

    for (size_t i = 0; i < m_data_size; i++)
    {
        std::cout << i << ":" << (int)(m_heap_buffer + m_data_offset)[i] << std::endl;
    }

    printf("------------ loop_2_printf_data ------------\n\n");
}


bool msg_buffer_t::is_init_i() const
{
    return (NULL != m_heap_buffer);
}

int msg_buffer_t::init_buffer_i(uint32_t size_)
{
    if (is_init_i())
    {
        return 1;
    }

    uint32_t alloc_size = ((size_ > MIN_MSG_BUFFER_SIZE) ? align_num_i(size_, MIN_MSG_BUFFER_SIZE) : MIN_MSG_BUFFER_SIZE);

    if (alloc_size > m_buffer_max_limit)
    {
        alloc_size = m_buffer_max_limit;
    }

    m_heap_buffer = (char*)malloc(alloc_size);
    if (NULL == m_heap_buffer)
    {
        //! yunjie: mem error
        return -1;
    }

    m_heap_size = alloc_size;

    return 0;
}

int msg_buffer_t::expand_i(uint32_t size_)
{
    if (size_ <= m_heap_size)
    {
        return -1;
    }

    uint32_t alloc_size = align_num_i(size_, MIN_MSG_BUFFER_SIZE);

    if (alloc_size > m_buffer_max_limit)
    {
        alloc_size = m_buffer_max_limit;
    }

    //! yunjie: 重新分配新内存
    char* new_addr = (char*)realloc(m_heap_buffer, alloc_size);
    if (NULL == new_addr)
    {
        //! yunjie: mem error
        return -1;
    }

    m_heap_buffer = new_addr;
    m_heap_size = alloc_size;

    return 0;
}

uint32_t msg_buffer_t::align_num_i(uint32_t num_, uint32_t base_)
{
    uint32_t remainder = num_ % base_;
    uint32_t ret = num_ / base_ * base_;
    ret += remainder ? base_ : 0;

    return ret;
}

uint32_t msg_buffer_t::append_i(const char* src_, uint32_t size_)
{
    uint32_t copy_bytes = size_ > remain_free_tail_space_i()
                                ? remain_free_tail_space_i()
                                : size_;
    memcpy(write_ptr_i(), src_, copy_bytes );
    m_data_size += copy_bytes ;

    return copy_bytes;
}

uint32_t msg_buffer_t::remain_free_head_space_i() const
{
    return m_data_offset;
}

uint32_t msg_buffer_t::remain_free_tail_space_i() const
{
    return m_heap_size - m_data_offset - m_data_size;
}


void msg_buffer_t::marshal_i()
{
    if (0 == m_data_offset)
    {
        return;
    }

    memmove(m_heap_buffer, data(), m_data_size);
    m_data_offset = 0;
}

}

}
