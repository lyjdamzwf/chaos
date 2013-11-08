/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

/*!
 *  @file           thread.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.18
 *  @brief          thread
 *  @last changed
 *
 */

#include <signal.h>
#include <pthread.h>
#include <algorithm>
using namespace std;

#include <chaos/thread/thread.h>

namespace chaos
{

namespace thread
{

void thread_t::join()
{
    LOGTRACE((THREAD_MODULE, "thread_t::join begin"));

	if(0 != m_thread && m_joinable)
	{
		::pthread_join(m_thread, NULL);

		m_thread = 0;
		m_lock.lock();
		while(m_alive) m_cond.wait(m_lock);
		m_lock.unlock();
	}

    LOGTRACE((THREAD_MODULE, "thread_t::join end"));
}

void * thread_t::thread_func(void *arg)
{
    LOGTRACE((THREAD_MODULE, "thread_func begin"));

	thread_t* thread = (thread_t*)arg;

	thread->m_lock.lock();
	thread->m_alive = true;
	thread->m_cond.broadcast();
	thread->m_lock.unlock();

	sigset_t sig_mask;
	sigfillset(&sig_mask);
	pthread_sigmask(SIG_SETMASK, &sig_mask, NULL);

    //! yunjie: invoke the registed function.
	thread->m_thread_func();

	thread->m_lock.lock();
	thread->m_alive = false;
	thread->m_cond.broadcast();
	thread->m_lock.unlock();

	if(!thread->is_joinable())
	{
		thread->m_lock.lock();
		while(thread->m_alive) thread->m_cond.wait(thread->m_lock);
		thread->m_lock.unlock();

		SAFE_DELETE(thread);
	}


    LOGTRACE((THREAD_MODULE, "thread_func end"));
	pthread_exit(NULL);
}

bool thread_t::start(async_method_t method_)
{
    LOGTRACE((THREAD_MODULE, "thread_t::start begin"));

	if(m_alive)
	{
        LOGWARN((THREAD_MODULE, "thread_t::start thread-[%] has started, return.", get_thread_name().c_str()));

		return true;
	}

	::pthread_attr_t attr;
	::pthread_attr_init(&attr);
	if(!m_joinable) pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    m_thread_func = method_;

	if(0 != ::pthread_create(&m_thread, NULL, thread_t::thread_func, this))
	{
        LOGWARN((THREAD_MODULE, "thread_t::start thread-[%] create failed, return.", get_thread_name().c_str()));

		return false;
	}

	pthread_attr_destroy(&attr);

	m_lock.lock();
	while(!m_alive) m_cond.wait(m_lock);
	m_lock.unlock();

    LOGTRACE((THREAD_MODULE, "thread_t::start end"));
	return true;
}

}

}

