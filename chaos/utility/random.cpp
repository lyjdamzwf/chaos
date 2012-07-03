/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

/** 
 *  @file           random.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */

#include "random.h"

namespace chaos
{

namespace utility
{

rand_gen_t	rand_gen	= rand_gen_t((unsigned)time(NULL));

//! yunjie: 随机范围 - [start_, end_)
uint32_t rand_gen_t::get_rand(uint32_t start_, uint32_t end_)
{
	return (uint32_t)((end_ - start_) * rand_gen.rand_double()) + start_;
}

int  rand_gen_t::rand_str(char * dest_, uint32_t len_)
{
    for (uint32_t i = 0; i < len_; ++i)
    {
        int x = rand_gen_t::get_rand(0, sizeof(CCH) - 1);
        dest_[i] = CCH[x];
    }

    return 0;
}

int  rand_gen_t::rand_str(string& dest_, uint32_t len_)
{
    dest_ = "";
    dest_.reserve(len_ + 1);
    for (uint32_t i = 0; i < len_; ++i)
    {
        int x = rand_gen_t::get_rand(0, sizeof(CCH) - 1);
        dest_  += CCH[x];
    }

    return 0;
}

bool rand_gen_t::calc_probability(int rate_)
{
    if (rate_ < 0 || rate_ > 100)
    {
        return false;
    }

    int val = rand_gen_t::get_rand(0, 101);
    bool ret = val <= rate_ ? true : false ;

    return ret;
}

}

}
