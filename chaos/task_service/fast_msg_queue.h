/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_FAST_MSG_QUEUE_H_
#define _CHAOS_FAST_MSG_QUEUE_H_

/*! 
 *  @file           fast_msg_queue.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.25
 *  @brief          fast msg queue
 *                  还存在BUG, 没有投入使用
 *  @last changed
 *
 */

#include <deque>

#include "thread_inc.h"

#include "ring_buffer.h"

namespace chaos
{

namespace task_service
{

using namespace chaos::thread;

template<typename T>
class fast_msg_queue_t
{
public:
    fast_msg_queue_t()
    {
    }

    virtual ~fast_msg_queue_t()
    {
    }

public:
    void push(const T& element_)
    {
        if (m_ring_buffer.writeable())
        {
            m_ring_buffer.put(element_);
        }
        else
            printf("can not put\n");

    }

    T pop()
    {
        if (empty())
        {
            return T();
        }

        return m_ring_buffer.get();
    }

    bool empty() const
    {
        return !m_ring_buffer.readable();
    }

    int size() const
    {
        return m_ring_buffer.size();
    }

    void clear()
    {
        m_ring_buffer.reset();
    }

private:
    ring_buffer_t<T>                        m_ring_buffer;
};

}

}

#endif //! _CHAOS_FAST_MSG_QUEUE_H_
