/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_HEART_BEAT_ELEMENT_MGR_H_
#define _CHAOS_HEART_BEAT_ELEMENT_MGR_H_

/*! 
 *  @file           heart_beat_element_mgr.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.5.5
 *  @brief          heart beat element mgr
 *  @last changed
 *
 */

#include <ext/hash_map>

#include "utility_inc.h"
#include "log_inc.h"

#include "heart_beat_list.h"

namespace chaos
{

namespace heart_beat
{

using namespace __gnu_cxx;
using namespace chaos::utility;
using namespace chaos::log;

template<typename element_type>
struct element_data_t
{
    element_data_t();

    element_data_t(const element_type& in_element);

    element_type element;

    time_t time;
};

template<typename element_type, typename element_hash>
class heart_beat_element_mgr_t : private noncopyable_t
{
public:
    typedef         void(*callback_function_type)(element_type&);

    typedef element_data_t<element_type> element_data_type;
    typedef heart_beat_list_t<element_data_type> list_type;
    typedef typename heart_beat_list_t<element_data_type>::node_type list_node_type;

    typedef hash_map<element_type, list_node_type*, element_hash> element_map;

    typedef typename element_map::iterator element_map_iterator;

public:
    heart_beat_element_mgr_t();

    int set_callback_function(callback_function_type callback_function);

    int set_timeout(bool timeout_flag, unsigned int timedout);

    int set_max_limit(bool max_limit_flag, unsigned long max_limit);

    int handle_timeout();

    int add_element(element_type& element);

    int update_element(element_type& element);

    int del_element(element_type& element);

    int clear_element();

    int get_all_element_and_clear(vector<element_type>* element_vt);

private:
    element_map                                         m_elements;
    list_type                                           m_busy_list;
    callback_function_type                              m_callback_function;
    unsigned long                                       m_element_count;
    bool                                                m_timeout_flag;
    unsigned int                                        m_timeout;
    bool                                                m_max_limit_flag;
    unsigned long                                       m_max_limit;
};

template<typename element_type>
element_data_t<element_type>::element_data_t() : element(), time(time(NULL))
{
    LOGTRACE((HEART_BEAT_MOUDLE, "element_data_t<element_type>::element_data_t"));
}

template<typename element_type>
element_data_t<element_type>::element_data_t(const element_type& in_element)
  : element(in_element), time(::time(NULL))
{
    LOGTRACE((HEART_BEAT_MOUDLE, "element_data_t<element_type>::element_data_t"));
}

template<typename element_type, typename element_hash>
heart_beat_element_mgr_t<element_type, element_hash>::heart_beat_element_mgr_t()
  : m_element_count(0), m_timeout_flag(false), m_timeout(0), m_max_limit_flag(false), m_max_limit(0)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::heart_beat_element_mgr_t"));
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::set_callback_function(callback_function_type callback_function)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::set_callback_function begin..."));

    m_callback_function = callback_function;

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::set_callback_function end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::set_timeout(bool timeout_flag, unsigned int timeout)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::set_timedout begin..."));
    m_timeout_flag = timeout_flag;
    m_timeout = timeout;
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::set_timedout end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::set_max_limit(bool max_limit_flag, unsigned long max_limit)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::set_max_limit begin..."));
    m_max_limit_flag = max_limit_flag;
    m_max_limit = max_limit;
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::set_max_limit end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::handle_timeout()
{
    if (m_timeout_flag)
    {
        time_t currect_time = time(NULL);
        list_node_type* node = NULL;
        unsigned int timeout = m_timeout;

        while ((node = m_busy_list.back()))
        {
            if (currect_time >= (node->data.time + timeout))
            {
                //! yunjie: 因为m_callback_function可能会调用del_element元素, 所以这里需要先从容器中去除, 防止double free
                if (!(m_busy_list.pop_back()))
                {
                    LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::handle_timeout "
                      "Failed to pop node from back of element busy list."));

                    return -1;
                }
                m_elements.erase(node->data.element);
                --m_element_count;

                if (!m_callback_function)
                {
                    LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::handle_timeout "
                      "The element callback function is empty."));
                }
                else
                {
                    m_callback_function(node->data.element);
                }

                SAFE_DELETE(node);
            }
            else
            {
              break;  //! yunjie: 没有超时元素
            }
        }
    }

    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::add_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::add_element begin..."));

    element_map_iterator it = m_elements.find(element);
    if (it != m_elements.end()) //! yunjie: 已经存在, 返回
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::add_element element has existed"));

        return -1;;
    }
    else  //! yunjie: 添加新的元素
    {
        if (m_max_limit_flag) //! yunjie: 是否有设置最大元素数限制
        {
            if (m_element_count + 1 > m_max_limit)
            {
                list_node_type* node = m_busy_list.pop_back();
                m_elements.erase(node->data.element);
                --m_element_count;

                if (!m_callback_function)
                {
                    LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::add_element "
                      "The element callback function is empty."));
                }
                else
                {
                    m_callback_function(node->data.element);
                }

                SAFE_DELETE(node);
            }
        }

        list_node_type* node = new list_node_type(element);
        if (!node)
        {
            LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::add_element "
              "failed to malloc the element node."));

            return -1;
        }

        m_elements.insert(make_pair(element, node));
        m_busy_list.push_front(node);
        ++m_element_count;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::add_element end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::update_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::update_element begin..."));

    element_map_iterator it = m_elements.find(element);
    if (it == m_elements.end())
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::update_element "
          "Failed to find element."));

        return -1;
    }

    list_node_type* node = it->second;
    if (m_busy_list.erase(node))
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::update_element "
          "Failed to delete node from element busy list."));

        return -1;
    }
    node->data.time = ::time(NULL);
    m_busy_list.push_front(node);

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::update_element end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::del_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::del_element begin..."));

    element_map_iterator it = m_elements.find(element);
    if (it != m_elements.end())
    {
        list_node_type* node = it->second;
        if (m_busy_list.erase(node))
        {
            LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::del_element "
              "Failed to delete node from element busy list."));

            return -1;
        }

        m_elements.erase(element);
        SAFE_DELETE(node);
        --m_element_count;
    }
    else
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::del_element "
          "Failed to find element."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::del_element end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::clear_element()
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::clear_element begin..."));
    list_node_type* node = NULL;
    while (NULL != (node = m_busy_list.pop_front()))
    {
        SAFE_DELETE(node);
    }

    m_elements.clear();
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::clear_element end ok..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_element_mgr_t<element_type, element_hash>::get_all_element_and_clear(
                                            vector<element_type>* element_vt)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::get_all_element_and_clear begin..."));
    list_node_type* node = NULL;
    while (NULL != (node = m_busy_list.pop_front()))
    {
        element_vt->push_back(node->data.element);
        SAFE_DELETE(node);
    }

    m_elements.clear();
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_element_mgr_t::get_all_element_and_clear end ok..."));
    return 0;
}

}

}

#endif //! _CHAOS_HEART_BEAT_ELEMENT_MGR_H_

