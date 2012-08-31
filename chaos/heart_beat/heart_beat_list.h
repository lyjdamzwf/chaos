/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_HEART_BEAT_LIST_H_
#define _CHAOS_HEART_BEAT_LIST_H_

/*!
 *  @file           heart_beat_list.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.5.5
 *  @brief          heart beat list
 *  @last changed
 *
 */

namespace chaos
{

namespace heart_beat
{

template<typename data_type>
struct heart_beat_list_node_t
{
    typedef struct heart_beat_list_node_t<data_type> node_type;

    heart_beat_list_node_t() : front(NULL), next(NULL), data()
    {
    }

    heart_beat_list_node_t(const data_type& in_data) : front(NULL), next(NULL), data(in_data)
    {
    }

    heart_beat_list_node_t(const heart_beat_list_node_t& rhs)
    {
    }

    ~heart_beat_list_node_t()
    {
    }

    node_type* front;
    node_type* next;
    data_type data;
};

template<typename data_type>
class heart_beat_list_t
{
public:
    typedef heart_beat_list_node_t<data_type> node_type;

public:
    heart_beat_list_t();

    ~heart_beat_list_t();

    int push_front(node_type* node);

    int push_back(node_type* node);

    node_type* pop_front();

    node_type* pop_back();

    node_type* front();

    node_type* back();

    int erase(node_type* node);

    bool empty();

private:
    node_type* m_header;
    node_type* m_tail;
};

template<typename data_type>
heart_beat_list_t<data_type>::heart_beat_list_t() : m_header(NULL), m_tail(NULL)
{
}

template<typename data_type>
heart_beat_list_t<data_type>::~heart_beat_list_t()
{
    m_header = NULL;
    m_tail = NULL;
}

template<typename data_type>
int heart_beat_list_t<data_type>::push_front(node_type* node)
{
    if (!node)
    {
        return -1;
    }

    node->front = NULL;
    node->next = NULL;
    if (!m_header)
    {
        m_header = node;
        m_tail = node;
    }
    else
    {
        node->next = m_header;
        m_header->front = node;
        m_header = node;
    }

    return 0;
}

template<typename data_type>
int heart_beat_list_t<data_type>::push_back(node_type* node)
{
    if (!node)
    {
        return -1;
    }

    node->front = NULL;
    node->next = NULL;
    if (!m_tail)
    {
        m_header = node;
        m_tail = node;
    }
    else
    {
        m_tail->next = node;
        node->front = m_tail;
        m_tail = node;
    }

    return 0;
}

template<typename data_type>
heart_beat_list_node_t<data_type>* heart_beat_list_t<data_type>::pop_front()
{
    node_type* ret = NULL;

    if (!m_header)
    {
        ret = NULL;
    }
    else if (m_header == m_tail)
    {
        ret = m_header;
        m_header = NULL;
        m_tail = NULL;
    }
    else
    {
        ret = m_header;
        m_header = m_header->next;
        ret->next = NULL;
        m_header->front = NULL;
    }

    return ret;
}

template<typename data_type>
heart_beat_list_node_t<data_type>* heart_beat_list_t<data_type>::pop_back()
{
    node_type* ret = NULL;

    if (!m_tail)
    {
        ret = NULL;
    }
    else if (m_header == m_tail)
    {
        ret = m_tail;
        m_header = NULL;
        m_tail = NULL;
    }
    else
    {
        ret = m_tail;
        m_tail = m_tail->front;
        ret->front = NULL;
        m_tail->next = NULL;
    }

    return ret;
}

template<typename data_type>
heart_beat_list_node_t<data_type>* heart_beat_list_t<data_type>::front()
{
    return m_header;
}

template<typename data_type>
heart_beat_list_node_t<data_type>* heart_beat_list_t<data_type>::back()
{
    return m_tail;
}

template<typename data_type>
int heart_beat_list_t<data_type>::erase(node_type* node)
{
    if (!node ||  !m_header)
    {
        return -1;
    }

    int ret = -1;
    if (!(node->front) && !(node->next))
    {
        if (m_header == m_tail && m_header == node)
        {
            m_header = NULL;
            m_tail = NULL;
            ret = 0;
        }
    }
    else if (!(node->front) && node->next)
    {
        if (m_header == node)
        {
            m_header = m_header->next;
            m_header->front = NULL;
            node->next = NULL;
            ret = 0;
        }
    }
    if (node->front && !(node->next))
    {
        if (m_tail == node)
        {
            m_tail = m_tail->front;
            m_tail->next = NULL;
            node->front = NULL;
            ret = 0;
        }
    }
    else if (node->front && node->next)
    {
        node_type* node_front = node->front;
        node_type* node_next = node->next;
        node->front = NULL;
        node->next = NULL;
        node_front->next = node_next;
        node_next->front = node_front;
        ret = 0;
    }

    return ret;
}

template<typename data_type>
bool heart_beat_list_t<data_type>::empty()
{
    return !m_header;
}

}

}

#endif //! _CHAOS_HEART_BEAT_LIST_H_

