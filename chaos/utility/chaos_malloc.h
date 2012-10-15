#ifndef _CHAOS_CMALLOC_H_
#define _CHAOS_CMALLOC_H_

#include <chaos/deps/jemalloc/jemalloc.h>

namespace chaos
{

namespace utility
{

#define chaos_malloc(size)          je_malloc(size)
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

}

}

#endif /* _CHAOS_CMALLOC_H_ */
