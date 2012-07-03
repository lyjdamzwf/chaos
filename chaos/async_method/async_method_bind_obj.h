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

#include "async_method_base.h"

namespace chaos
{

namespace async_method
{

template<typename T, typename FUNC>
class async_method_bind_obj_0_t: public async_method_base_t
{
public:
    async_method_bind_obj_0_t()
    {
    }

    async_method_bind_obj_0_t(T instance_, FUNC func0_)
        : m_instance(instance_),
          m_func0(func0_)
    {
    }

    virtual void exec()
    {
        (m_instance->*m_func0)();        //! yunjie: 优先级问题, 必须加括号
    }

private:
    T               m_instance;
    FUNC            m_func0;
};

template<typename T, typename FUNC, typename ARG0>
class async_method_bind_obj_1_t: public async_method_base_t
{
public:
    async_method_bind_obj_1_t()
    {
    }

    async_method_bind_obj_1_t(T instance_, FUNC func1_, const ARG0& arg0_)
        : m_instance(instance_),
          m_func1(func1_),
          m_arg0(arg0_)
    {
    }

    virtual void exec()
    {
        (m_instance->*m_func1)(m_arg0);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    T           m_instance;
    FUNC        m_func1;
    ARG0        m_arg0;
};

template<typename T, typename FUNC, typename ARG0, typename ARG1>
class async_method_bind_obj_2_t: public async_method_base_t
{
public:
    async_method_bind_obj_2_t()
    {
    }

    async_method_bind_obj_2_t(T instance_, FUNC func2_, const ARG0& arg0_, const ARG1& arg1_)
        : m_instance(instance_),
          m_func2(func2_),
          m_arg0(arg0_),
          m_arg1(arg1_)
    {
    }

    virtual void exec()
    {
        (m_instance->*m_func2)(m_arg0, m_arg1);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    T           m_instance;
    FUNC        m_func2;
    ARG0        m_arg0;
    ARG1        m_arg1;
};

template<typename T, typename FUNC, typename ARG0, typename ARG1, typename ARG2>
class async_method_bind_obj_3_t: public async_method_base_t
{
public:
    async_method_bind_obj_3_t()
    {
    }

    async_method_bind_obj_3_t(T instance_, FUNC func3_, const ARG0& arg0_, const ARG1& arg1_, const ARG2& arg2_)
        : m_instance(instance_),
          m_func3(func3_),
          m_arg0(arg0_),
          m_arg1(arg1_),
          m_arg2(arg2_)
    {
    }

    virtual void exec()
    {
        (m_instance->*m_func3)(m_arg0, m_arg1, m_arg2);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    T           m_instance;
    FUNC        m_func3;
    ARG0        m_arg0;
    ARG1        m_arg1;
    ARG2        m_arg2;
};

template<typename T, typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
class async_method_bind_obj_4_t: public async_method_base_t
{
public:
    async_method_bind_obj_4_t()
    {
    }

    async_method_bind_obj_4_t(T instance_, FUNC func4_, const ARG0& arg0_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_)
        : m_instance(instance_),
          m_func4(func4_),
          m_arg0(arg0_),
          m_arg1(arg1_),
          m_arg2(arg2_),
          m_arg3(arg3_)
    {
    }

    virtual void exec()
    {
        (m_instance->*m_func4)(m_arg0, m_arg1, m_arg2, m_arg3);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    T           m_instance;
    FUNC        m_func4;
    ARG0        m_arg0;
    ARG1        m_arg1;
    ARG2        m_arg2;
    ARG3        m_arg3;
};

template<typename T, typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
class async_method_bind_obj_5_t: public async_method_base_t
{
public:
    async_method_bind_obj_5_t()
    {
    }

    async_method_bind_obj_5_t(T instance_, FUNC func5_, const ARG0& arg0_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_)
        : m_instance(instance_),
          m_func5(func5_),
          m_arg0(arg0_),
          m_arg1(arg1_),
          m_arg2(arg2_),
          m_arg3(arg3_),
          m_arg4(arg4_)
    {
    }

    virtual void exec()
    {
        (m_instance->*m_func5)(m_arg0, m_arg1, m_arg2, m_arg3, m_arg4);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    T           m_instance;
    FUNC        m_func5;
    ARG0        m_arg0;
    ARG1        m_arg1;
    ARG2        m_arg2;
    ARG3        m_arg3;
    ARG4        m_arg4;
};


}

}

#endif //! _CHAOS_ASYNC_METHOD_BIND_OBJ_H_
