/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ASYNC_METHOD_BIND_FUNC_H_
#define _CHAOS_ASYNC_METHOD_BIND_FUNC_H_

/*! 
 *  @file           async_method_bind_func.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.17
 *  @brief          bind class of static function
 *  @last changed   2012.3.24 by yunjie
 *
 */

#include <chaos/async_method/async_method_base.h>

namespace chaos
{

namespace async_method
{

#define BIND_FUNC_IMPL(num) \
template <typename F BIND_NAME_LIST_##num(typename A)> \
class async_method_bind_func_##num##_t : public async_method_base_t \
{ \
public: \
    async_method_bind_func_##num##_t(F f_ BIND_CTOR_ARG_##num) \
        : m_func(f_) BIND_CTOR_LIST_##num \
    {} \
    void exec() \
    { \
        if (m_func) \
        { \
            (*m_func)(BIND_INVOKE_LIST_##num); \
        } \
    } \
private: \
    F   m_func; \
    BIND_MEMBER_LIST_##num \
};

BIND_FUNC_IMPL(0)
BIND_FUNC_IMPL(1)
BIND_FUNC_IMPL(2)
BIND_FUNC_IMPL(3)
BIND_FUNC_IMPL(4)
BIND_FUNC_IMPL(5)
BIND_FUNC_IMPL(6)
BIND_FUNC_IMPL(7)
BIND_FUNC_IMPL(8)
BIND_FUNC_IMPL(9)

}

}

#endif //! _CHAOS_ASYNC_METHOD_BIND_FUNC_H_

