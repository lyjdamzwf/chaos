/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _ATOMICVAL_H_
#define _ATOMICVAL_H_

/*!
 *  @file           atomic_val.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief          atomic val
 *  @last changed
 *
 */

#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>

namespace chaos
{

namespace utility
{


template<typename T>
class atomic_val_t
{
public:
	atomic_val_t(): m_val(0) {}
	explicit atomic_val_t(T val):
#ifdef _WIN32
		m_val((Int32)val)
#else
		m_val((size_t)val)
#endif
		{}
	atomic_val_t(const atomic_val_t<T>& other): m_val(other._val) {}
	inline operator T() const
	{
#ifdef _WIN32
		return (const T)m_val;
#else
		return (const T)__sync_fetch_and_xor((volatile size_t *)&m_val, 0);
#endif
	}
	inline T value() const { return *this; }
	inline atomic_val_t<T>& operator=(T val)
	{
#ifdef _WIN32
		InterlockedExchange((volatile LONG *)&m_val, (LONG)val);
#else
		size_t oldval;
		do {
			oldval = __sync_fetch_and_xor((volatile size_t *)&m_val, 0);
		} while(!__sync_bool_compare_and_swap(&m_val, oldval, val));
#endif
		return *this;
	}
	inline atomic_val_t<T>& operator=(const atomic_val_t<T>& other)
	{
		return (*this) = other.value();
	}
	inline T operator ++ ()
	{
#ifdef _WIN32
		return (T)InterlockedIncrement(&m_val);
#else
		return (T)__sync_add_and_fetch(&m_val, 1);
#endif
	}
	inline T operator ++ (int)
	{
#ifdef _WIN32
		T result = m_val;
		InterlockedIncrement(&m_val);
		return result;
#else
		return (T)__sync_fetch_and_add(&m_val, 1);
#endif
	}
	inline T operator -- ()
	{
#ifdef _WIN32
		return (T)InterlockedDecrement(&m_val);
#else
		return (T)__sync_sub_and_fetch(&m_val, 1);
#endif
	}
	inline T operator -- (int)
	{
#ifdef _WIN32
		T result = m_val;
		InterlockedDecrement(&m_val);
		return result;
#else
		return (T)__sync_fetch_and_sub(&m_val, 1);
#endif
	}
	inline T operator += (T n)
	{
#ifdef _WIN32
		InterlockedExchangeAdd(&m_val, n);
		return _val;
#else
		return (T)__sync_fetch_and_add(&m_val, n);
#endif
	}
	inline T operator -= (T n)
	{
#ifdef _WIN32
		InterlockedExchangeAdd(&m_val, -n);
		return _val;
#else
		return (T)__sync_fetch_and_sub(&m_val, n);
#endif
	}

private:
#ifdef _WIN32
	volatile LONG m_val;
#else
	volatile size_t m_val;
#endif
};

}

}

#endif // _ATOMICVAL_H_
