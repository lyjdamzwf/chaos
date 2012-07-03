/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_RING_BUFFER_H_
#define _CHAOS_RING_BUFFER_H_

/*! 
 *  @file           ring_buffer.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.25
 *  @brief          ring buffer
 *                  仍存在BUG, 尚未投入使用
 *  @last changed
 */

#include "thread_inc.h"
#include "utility_inc.h"

namespace chaos
{

namespace task_service
{

using namespace chaos::thread;
using namespace chaos::utility;

#define RING_BUFFER_ELEMENT_COUNT       (1000 * 100)

template<typename ElementType>
class ring_buffer_t : noncopyable_t
{
public:
    ring_buffer_t()
        : m_write_offset(0),
          m_read_offset(0),
          m_is_same_round(true)
    {
    }

    virtual ~ring_buffer_t()
    {
    }

public:
    int put(const ElementType& element_)
    {
        if (!writeable())
        {
            return -1;
        }

        m_buffer[m_write_offset] = element_;
        if (m_write_offset + 1 == RING_BUFFER_ELEMENT_COUNT)
        {
            m_write_offset = 0;
            m_is_same_round = false;
        }
        else
        {
            ++m_write_offset;
        }

        return 0;
    }

    ElementType get()
    {
        if (!readable())
        {
            return ElementType();
        }

        ElementType& element = m_buffer[m_read_offset];
        if (m_read_offset + 1 == RING_BUFFER_ELEMENT_COUNT)
        {
            m_read_offset = 0;
            m_is_same_round = true;
        }
        else
        {
            ++m_read_offset;
        }

        return element;
    }

    bool writeable() const
    {
        return (m_is_same_round && m_write_offset >= m_read_offset) || (!m_is_same_round && m_write_offset < m_read_offset);
    }

    bool readable() const
    {
        return (m_is_same_round && m_read_offset < m_write_offset) || (!m_is_same_round);
    }

    int size() const
    {
        if (m_is_same_round)
        {
            return m_write_offset - m_read_offset;
        }
        else
        {
            return RING_BUFFER_ELEMENT_COUNT - m_read_offset + m_write_offset;
        }
    }

    void reset()
    {
        m_write_offset = 0;
        m_read_offset = 0;
        m_is_same_round = true;
    }

private:
    int                                 m_write_offset;
    int                                 m_read_offset;
    bool                                m_is_same_round;
    ElementType                         m_buffer[RING_BUFFER_ELEMENT_COUNT];
};

}

}


#endif //! _CHAOS_RING_BUFFER_H_
