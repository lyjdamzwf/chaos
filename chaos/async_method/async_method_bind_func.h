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

#include "async_method_base.h"

namespace chaos
{

namespace async_method
{
template<typename FUNC>
class async_method_bind_func_0_t: public async_method_base_t
{
public:
    async_method_bind_func_0_t()
        : m_func0(NULL)
    {
    }

    async_method_bind_func_0_t(FUNC func_)
        : m_func0(func_)
    {
    }

    virtual void exec()
    {
        (*m_func0)();        //! yunjie: 优先级问题, 必须加括号
    }

private:
    FUNC                m_func0;
};

template<typename FUNC, typename ARG0>
class async_method_bind_func_1_t: public async_method_base_t
{
public:
    async_method_bind_func_1_t()
        : m_func1(NULL)
    {
    }

    async_method_bind_func_1_t(FUNC func_, const ARG0& arg0_)
        : m_func1(func_),
          m_arg0(arg0_)
    {
    }

    virtual void exec()
    {
        (*m_func1)(m_arg0);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    FUNC            m_func1;
    ARG0            m_arg0; 
};

template<typename FUNC, typename ARG0, typename ARG1>
class async_method_bind_func_2_t: public async_method_base_t
{
public:
    async_method_bind_func_2_t()
        : m_func2(NULL)
    {
    }

    async_method_bind_func_2_t(FUNC func_, const ARG0& arg0_, const ARG1& arg1_)
        : m_func2(func_),
          m_arg0(arg0_),
          m_arg1(arg1_)
    {
    }

    virtual void exec()
    {
        (*m_func2)(m_arg0, m_arg1);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    FUNC            m_func2;
    ARG0            m_arg0; 
    ARG1            m_arg1; 
};

template<typename FUNC, typename ARG0, typename ARG1, typename ARG2>
class async_method_bind_func_3_t: public async_method_base_t
{
public:
    async_method_bind_func_3_t()
        : m_func3(NULL)
    {
    }

    async_method_bind_func_3_t(FUNC func_, const ARG0& arg0_, const ARG1& arg1_, const ARG2& arg2_)
        : m_func3(func_),
          m_arg0(arg0_),
          m_arg1(arg1_),
          m_arg2(arg2_)
    {
    }

    virtual void exec()
    {
        (*m_func3)(m_arg0, m_arg1, m_arg2);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    FUNC            m_func3;
    ARG0            m_arg0; 
    ARG1            m_arg1; 
    ARG2            m_arg2; 
};

template<typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
class async_method_bind_func_4_t: public async_method_base_t
{
public:
    async_method_bind_func_4_t()
        : m_func4(NULL)
    {
    }

    async_method_bind_func_4_t(FUNC func_, const ARG0& arg0_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_)
        : m_func4(func_),
          m_arg0(arg0_),
          m_arg1(arg1_),
          m_arg2(arg2_),
          m_arg3(arg3_)
    {
    }

    virtual void exec()
    {
        (*m_func4)(m_arg0, m_arg1, m_arg2, m_arg3);        //! yunejie: 优先级问题, 必须加括号
    }

private:
    FUNC            m_func4;
    ARG0            m_arg0; 
    ARG1            m_arg1; 
    ARG2            m_arg2; 
    ARG3            m_arg3; 
};

template<typename FUNC, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
class async_method_bind_func_5_t: public async_method_base_t
{
public:
    async_method_bind_func_5_t()
        : m_func5(NULL)
    {
    }

    async_method_bind_func_5_t(FUNC func_, const ARG0& arg0_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_, const ARG4& arg4_)
        : m_func5(func_),
          m_arg0(arg0_),
          m_arg1(arg1_),
          m_arg2(arg2_),
          m_arg3(arg3_),
          m_arg4(arg4_)
    {
    }

    virtual void exec()
    {
        (*m_func5)(m_arg0, m_arg1, m_arg2, m_arg3, m_arg4);        //! yunjie: 优先级问题, 必须加括号
    }

private:
    FUNC            m_func5;
    ARG0            m_arg0; 
    ARG1            m_arg1; 
    ARG2            m_arg2; 
    ARG3            m_arg3; 
    ARG4            m_arg4; 
};



}

}

#endif //! _CHAOS_ASYNC_METHOD_BIND_FUNC_H_

