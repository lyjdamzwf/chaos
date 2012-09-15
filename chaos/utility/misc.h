/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_MISC_H_
#define _CHAOS_MISC_H_

#include <vector>

namespace chaos
{

namespace utility
{

#define SAFE_DELETE(x) { if (NULL != x) { delete(x); (x) = NULL; } }
#define SAFE_DELETE_ARR(x) { if (NULL != x) { delete [] (x); (x) = NULL; } }

#define GET_LONG_HIGH_PART(value)           (value >> 32)
#define GET_LONG_LOW_PART(value)            (value & 0xFFFFFFFF)
#define PARSE_TO_LONG(high, low)            (uint64_t)(((uint64_t)high) << 32 | low)

#define RED_COLOR_HEAD              "\033[0;31m"
#define YELLOW_COLOR_HEAD           "\033[1;33m"
#define GREEN_COLOR_HEAD            "\033[32m"
#define NONE_COLOR_HEAD             "\033[0m"
#define COLOR_END                   "\033[0m"

#define STRERR                      strerror(errno)

}

}

#endif //! _CHAOS_MISC_H_
