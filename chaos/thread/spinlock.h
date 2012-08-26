/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_SPINLOCK_H_
#define _CHAOS_SPINLOCK_H_

/*! 
 *  @file           spinlock.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.19
 *  @brief          spinlock
 *  @last changed
 *
 */

#include <pthread.h>

#include <chaos/utility/noncopyable.h>

namespace chaos
{

namespace thread
{

using namespace chaos::utility;

class spin_lock_t : private noncopyable_t
{
	public:
		spin_lock_t()
		{
			//! pthread_spinlinattr_t attr;
			//! ::pthread_spinattr_init(&attr);
			//! ::pthread_mutexattr_settype(&attr, kind_);
			::pthread_spin_init(&m_spinlock, 0);
		}
	
		~spin_lock_t()
		{
			::pthread_spin_destroy(&m_spinlock);
		}

		inline void lock()
		{
			::pthread_spin_lock(&m_spinlock);
		}

		inline void unlock()
		{
			::pthread_spin_unlock(&m_spinlock);
		}

		pthread_spinlock_t* get_spinlock()
		{
			return &m_spinlock;
		}

	private:
		pthread_spinlock_t                 m_spinlock;
};

class scope_spin_lock_t : private noncopyable_t
{
	public:

		scope_spin_lock_t(spin_lock_t& m_) : m_lock(m_)
		{
			m_lock.lock();
		}

		~scope_spin_lock_t()
		{
			m_lock.unlock();
		}

	private:
		spin_lock_t&                        m_lock;
};

}

}

#endif //! _CHAOS_SPINLOCK_H_


