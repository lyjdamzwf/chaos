/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_NONCOPYALBE_H_
#define _CHAOS_NONCOPYALBE_H_

/** 
 *  @file           noncopyable.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */

namespace chaos
{

namespace utility
{

class noncopyable_t
{
protected:
	noncopyable_t() {}
	~noncopyable_t() {}

//! yunjie: 将拷贝构造和赋值函数 设置为私有
private:
	noncopyable_t( const noncopyable_t& );
	const noncopyable_t& operator = ( const noncopyable_t& );
};

}

}

#endif //! _CHAOS_NONCOPYALBE_H_
