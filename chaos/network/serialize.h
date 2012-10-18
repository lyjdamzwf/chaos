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
using namespace std;

#include <chaos/utility/utility_inc.h>

#include <chaos/network/msg_buffer.h>

namespace chaos
{

namespace network
{

using namespace chaos::utility;

#define HEAD_SIZE           12

class serialize_t : public memory_holder_t
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
    {
        m_buffer = rhs_.m_buffer;
        m_reserved_head_bytes = rhs_.m_reserved_head_bytes;
    }

    const serialize_t& operator=(const serialize_t& rhs_)
    {
        m_buffer = rhs_.m_buffer;
        m_reserved_head_bytes = rhs_.m_reserved_head_bytes;

        return *this;
    }

    void clone(serialize_t& obj_)
    {
        m_buffer.clone(obj_.m_buffer);
        obj_.m_reserved_head_bytes = m_reserved_head_bytes;
    }

	uint32_t size() const { return m_buffer.size() - m_reserved_head_bytes; }
	const char* data() const { return m_buffer.data() + m_reserved_head_bytes; }

    void reserve(uint32_t size_) { if (size_ > m_buffer.capacity()) m_buffer.reserve(size_); }

    //! yunjie: 重置数据变量并释放内存块
	void release()
    {
        m_buffer.release();
        m_reserved_head_bytes = 0;
    }

    //! yunjie: 危险操作, 会重置指针, 但不会释放
    //          多线程buffer swap时需要该功能
    void reset()
    {
        m_buffer.reset();
        m_reserved_head_bytes = 0;
    }

	uint32_t append(const char* buf_, uint32_t len_)
	{
        if (NULL == m_buffer.space())
        {
            m_reserved_head_bytes = m_buffer.append(HEAD_SIZE, 0);
        }

		return m_buffer.append(buf_, len_);
	}

    uint32_t append(uint32_t size_, char val_)
    {
        if (NULL == m_buffer.space())
        {
            m_reserved_head_bytes = m_buffer.append(HEAD_SIZE, 0);
        }

        return m_buffer.append(size_, val_);
    }

	uint32_t prepend(const char* buf_, uint32_t len_)
	{
        if (!m_reserved_head_bytes)
        {
            return m_buffer.prepend(buf_, len_);
        }

        m_buffer.drain_size(m_reserved_head_bytes);
        uint32_t prepend_ret = m_buffer.prepend(buf_, len_);

        m_reserved_head_bytes = (m_reserved_head_bytes > len_) ? m_reserved_head_bytes - len_ : 0;

        if (m_reserved_head_bytes)
        {
            m_buffer.prepend(m_reserved_head_bytes, 0);
        }

        return prepend_ret;
    }

	uint32_t prepend(uint32_t size_, char val_)
	{
        if (!m_reserved_head_bytes)
        {
            return m_buffer.prepend(size_, val_);
        }

        m_buffer.drain_size(m_reserved_head_bytes);
        uint32_t prepend_ret = m_buffer.prepend(size_, val_);

        m_reserved_head_bytes = (m_reserved_head_bytes > size_) ? m_reserved_head_bytes - size_: 0;

        if (m_reserved_head_bytes)
        {
            m_buffer.prepend(m_reserved_head_bytes, 0);
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
    msg_buffer_t                    m_buffer;
    uint32_t                        m_reserved_head_bytes;
};

}

}

#endif //! _CHAOS_STERAM_H_
