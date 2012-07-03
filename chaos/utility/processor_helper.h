/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _PROCESSOR_HELPER_H_
#define _PROCESSOR_HELPER_H_

/** 
 *  @file           processor_helper.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */

#include <sys/types.h>
#include <unistd.h>

namespace chaos
{

namespace utility
{

class processor_helper_t
{
public:
	//! yunjie: daemonize the current process
	static void daemonize();

};

}

}

#endif //! _PROCESSOR_HELPER_H_

