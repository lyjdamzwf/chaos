/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ASYNC_METHOD_BIND_OBJ_H_
#define _CHAOS_ASYNC_METHOD_BIND_OBJ_H_

/*!
 *  @file           async_method_obj.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.17
 *  @brief          bind class of obj
 *  @last changed
 *
 */

#include <chaos/async_method/async_method_base.h>

namespace chaos
{

namespace async_method
{

#define BIND_OBJ_IMPL(num) \
template <typename CLS_TYPE, typename F BIND_NAME_LIST_##num(typename A)> \
class async_method_bind_obj_##num##_t : public async_method_base_t \
{ \
public: \
    async_method_bind_obj_##num##_t(CLS_TYPE obj_, F f_ BIND_CTOR_ARG_##num) \
        : m_obj_ptr(obj_), m_func(f_) BIND_CTOR_LIST_##num \
    {} \
    void exec() \
    { \
        if (m_obj_ptr && m_func) \
        { \
            (m_obj_ptr->*m_func)(BIND_INVOKE_LIST_##num); \
        } \
    } \
private: \
    CLS_TYPE m_obj_ptr; \
    F        m_func; \
    BIND_MEMBER_LIST_##num \
};

BIND_OBJ_IMPL(0);
BIND_OBJ_IMPL(1);
BIND_OBJ_IMPL(2);
BIND_OBJ_IMPL(3);
BIND_OBJ_IMPL(4);
BIND_OBJ_IMPL(5);
BIND_OBJ_IMPL(6);
BIND_OBJ_IMPL(7);
BIND_OBJ_IMPL(8);
BIND_OBJ_IMPL(9);

}

}

#endif //! _CHAOS_ASYNC_METHOD_BIND_OBJ_H_
