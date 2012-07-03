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

class async_method_base_t
{
public:
    async_method_base_t() {}
    virtual ~async_method_base_t() {}
    virtual void exec() {}
};

}

}

#endif //! _CHAOS_ASYNC_METHOD_BASE_H_

