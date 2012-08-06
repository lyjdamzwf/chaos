/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _ITOA_H_
#define _ITOA_H_

/*! 
 *  @file           itoa.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */


#include <string.h>
#include <string>

namespace chaos
{

namespace utility
{

template <typename Type>
std::string itoa(Type num_, int dec_ = 10)
{
	char buffer[256];
	char* p = buffer;

	do
	{
		*p++ = "0123456789"[num_ % dec_];
		num_ /= dec_;
		if (static_cast<size_t>(p - buffer) > sizeof(buffer)) return "";
	} while (num_);

	buffer[p - buffer] = 0;

	int i, j;
	for (i = 0, j = (int)strlen(buffer) - 1; i < j; i++, j--)
	{
		buffer[j] = buffer[i] + buffer[j];
		buffer[i] = buffer[j] - buffer[i];
		buffer[j] = buffer[j] - buffer[i];
	}

	return buffer;
}

}

}

#endif // _ITOA_H_
