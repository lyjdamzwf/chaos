/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_RWLOCK_H_
#define _CHAOS_RWLOCK_H_

/*!
 *  @file           rwlock.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.19
 *  @brief          rwlock
 *  @last changed
 *
 */

#include <pthread.h>

#include <chaos/utility/noncopyable.h>

namespace chaos
{

namespace thread
{

class rwlock_t : private noncopyable_t
{
	public:
		unsigned int rd_count;
		unsigned int wr_count;

		rwlock_t() : rd_count(0), wr_count(0)
		{
			::pthread_rwlock_init(&m_rwlock, NULL);
		}

		~rwlock_t()
		{
			::pthread_rwlock_destroy(&m_rwlock);
		}

		void rdlock()
		{
			::pthread_rwlock_rdlock(&m_rwlock);
			rd_count++;
		}

		void wrlock()
		{
			::pthread_rwlock_wrlock(&m_rwlock);
			rd_count++;
			wr_count++;
		}

		void unlock()
		{
			::pthread_rwlock_unlock(&m_rwlock);
			rd_count--;
		}

	private:
		pthread_rwlock_t m_rwlock;
};

class scope_rdlock_t : private noncopyable_t
{
	public:
		scope_rdlock_t(rwlock_t &lock_) : m_rwlock(lock_)
		{
			m_rwlock.rdlock();
		}

		~scope_rdlock_t()
		{
			m_rwlock.unlock();
		}
	private:
		rwlock_t&           m_rwlock;
};

class scope_wrlock_t : private noncopyable_t
{
	public:
		scope_wrlock_t(rwlock_t &lock_) : m_rwlock(lock_)
		{
			m_rwlock.wrlock();
		}

		~scope_wrlock_t()
		{
			m_rwlock.unlock();
		}
	private:
		rwlock_t&           m_rwlock;
};

}

}

#endif //! _CHAOS_RWLOCK_H_

