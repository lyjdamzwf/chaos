/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_HEART_BEAT_SERVICE_H_
#define _CHAOS_HEART_BEAT_SERVICE_H_

/*!
 *  @file           heart_beat_service.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.5.5
 *  @brief          heart beat service
 *  @last changed
 *
 */

#include <chaos/task_service/task_service_inc.h>
#include <chaos/heart_beat/heart_beat_element_mgr.h>

namespace chaos
{

namespace heart_beat
{

using namespace chaos::task_service;

//! yunjie: 扫描heart beat元素的时间间隔, HEART_BEAT_MOUDLE_TICKS秒执行一次handle_timeout
#ifndef HEART_BEAT_MOUDLE_TICKS
#define HEART_BEAT_MOUDLE_TICKS 8
#endif

template<typename element_type, typename element_hash = hash<element_type> >
class heart_beat_service_t : private noncopyable_t
{
public:
    typedef         void(*callback_function_type)(element_type&);

public:
    heart_beat_service_t();
    ~heart_beat_service_t();

    int initialize(task_service_t* service_ptr_);
    int set_callback_function(callback_function_type callback_function);
    int set_timeout(bool timeout_flag, unsigned int timedout);
    int set_max_limit(bool max_limit_flag, unsigned long max_limit);

    int start();

    int stop();

    void async_add_element(element_type& element);

    void async_update_element(element_type& element);

    void async_del_element(element_type& element);

private:
    int stop_service();

    int handle_timeout();

    int add_element(element_type& element);

    int update_element(element_type& element);

    int del_element(element_type& element);

private:
    bool                                                                        m_started;
    task_service_t*                                                             m_service_ptr;
    heart_beat_element_mgr_t<element_type, element_hash>                        m_element_manager;

    volatile bool m_get_element_flag;
};

template<typename element_type, typename element_hash>
heart_beat_service_t<element_type, element_hash>::heart_beat_service_t()
    :
        m_started(false),
        m_service_ptr(NULL)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::heart_beat_service_t ..."));
}

template<typename element_type, typename element_hash>
heart_beat_service_t<element_type, element_hash>::~heart_beat_service_t()
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::~heart_beat_service_t begin ..."));

    stop();

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::~heart_beat_service_t end ok."));
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::initialize(task_service_t* service_ptr_)
{
    if (m_started)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::initialize "
                    "Heart beat service has been started and cannot set callback function again"));

        return -1;
    }

    m_service_ptr = service_ptr_;

    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::set_callback_function(callback_function_type callback_function)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_callback_function begin ..."));

    if (m_started)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_callback_function "
          "Heart beat service has been started and cannot set callback function again"));

        return -1;
    }

    if (m_element_manager.set_callback_function(callback_function))
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_callback_function "
          "Failed to set callback function of element."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_callback_function end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::set_timeout(bool timeout_flag, unsigned int timedout)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_timedout begin ..."));

    if (m_started)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_timeout "
          "Heart beat service has been started and cannot set timeout again."));

        return -1;
    }

    if (m_element_manager.set_timeout(timeout_flag, timedout))
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_timeout "
          "Failed to set timeout flag and seconds of element."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_timeout end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::set_max_limit(bool max_limit_flag, unsigned long max_limit)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_max_limit begin ..."));

    if (m_started)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_max_limit "
          "Heart beat service has been started and cannot set max limit of element agagin."));

        return -1;
    }

    if (m_element_manager.set_max_limit(max_limit_flag, max_limit))
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_max_limit "
          "Failed to set max limit flag and number of element."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::set_max_limit end ok ..."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::start()
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::start begin ..."));

    if (m_started)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::start "
          "Heart beat service is already started."));

        return 0;
    }

    if (NULL == m_service_ptr)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::start m_service_ptr is NULL, return."));
        return 0;
    }

    m_service_ptr->register_timer(HEART_BEAT_MOUDLE_TICKS,
                                  bindfunc(
                                                                this,
                                                                &heart_beat_service_t<element_type, element_hash>::handle_timeout
                                                               )
                                );

    m_started = true;

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::start end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::stop()
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::stop begin ..."));

    if (!m_started)
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::stop "
          "Heart beat service is already stoped."));

        return 0;
    }

    m_service_ptr->post(bindfunc(this, &heart_beat_service_t::stop_service));

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::stop end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::stop_service()
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::stop_service begin ..."));

    m_element_manager.clear_element();
    m_started = false;

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::stop_service end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
void heart_beat_service_t<element_type, element_hash>::async_add_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::async_add_element begin..."));

    if (NULL != m_service_ptr)
    {
        m_service_ptr->post(bindfunc(this, &heart_beat_service_t<element_type, element_hash>::add_element, element));
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::async_add_element end ok."));
}

template<typename element_type, typename element_hash>
void heart_beat_service_t<element_type, element_hash>::async_update_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::async_update_element begin..."));

    if (NULL != m_service_ptr)
    {
        m_service_ptr->post(bindfunc(this, &heart_beat_service_t<element_type, element_hash>::update_element, element));
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::async_update_element end ok."));
}

template<typename element_type, typename element_hash>
void heart_beat_service_t<element_type, element_hash>::async_del_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::async_del_element begin..."));

    if (NULL != m_service_ptr)
    {
        m_service_ptr->post(bindfunc(this, &heart_beat_service_t<element_type, element_hash>::del_element, element));
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::async_del_element end ok."));
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::handle_timeout()
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::handle_timeout() begin..."));

    if (m_started)
    {
        m_service_ptr->register_timer(HEART_BEAT_MOUDLE_TICKS,
                bindfunc(
                    this,
                    &heart_beat_service_t<element_type, element_hash>::handle_timeout
                    )
                );
    }


    if (m_element_manager.handle_timeout())
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_service_t::handle_timeout "
          "Failed to invoke handle element at element manager."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::handle_timeout() end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::add_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::add_element begin ..."));

    if (m_element_manager.add_element(element))
    {
        LOGERROR((HEART_BEAT_MOUDLE, "heart_beat_service_t::add_element "
          "Failed to invoke add element at element manager."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::add_element end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::update_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::update_element begin ..."));

    if (m_element_manager.update_element(element))
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::update_element "
          "Failed to invoke update element at element manager."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::update_element end ok."));
    return 0;
}

template<typename element_type, typename element_hash>
int heart_beat_service_t<element_type, element_hash>::del_element(element_type& element)
{
    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::del_element begin ..."));

    if (m_element_manager.del_element(element))
    {
        LOGWARN((HEART_BEAT_MOUDLE, "heart_beat_service_t::del_element "
          "Failed to invoke delete element at element manager."));

        return -1;
    }

    LOGTRACE((HEART_BEAT_MOUDLE, "heart_beat_service_t::del_element end ok."));
    return 0;
}

}

}

#endif //! _CHAOS_HEART_BEAT_SERVICE_H_

