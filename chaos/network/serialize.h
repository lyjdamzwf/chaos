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

#include <chaos/network/msg_buffer.h>

namespace chaos
{

namespace network
{

#define HEAD_SIZE           8

class serialize_t
{
public:
	serialize_t()
    {
        clear_i();
    }

	serialize_t(const void* data_, uint32_t size_)
    {
        clear_i();
        append((const char*)data_, size_);
    }

    ~serialize_t()
    {
    }

    serialize_t(const serialize_t& rhs_)
    {
        m_buffer = rhs_.m_buffer;
        m_remain_head_bytes = rhs_.m_remain_head_bytes;
    }

    const serialize_t& operator=(const serialize_t& rhs_)
    {
        m_buffer = rhs_.m_buffer;
        m_remain_head_bytes = rhs_.m_remain_head_bytes;

        return *this;
    }

	uint32_t size() const { return m_buffer.size() - m_remain_head_bytes; }
	const char* data() const { return m_buffer.data() + m_remain_head_bytes; }

    void reserve(uint32_t size_) { if (size_ > m_buffer.capacity()) m_buffer.reserve(size_); }

	void clear() { clear_i(); }

	uint32_t append(const char* buf_, uint32_t len_)
	{
		return m_buffer.append(buf_, len_);
	}

    uint32_t append(uint32_t size_, char val_)
    {
        return m_buffer.append(size_, val_);
    }

	uint32_t prepend(const char* buf_, uint32_t len_)
	{
        if (!m_remain_head_bytes)
        {
            m_buffer.prepend(buf_, len_);
        }

        m_buffer.drain_size(m_remain_head_bytes);
        uint32_t prepend_ret = m_buffer.prepend(buf_, len_);

        m_remain_head_bytes = (m_remain_head_bytes > len_) ? m_remain_head_bytes - len_ : 0;

        if (m_remain_head_bytes)
        {
            m_buffer.prepend(m_remain_head_bytes, 0);
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
        for (uint32_t i = 0; i < m_buffer.size(); ++i)
        {
            printf("%d: %p - %d\n", i, &(m_buffer.data()[i]), m_buffer.data()[i]);
        }
        printf("data():%p\n", data());
        printf("size():%d\n\n", size());
    }

private:
    void clear_i()
    {
        m_buffer.clear();

        m_buffer.append(HEAD_SIZE, 0);
        m_remain_head_bytes = HEAD_SIZE;
    }

private:
    msg_buffer_t                    m_buffer;
    uint32_t                        m_remain_head_bytes;
};

}

}

#endif //! _CHAOS_STERAM_H_
