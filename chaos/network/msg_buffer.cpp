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
        m_is_limit(false),
        m_buffer_max_limit(DEFAULT_MAX_MSG_BUFFER_SIZE)
{
}

msg_buffer_t::~msg_buffer_t()
{
    release_i();
}

msg_buffer_t::msg_buffer_t(const msg_buffer_t& rhs_)
    :
        m_heap_buffer(NULL),
        m_heap_size(0),
        m_data_offset(0),
        m_data_size(0),
        m_is_limit(false),
        m_buffer_max_limit(DEFAULT_MAX_MSG_BUFFER_SIZE)
{
    release_i();

    if (rhs_.m_buffer_sptr.is_null() && rhs_.size())
    {
        m_heap_buffer = (char*)chaos_malloc(rhs_.size());

        if (NULL == m_heap_buffer)
            return;

        memcpy(m_heap_buffer, rhs_.data(), rhs_.size());
        m_heap_size = rhs_.size();
        m_data_offset = 0;
        m_data_size = rhs_.size();
    }
    else
    {
        m_heap_buffer = rhs_.m_heap_buffer;
        m_buffer_sptr = rhs_.m_buffer_sptr;
        m_heap_size = rhs_.m_heap_size;
        m_data_offset = rhs_.m_data_offset;
        m_data_size = rhs_.m_data_size;
    }

    m_is_limit = rhs_.m_is_limit;
    m_buffer_max_limit = rhs_.m_buffer_max_limit;
}

const msg_buffer_t& msg_buffer_t::operator=(const msg_buffer_t& rhs_)
{
    release_i();

    if (rhs_.m_buffer_sptr.is_null() && rhs_.size())
    {
        m_heap_buffer = (char*)chaos_malloc(rhs_.size());

        if (NULL == m_heap_buffer)
            return *this;

        memcpy(m_heap_buffer, rhs_.data(), rhs_.size());
        m_heap_size = rhs_.size();
        m_data_offset = 0;
        m_data_size = rhs_.size();
    }
    else
    {
        m_heap_buffer = rhs_.m_heap_buffer;
        m_buffer_sptr = rhs_.m_buffer_sptr;
        m_heap_size = rhs_.m_heap_size;
        m_data_offset = rhs_.m_data_offset;
        m_data_size = rhs_.m_data_size;
    }

    m_is_limit = rhs_.m_is_limit;
    m_buffer_max_limit = rhs_.m_buffer_max_limit;

    return *this;
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

void msg_buffer_t::adjust_space_for_tail_i(uint32_t size_)
{
    if (!is_init_i())  //! yunjie: 第一次分配
    {
        if (-1 == init_buffer_i(size_))
        {
            //! yunjie: mem error
            return;
        }
    }
    else if (size_ > remain_tail_capacity())      //! yunjie: 尾部剩余的堆空间不足
    {
        //! yunjie: 判断头尾空闲内存的总和是否足够
        if (remain_head_capacity() +  remain_tail_capacity() >= size_)
        {
            //! yunjie: 将数据内存块对齐到头
            marshal_i();
        }
        else
        {
            if (expand_i(size_ + m_heap_size))
            {
                //! yunjie: 内存扩张失败，所有数据对齐到头, 尽可能让尾部留有空余
                if (remain_head_capacity())
                {
                    marshal_i();
                }
            }
        }
    }
}

void msg_buffer_t::adjust_space_for_head_i(uint32_t size_)
{
    if (size_ > remain_head_capacity())      //! yunjie: 尾部剩余的堆空间不足
    {
        //! yunjie: 判断头尾空闲内存的总和是否足够
        if (remain_head_capacity() +  remain_tail_capacity() >= size_)
        {
            //! yunjie: 将数据内存块对齐到头
            marshal_i(size_);
        }
        else
        {
            //! yunjie: 扩张内存块, 并对齐数据起始地址到size_
            if (expand_i(size_ + m_heap_size, size_))
            {
                //! yunjie: 内存扩张失败，所有数据对齐到头, 尽可能让头部留有空余
                if (remain_tail_capacity())
                {
                    marshal_i(remain_head_capacity() + remain_tail_capacity());
                }
            }
        }
    }
}

uint32_t msg_buffer_t::append(const void* data_, uint32_t size_)
{
    adjust_space_for_tail_i(size_);
    uint32_t append_size = size_ > remain_tail_capacity()
                            ? remain_tail_capacity()
                            : size_;

    append_i((char*)data_, append_size);

    check_buffer_sptr_i();

    return append_size;
}

uint32_t msg_buffer_t::append(uint32_t size_, char val_)
{
    adjust_space_for_tail_i(size_);
    uint32_t append_size = size_ > remain_tail_capacity()
                            ? remain_tail_capacity()
                            : size_;

    memset(write_ptr_i(), val_, append_size);
    m_data_size += append_size;

    check_buffer_sptr_i();

    return append_size;
}


uint32_t msg_buffer_t::prepend(const void* data_, uint32_t size_)
{
    if (!m_data_size)
    {
        return append(data_, size_);
    }

    assert(is_init_i());

    adjust_space_for_head_i(size_);

    uint32_t prepend_size = size_ > remain_head_capacity()
                            ? remain_head_capacity()
                            : size_;

    prepend_i((char*)data_, prepend_size);

    check_buffer_sptr_i();

    return prepend_size;
}

uint32_t msg_buffer_t::prepend(uint32_t size_, char val_)
{
    if (!m_data_size)
    {
        return append(size_, val_);
    }

    assert(is_init_i());

    adjust_space_for_head_i(size_);

    uint32_t prepend_size = size_ > remain_head_capacity()
                            ? remain_head_capacity()
                            : size_;
    m_data_offset -= prepend_size;
    memset(m_heap_buffer + m_data_offset, val_, prepend_size);
    m_data_size += prepend_size;

    check_buffer_sptr_i();

    return prepend_size;
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
    uint32_t remain_free_tail_space = remain_tail_capacity();
    if (0 == remain_free_tail_space)
    {
        marshal_i();

        if (0 == (remain_free_tail_space = remain_tail_capacity()))
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

    check_buffer_sptr_i();

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

uint32_t msg_buffer_t::calc_append_move_bytes(uint32_t size_)
{
    //! yunjie: 尾部剩余的堆空间不足
    if (NULL != m_heap_buffer && size_ > remain_tail_capacity())
    {
        if (remain_head_capacity() +  remain_tail_capacity() >= size_)
        {
            //! yunjie: 有效数据的marshal
            return m_data_size;
        }
        else
        {
            //! yunjie: 将会拷贝整个内存块
            return m_data_size;
        }
    }

    return 0;
}

void msg_buffer_t::release_i()
{
    if (m_buffer_sptr.is_null())
    {
        if (NULL != m_heap_buffer)
        {
            chaos_free(m_heap_buffer);
            m_heap_buffer = NULL;
        }
    }
    else
    {
        m_buffer_sptr.reset();
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

int msg_buffer_t::init_buffer_i(uint32_t size_)
{
    assert(!is_init_i());

    uint32_t real_size = size_ < MIN_MSG_BUFFER_SIZE ? MIN_MSG_BUFFER_SIZE : size_;

    uint32_t alloc_size = align_to_jesize(real_size);

    if (m_is_limit && alloc_size > m_buffer_max_limit)
    {
        alloc_size = m_buffer_max_limit;
    }

    m_heap_buffer = (char*)chaos_malloc(alloc_size);
    if (NULL == m_heap_buffer)
    {
        return -1;
    }

    m_heap_size = alloc_size;

    return 0;
}

int msg_buffer_t::expand_i(uint32_t size_, uint32_t copy_offset_)
{
    assert(size_ > m_heap_size);
    assert(size_ >= copy_offset_);

    if (m_is_limit && m_heap_size >= m_buffer_max_limit)
    {
        return 1;
    }

    //! yunjie: 对齐到jemalloc的内存大小
    uint32_t alloc_size = align_to_jesize(size_);

    if (m_is_limit && alloc_size > m_buffer_max_limit)
    {
        alloc_size = m_buffer_max_limit;
    }

    //! yunjie: 只是为了去除强转警告
    void* tmp_ptr = m_heap_buffer;

    if (m_heap_size >= jemalloc_min_in_place_expandable
        && !copy_offset_        //! yunjie: copy_offset > 0说明头部空间不足, 不能ExpandInPalce
        && chaos_rallocm(&tmp_ptr, NULL, alloc_size, 0, ALLOCM_NO_MOVE) == ALLOCM_SUCCESS)
    {
        m_heap_size = alloc_size;

        return 0;
    }

    char* new_addr = (char*)chaos_malloc(alloc_size);
    if (NULL == new_addr)
    {
        return -1;
    }

    memcpy(new_addr + copy_offset_, data(), size());

    if (m_buffer_sptr.is_null())
    {
        chaos_free(m_heap_buffer);
    }

    m_heap_buffer = new_addr;
    m_heap_size = alloc_size;
    m_data_offset = copy_offset_;

    return 0;
}

void msg_buffer_t::append_i(const char* src_, uint32_t size_)
{
    memcpy(write_ptr_i(), src_, size_);
    m_data_size += size_;
}

void msg_buffer_t::prepend_i(const char* src_, uint32_t size_)
{
    m_data_offset -= size_;
    memcpy(m_heap_buffer + m_data_offset, src_, size_);
    m_data_size += size_;
}

void msg_buffer_t::marshal_i(uint32_t offset_)
{
    assert(m_data_size);

    memmove(m_heap_buffer + offset_, data(), size());
    m_data_offset = offset_;
}

void msg_buffer_t::check_buffer_sptr_i()
{
    if (size() >= MAX_COPY_SIZE)
    {
        m_buffer_sptr = m_heap_buffer;
    }
}

}

}
