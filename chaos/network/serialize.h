/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_STERAM_H_
#define _CHAOS_STERAM_H_

/*!
 *  @file           stream.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.9.11
 *  @brief          stream.h
 *  @last changed
 *
 */

#include <stdint.h>
#include <stdio.h>

#include <string>

#include <chaos/utility/utility_inc.h>

#include <chaos/network/msg_buffer.h>

namespace chaos
{

namespace network
{

using namespace std;

using namespace chaos::utility;

//! yunjie: 头部预留内存块大小
#define HEAD_SIZE           12

class serialize_t : public msg_buffer_t
{
public:
	serialize_t()
        :
            m_reserved_head_bytes(0)
    {
    }

	serialize_t(const void* data_, uint32_t size_)
        :
            m_reserved_head_bytes(0)
    {
        append((const char*)data_, size_);
    }

    ~serialize_t()
    {
    }

    serialize_t(const serialize_t& rhs_)
        :
            msg_buffer_t(rhs_)
    {
        m_reserved_head_bytes = rhs_.m_reserved_head_bytes;
    }

    const serialize_t& operator=(const serialize_t& rhs_)
    {
        msg_buffer_t::operator= (rhs_);
        m_reserved_head_bytes = rhs_.m_reserved_head_bytes;

        return *this;
    }

	uint32_t size() const { return msg_buffer_t::size() - m_reserved_head_bytes; }
	const char* data() const { return msg_buffer_t::data() + m_reserved_head_bytes; }

    void reserve(uint32_t size_) { if (size_ > msg_buffer_t::capacity()) msg_buffer_t::reserve(size_); }

	uint32_t append(const char* buf_, uint32_t len_)
	{
        if (NULL == msg_buffer_t::space())
        {
            m_reserved_head_bytes = msg_buffer_t::append(HEAD_SIZE, 0);
        }

		return msg_buffer_t::append(buf_, len_);
	}

    uint32_t append(uint32_t size_, char val_)
    {
        if (NULL == msg_buffer_t::space())
        {
            m_reserved_head_bytes = msg_buffer_t::append(HEAD_SIZE, 0);
        }

        return msg_buffer_t::append(size_, val_);
    }

	uint32_t prepend(const char* buf_, uint32_t len_)
	{
        if (!m_reserved_head_bytes)
        {
            //! yunjie: 没有为头部预留的内存块, 这时prepend有可能会移动数据内存块
            return msg_buffer_t::prepend(buf_, len_);
        }

        //! yunjie: 头部预留内存块有剩余
        msg_buffer_t::drain_size(m_reserved_head_bytes);
        uint32_t prepend_ret = msg_buffer_t::prepend(buf_, len_);

        m_reserved_head_bytes = (m_reserved_head_bytes > len_) ? m_reserved_head_bytes - len_ : 0;

        if (m_reserved_head_bytes)
        {
            msg_buffer_t::prepend(m_reserved_head_bytes, 0);
        }

        return prepend_ret;
    }

	uint32_t prepend(uint32_t size_, char val_)
	{
        if (!m_reserved_head_bytes)
        {
            //! yunjie: 没有为头部预留的内存块, 这时prepend有可能会移动数据内存块
            return msg_buffer_t::prepend(size_, val_);
        }

        //! yunjie: 头部预留内存块有剩余
        msg_buffer_t::drain_size(m_reserved_head_bytes);
        uint32_t prepend_ret = msg_buffer_t::prepend(size_, val_);

        m_reserved_head_bytes = (m_reserved_head_bytes > size_) ? m_reserved_head_bytes - size_: 0;

        if (m_reserved_head_bytes)
        {
            msg_buffer_t::prepend(m_reserved_head_bytes, 0);
        }

        return prepend_ret;
    }

    template<typename T>
	serialize_t& operator<<(const T& v)
	{
		append((char *)&v, sizeof(T));
		return *this;
	}

	template<typename T>
	serialize_t& operator<<(const std::vector<T>& v)
	{
		uint32_t n = static_cast<uint32_t>(v.size());
		(*this) << n;
		append((char *)&v[0], sizeof(T) * n);
		return *this;
	}

    serialize_t& operator<<(const std::string& v)
	{
		(*this) << static_cast<uint32_t>(v.length());
        append(v.data(), v.length());

		return *this;
	}

	serialize_t& operator<<(const char* v)
	{
		if (v == NULL)
		{
			(*this) << static_cast<uint32_t>(0);
			return *this;
		}
		uint32_t len = static_cast<uint32_t>(strlen(v));
		(*this) << len;
        append(v, len);

		return *this;
	}

    void dump() const
    {
        printf("\n\n------------------ serialize dump ------------------\n");
        for (uint32_t i = 0; i < size(); ++i)
        {
            printf("%d: %p - %d\n", i, &(data()[i]), data()[i]);
        }
        printf("data():%p, size():%d, remain_head_bytes:%d\n", data(), size(), m_reserved_head_bytes);
    }

private:
    uint32_t                        m_reserved_head_bytes;
};

}

}

#endif //! _CHAOS_STERAM_H_
