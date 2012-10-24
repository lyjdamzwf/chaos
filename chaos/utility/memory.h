/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_CMALLOC_H_
#define _CHAOS_CMALLOC_H_

/*!
 *  @file           chaos_malloc.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.10.23
 *  @brief
 *  @last changed
 *
 */

#include <chaos/deps/jemalloc/jemalloc.h>

namespace chaos
{

namespace utility
{

#define chaos_malloc                je_malloc
#define chaos_callos                je_calloc
#define chaos_realloc               je_realloc
#define chaos_free                  je_free
#define chaos_rallocm               je_rallocm

static const size_t jemalloc_min_in_place_expandable = 4096;

inline size_t align_to_jesize(size_t size_)
{
    if (size_ <= 64)
    {
        return 64;
    }

    if (size_ <= 512)
    {
        return (size_ + 63) & ~size_t(63);
    }

    if (size_ <= 3840)
    {
        return (size_ + 255) & ~size_t(255);
    }

    if (size_ <= 4072 * 1024)
    {
        return (size_ + 4095) & ~size_t(4095);
    }

    return (size_ + 4194303) & ~size_t(4194303);
}

#include <chaos/utility/construct.h>

template<typename T>
inline T* construct()
{
    T* ptr = (T*)chaos_malloc(sizeof(T));

    if (NULL != ptr)
    {
        try
        {
            new (ptr) T();
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }

    return ptr;
}

template <typename T>
inline void destroy(T* t_)
{
    if (NULL != t_)
    {
        t_->~T();
        chaos_free(t_);
    }
}

}

}

#endif /* _CHAOS_CMALLOC_H_ */
