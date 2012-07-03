/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ASYNC_METHOD_H_
#define _CHAOS_ASYNC_METHOD_H_

/*! 
 *  @file           async_method.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.17
 *  @brief          async method interface
 *  @last changed
 *
 */

#include <stdlib.h>
#include <stdint.h>

#include <iostream>

#include "utility_inc.h"

#include "async_method_base.h"
#include "async_method_bind_func.h"
#include "async_method_bind_obj.h"

namespace chaos
{

namespace async_method
{

using namespace std;

//! yunjie: bind接口的参数不能使用const T&类型, 如果传入的是函数指针将编译错误
class async_method_t
{
public:
    //! ---------------------- yunjie: bind static function begin ---------------------- 
    template<typename FUNC>
    static async_method_t bind_func(FUNC func_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_func_0_t<FUNC>(func_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename FUNC, typename ARG0>
    static async_method_t bind_func(FUNC func_, ARG0 arg0_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_func_1_t<FUNC, ARG0>(func_, arg0_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename FUNC, typename ARG0, typename ARG1>
    static async_method_t bind_func(FUNC func_, ARG0 arg0_, ARG1 arg1_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_func_2_t<FUNC, ARG0, ARG1>(func_, arg0_, arg1_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename FUNC, typename ARG0, typename ARG1, typename ARG2>
    static async_method_t bind_func(FUNC func_, ARG0 arg0_, ARG1 arg1_, ARG2 arg2_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_func_3_t<FUNC, ARG0, ARG1, ARG2>(func_, arg0_, arg1_, arg2_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
    static async_method_t bind_func(FUNC func_, ARG0 arg0_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_func_4_t<FUNC, ARG0, ARG1, ARG2, ARG3>(func_, arg0_, arg1_, arg2_, arg3_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    static async_method_t bind_func(FUNC func_, ARG0 arg0_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_func_5_t<FUNC, ARG0, ARG1, ARG2, ARG3, ARG4>(func_, arg0_, arg1_, arg2_, arg3_, arg4_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }
    //! ---------------------- yunjie: bind static function end ---------------------- 




    //! ---------------------- yunjie: bind object function begin ---------------------- 
    template<typename T, typename FUNC>
    static async_method_t bind_memfunc(T instance_, FUNC func_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_obj_0_t<T, FUNC>(instance_, func_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename T, typename FUNC, typename ARG0>
    static async_method_t bind_memfunc(T instance_, FUNC func_, ARG0 arg0_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_obj_1_t<T, FUNC, ARG0>(instance_, func_, arg0_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename T, typename FUNC, typename ARG0, typename ARG1>
    static async_method_t bind_memfunc(T instance_, FUNC func_, ARG0 arg0_, ARG1 arg1_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_obj_2_t<T, FUNC, ARG0, ARG1>(instance_, func_, arg0_, arg1_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename T, typename FUNC, typename ARG0, typename ARG1, typename ARG2>
    static async_method_t bind_memfunc(T instance_, FUNC func_, ARG0 arg0_, ARG1 arg1_, ARG2 arg2_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_obj_3_t<T, FUNC, ARG0, ARG1, ARG2>(instance_, func_, arg0_, arg1_, arg2_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename T, typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
    static async_method_t bind_memfunc(T instance_, FUNC func_, ARG0 arg0_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_obj_4_t<T, FUNC, ARG0, ARG1, ARG2, ARG3>(instance_, func_, arg0_, arg1_, arg2_, arg3_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }

    template<typename T, typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    static async_method_t bind_memfunc(T instance_, FUNC func_, ARG0 arg0_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_, ARG4 arg4_)
    {
        async_method_base_t* async_method_ptr = new async_method_bind_obj_5_t<T, FUNC, ARG0, ARG1, ARG2, ARG3, ARG4>(instance_, func_, arg0_, arg1_, arg2_, arg3_, arg4_);
        async_method_t async_method(async_method_ptr);

        return async_method;
    }
    //! ---------------------- yunjie: bind object function end ---------------------- 


public:
    async_method_t()
        : m_async_method_base_ptr(NULL)
    {
    }

    async_method_t(async_method_base_t* ptr_)
        : m_async_method_base_ptr(ptr_)
    {
    }

    async_method_t(const async_method_t& rhs_)
    {
        m_async_method_base_ptr = rhs_.m_async_method_base_ptr;
    }

    void operator=(const async_method_t& method_)
    {
        m_async_method_base_ptr = method_.m_async_method_base_ptr;
    }

    void operator()()
    {
        if (NULL != m_async_method_base_ptr)
        {
            m_async_method_base_ptr->exec();
        }
    }

    void release()
    {
        if (NULL != m_async_method_base_ptr)
        {
            SAFE_DELETE(m_async_method_base_ptr);
        }
    }

private:
    async_method_base_t*    m_async_method_base_ptr;
};


}

}

#endif //! _CHAOS_ASYNC_METHOD_H_

