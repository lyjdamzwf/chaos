/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include <algorithm>
using namespace std;

#include <chaos/utility/utility_inc.h>
#include <chaos/thread/mutex.h>
#include <chaos/thread/thread_group.h>

/*!
 *  @file           thread_group.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.18
 *  @brief          thread group
 *  @last changed
 *
 */

namespace chaos
{

namespace thread
{

thread_group_t::thread_group_t() : m_thd_vt()
{
}

thread_group_t::~thread_group_t()
{
	join_all();
}

void thread_group_t::add(thread_t* thread_)
{
    LOGTRACE((THREAD_MODULE, "thread_grout_t::add thread-[%] begin.", thread_->get_thread_name().c_str()));

	container_t::iterator it = std::find(m_thd_vt.begin(), m_thd_vt.end(), thread_);
	if (it == m_thd_vt.end())
		m_thd_vt.push_back(thread_);

    LOGTRACE((THREAD_MODULE, "thread_grout_t::add thread-[%] end.", thread_->get_thread_name().c_str()));
}

thread_t* thread_group_t::get_by_index(size_type_t idx_)
{
	if (idx_ >= m_thd_vt.size())
		return NULL;
	else
		return m_thd_vt[idx_];
}

thread_t* thread_group_t::operator[](size_type_t idx_)
{
	if (idx_ >= m_thd_vt.size())
		return NULL;
	else
		return m_thd_vt[idx_];
}

void thread_group_t::join_all()
{
    LOGTRACE((THREAD_MODULE, "thread_group_t::join_all() begin"));

	while (!m_thd_vt.empty())
	{
		thread_t* thread = m_thd_vt.back();
		if (thread)
		{
			thread->final();
			thread->join();
			SAFE_DELETE(thread);
		}
		m_thd_vt.pop_back();
	}

    LOGTRACE((THREAD_MODULE, "thread_group_t::join_all() end"));
}

bool thread_group_t::check_is_self(pthread_t pid_)
{
    for (container_t::iterator it = m_thd_vt.begin();
         it != m_thd_vt.end();
         ++it
        )
    {
        if ((*it)->get_thread_id() == pid_)
        {
            return true;
        }
    }

    return false;
}

void thread_group_t::exec_all(callback_t &cb_)
{
	for(container_t::iterator it = m_thd_vt.begin(); it != m_thd_vt.end(); it++)
	{
		cb_.exec(*it);
	}
}

}

}

