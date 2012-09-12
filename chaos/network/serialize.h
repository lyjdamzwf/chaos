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

namespace chaos
{

namespace network
{

#define HEAD_SIZE           8
#define MAX_STACK_SIZE      (16*1024)

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
        m_prepend_pos = rhs_.m_prepend_pos;
        m_buffer = rhs_.m_buffer;
    }

    const serialize_t& operator=(const serialize_t& rhs_)
    {
        m_prepend_pos = rhs_.m_prepend_pos;
        m_buffer = rhs_.m_buffer;

        return *this;
    }

	uint32_t head_left() const { return m_prepend_pos + 1; }
	uint32_t size() const { return m_buffer.size() - head_left(); }
	const char* data() const { return &m_buffer[m_prepend_pos + 1]; }

	uint32_t first_of(char b) const
	{
		uint32_t c = m_buffer.size();
		for (uint32_t i = m_prepend_pos + 1; i < c; ++ i)
		{
			if (m_buffer[i] == b)
			{
				return i;
			}
		}

		return -1;
	}

    void reserve(uint32_t size_) { if (size_ > m_buffer.capacity()) m_buffer.reserve(size_); }

	void clear() { clear_i(); }

	void append(const char* buf_, uint32_t len_)
	{
		m_buffer.append(buf_, len_);
	}

    void append(uint32_t size_, char val_)
    {
        m_buffer.append(size_, val_);
    }

	void prepend(const char* buf_, uint32_t len_)
	{
        uint32_t len = len_ <= head_left() ? len_ : head_left();

        if (len)
        {
            memcpy(const_cast<char*>(m_buffer.c_str()) + m_prepend_pos - len + 1, buf_, len);
            m_prepend_pos -= len;
        }

        if (len < len_)
        {
            m_buffer.insert(0, buf_ + len, len_ - len);
            m_prepend_pos = -1;
        }
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
		m_buffer.insert(m_buffer.end(), v.begin(), v.end());
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
		m_buffer.insert(m_buffer.end(), v, v + len);
		return *this;
	}

    void dump() const
    {
        for (uint32_t i = 0; i < m_buffer.size(); ++i)
        {
            printf("%d: %p - %d\n", i, &m_buffer[i], m_buffer[i]);
        }
        printf("prepend pos:%d\n", m_prepend_pos);
        printf("data():%p\n", data());
        printf("size():%d\n\n", size());
    }

private:
    void clear_i()
    {
        m_prepend_pos = HEAD_SIZE - 1;
        m_buffer.append(HEAD_SIZE, 0);
    }

private:
    uint32_t                        m_prepend_pos;
    string                          m_buffer;
};

}

}

#endif //! _CHAOS_STERAM_H_
