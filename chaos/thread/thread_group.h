/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_THREAD_GROUP_H_
#define _CHAOS_THREAD_GROUP_H_

/*!
 *  @file           thread_group.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.18
 *  @brief          thread group
 *  @last changed
 *
 */

#include <chaos/thread/thread.h>

namespace chaos
{

namespace thread
{

class thread_group_t: private noncopyable_t
{
	public:
		struct callback_t
		{
			virtual void exec(thread_t* thd_) = 0;
			virtual ~callback_t(){};
		};

		thread_group_t();
		virtual ~thread_group_t();

		typedef std::vector<thread_t*> container_t;
		typedef container_t::size_type size_type_t;

		void        add(thread_t *t);
		thread_t*   get_by_index(size_type_t idx_);
		thread_t*   operator[](size_type_t idx_);

		void join_all();
		void exec_all(callback_t& cb_);

        bool check_is_self(pthread_t pid_);

		const size_type_t size() const
		{
			return m_thd_vt.size();
		}

	private:
		container_t                     m_thd_vt;		//! 线程向量
};

}

}

#endif //! _CHAOS_THREAD_GROUP_H_
