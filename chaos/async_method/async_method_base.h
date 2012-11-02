/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ASYNC_METHOD_BASE_H_
#define _CHAOS_ASYNC_METHOD_BASE_H_

/*!
 *  @file           async_method_base.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.3.17
 *  @brief          base async method class
 *  @last changed   2012.3.24 by yunjie
 *
 */

#include <stdlib.h>
#include <stdint.h>

#include <iostream>

namespace chaos
{

namespace async_method
{

using namespace std;

#define COMMA_0
#define COMMA_1 ,
#define COMMA_2 ,
#define COMMA_3 ,
#define COMMA_4 ,
#define COMMA_5 ,
#define COMMA_6 ,
#define COMMA_7 ,
#define COMMA_8 ,
#define COMMA_9 ,

#define BIND_NAME_LIST_0(name)

#define BIND_NAME_LIST_1(name) \
    name##0

#define BIND_NAME_LIST_2(name) \
    name##0, name##1

#define BIND_NAME_LIST_3(name) \
    name##0, name##1, name##2

#define BIND_NAME_LIST_4(name) \
    name##0, name##1, name##2, name##3

#define BIND_NAME_LIST_5(name) \
    name##0, name##1, name##2, name##3, name##4

#define BIND_NAME_LIST_6(name) \
    name##0, name##1, name##2, name##3, name##4, name##5

#define BIND_NAME_LIST_7(name) \
    name##0, name##1, name##2, name##3, name##4, name##5, name##6

#define BIND_NAME_LIST_8(name) \
    name##0, name##1, name##2, name##3, name##4, name##5, name##6, name##7

#define BIND_NAME_LIST_9(name) \
    name##0, name##1, name##2, name##3, name##4, name##5, name##6, name##7, name##8



//! ----------------------------------------------------------------------------------------


#define BIND_FUNC_ARG_DEC_0
#define BIND_FUNC_ARG_DEC_1 B0
#define BIND_FUNC_ARG_DEC_2 B0,B1
#define BIND_FUNC_ARG_DEC_3 B0,B1,B2
#define BIND_FUNC_ARG_DEC_4 B0,B1,B2,B3
#define BIND_FUNC_ARG_DEC_5 B0,B1,B2,B3,B4
#define BIND_FUNC_ARG_DEC_6 B0,B1,B2,B3,B4,B5
#define BIND_FUNC_ARG_DEC_7 B0,B1,B2,B3,B4,B5,B6
#define BIND_FUNC_ARG_DEC_8 B0,B1,B2,B3,B4,B5,B6,B7
#define BIND_FUNC_ARG_DEC_9 B0,B1,B2,B3,B4,B5,B6,B7,B8


//! ----------------------------------------------------------------------------------------



#define BIND_CTOR_ARG_0

#define BIND_CTOR_ARG_1 \
    , const A0& a0_

#define BIND_CTOR_ARG_2 \
    , const A0& a0_, const A1& a1_

#define BIND_CTOR_ARG_3 \
    , const A0& a0_, const A1& a1_, const A2& a2_

#define BIND_CTOR_ARG_4 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_

#define BIND_CTOR_ARG_5 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_

#define BIND_CTOR_ARG_6 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_

#define BIND_CTOR_ARG_7 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_, const A6& a6_

#define BIND_CTOR_ARG_8 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_, const A6& a6_, const A7& a7_

#define BIND_CTOR_ARG_9 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_, const A6& a6_, const A7& a7_, const A8& a8_



//! ----------------------------------------------------------------------------------------



#define BIND_CTOR_LIST_0

#define BIND_CTOR_LIST_1 \
    , m_a0(a0_)

#define BIND_CTOR_LIST_2 \
    , m_a0(a0_), m_a1(a1_)

#define BIND_CTOR_LIST_3 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_)

#define BIND_CTOR_LIST_4 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_), m_a3(a3_)

#define BIND_CTOR_LIST_5 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_), m_a3(a3_), m_a4(a4_)

#define BIND_CTOR_LIST_6 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_), m_a3(a3_), m_a4(a4_), m_a5(a5_)

#define BIND_CTOR_LIST_7 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_), m_a3(a3_), m_a4(a4_), m_a5(a5_), m_a6(a6_)

#define BIND_CTOR_LIST_8 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_), m_a3(a3_), m_a4(a4_), m_a5(a5_), m_a6(a6_), m_a7(a7_)

#define BIND_CTOR_LIST_9 \
    , m_a0(a0_), m_a1(a1_), m_a2(a2_), m_a3(a3_), m_a4(a4_), m_a5(a5_), m_a6(a6_), m_a7(a7_), m_a8(a8_)



//! ----------------------------------------------------------------------------------------



#define BIND_INVOKE_LIST_0

#define BIND_INVOKE_LIST_1 \
    m_a0

#define BIND_INVOKE_LIST_2 \
    m_a0, m_a1

#define BIND_INVOKE_LIST_3 \
    m_a0, m_a1, m_a2

#define BIND_INVOKE_LIST_4 \
    m_a0, m_a1, m_a2, m_a3

#define BIND_INVOKE_LIST_5 \
    m_a0, m_a1, m_a2, m_a3, m_a4

#define BIND_INVOKE_LIST_6 \
    m_a0, m_a1, m_a2, m_a3, m_a4, m_a5

#define BIND_INVOKE_LIST_7 \
    m_a0, m_a1, m_a2, m_a3, m_a4, m_a5, m_a6

#define BIND_INVOKE_LIST_8 \
    m_a0, m_a1, m_a2, m_a3, m_a4, m_a5, m_a6, m_a7

#define BIND_INVOKE_LIST_9 \
    m_a0, m_a1, m_a2, m_a3, m_a4, m_a5, m_a6, m_a7, m_a8



//! ----------------------------------------------------------------------------------------



#define BIND_MEMBER_LIST_0

#define BIND_MEMBER_LIST_1 \
    A0 m_a0;

#define BIND_MEMBER_LIST_2 \
    A0 m_a0; A1 m_a1;

#define BIND_MEMBER_LIST_3 \
    A0 m_a0; A1 m_a1; A2 m_a2;

#define BIND_MEMBER_LIST_4 \
    A0 m_a0; A1 m_a1; A2 m_a2; A3 m_a3;

#define BIND_MEMBER_LIST_5 \
    A0 m_a0; A1 m_a1; A2 m_a2; A3 m_a3; A4 m_a4;

#define BIND_MEMBER_LIST_6 \
    A0 m_a0; A1 m_a1; A2 m_a2; A3 m_a3; A4 m_a4; A5 m_a5;

#define BIND_MEMBER_LIST_7 \
    A0 m_a0; A1 m_a1; A2 m_a2; A3 m_a3; A4 m_a4; A5 m_a5; A6 m_a6;

#define BIND_MEMBER_LIST_8 \
    A0 m_a0; A1 m_a1; A2 m_a2; A3 m_a3; A4 m_a4; A5 m_a5; A6 m_a6; A7 m_a7;

#define BIND_MEMBER_LIST_9 \
    A0 m_a0; A1 m_a1; A2 m_a2; A3 m_a3; A4 m_a4; A5 m_a5; A6 m_a6; A7 m_a7; A8 m_a8;



//! ----------------------------------------------------------------------------------------



#define BIND_ARG_LIST_0

#define BIND_ARG_LIST_1 \
    , const A0& a0_

#define BIND_ARG_LIST_2 \
    , const A0& a0_, const A1& a1_

#define BIND_ARG_LIST_3 \
    , const A0& a0_, const A1& a1_, const A2& a2_

#define BIND_ARG_LIST_4 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_

#define BIND_ARG_LIST_5 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_

#define BIND_ARG_LIST_6 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_

#define BIND_ARG_LIST_7 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_, const A6& a6_

#define BIND_ARG_LIST_8 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_, const A6& a6_, const A7& a7_

#define BIND_ARG_LIST_9 \
    , const A0& a0_, const A1& a1_, const A2& a2_, const A3& a3_, const A4& a4_, const A5& a5_, const A6& a6_, const A7& a7_, const A8& a8_



//! ----------------------------------------------------------------------------------------



#define BIND_NEW_CTOR_LIST_0

#define BIND_NEW_CTOR_LIST_1 \
        , a0_

#define BIND_NEW_CTOR_LIST_2 \
        , a0_, a1_

#define BIND_NEW_CTOR_LIST_3 \
        , a0_, a1_, a2_

#define BIND_NEW_CTOR_LIST_4 \
        , a0_, a1_, a2_, a3_

#define BIND_NEW_CTOR_LIST_5 \
        , a0_, a1_, a2_, a3_, a4_

#define BIND_NEW_CTOR_LIST_6 \
        , a0_, a1_, a2_, a3_, a4_, a5_

#define BIND_NEW_CTOR_LIST_7 \
        , a0_, a1_, a2_, a3_, a4_, a5_, a6_

#define BIND_NEW_CTOR_LIST_8 \
        , a0_, a1_, a2_, a3_, a4_, a5_, a6_, a7_

#define BIND_NEW_CTOR_LIST_9 \
        , a0_, a1_, a2_, a3_, a4_, a5_, a6_, a7_, a8_

class async_method_base_t
{
public:
    async_method_base_t() {}
    virtual ~async_method_base_t() {}
    virtual void exec() = 0;
    virtual async_method_base_t* clone() = 0;
};

}

}

#endif //! _CHAOS_ASYNC_METHOD_BASE_H_

