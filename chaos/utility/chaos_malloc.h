#ifndef _CHAOS_CMALLOC_H_
#define _CHAOS_CMALLOC_H_

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

#define TEMPLATE_ARG_LIST_0 typename T
#define TEMPLATE_ARG_LIST_1 typename T, typename A0
#define TEMPLATE_ARG_LIST_2 typename T, typename A0, typename A1
#define TEMPLATE_ARG_LIST_3 typename T, typename A0, typename A1, typename A2
#define TEMPLATE_ARG_LIST_4 typename T, typename A0, typename A1, typename A2, typename A3
#define TEMPLATE_ARG_LIST_5 typename T, typename A0, typename A1, typename A2, typename A3, typename A4
#define TEMPLATE_ARG_LIST_6 typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
#define TEMPLATE_ARG_LIST_7 typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
#define TEMPLATE_ARG_LIST_8 typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
#define TEMPLATE_ARG_LIST_9 typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8

#define FUNC_ARG_LIST_0
#define FUNC_ARG_LIST_1 A0 a0
#define FUNC_ARG_LIST_2 A0 a0, A1 a1
#define FUNC_ARG_LIST_3 A0 a0, A1 a1, A2 a2
#define FUNC_ARG_LIST_4 A0 a0, A1 a1, A2 a2, A3 a3
#define FUNC_ARG_LIST_5 A0 a0, A1 a1, A2 a2, A3 a3, A4 a4
#define FUNC_ARG_LIST_6 A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5
#define FUNC_ARG_LIST_7 A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6
#define FUNC_ARG_LIST_8 A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7
#define FUNC_ARG_LIST_9 A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8

#define CTOR_ARG_LIST_0
#define CTOR_ARG_LIST_1 a0
#define CTOR_ARG_LIST_2 a0, a1
#define CTOR_ARG_LIST_3 a0, a1, a2
#define CTOR_ARG_LIST_4 a0, a1, a2, a3
#define CTOR_ARG_LIST_5 a0, a1, a2, a3, a4
#define CTOR_ARG_LIST_6 a0, a1, a2, a3, a4, a5
#define CTOR_ARG_LIST_7 a0, a1, a2, a3, a4, a5, a6
#define CTOR_ARG_LIST_8 a0, a1, a2, a3, a4, a5, a6, a7
#define CTOR_ARG_LIST_9 a0, a1, a2, a3, a4, a5, a6, a7, a8

#define GEN_CHAOS_NEW(arg_num) \
template <TEMPLATE_ARG_LIST_##arg_num> \
inline T* chaos_new(FUNC_ARG_LIST_##arg_num) \
{ \
    T* ptr = (T*)chaos_malloc(sizeof(T)); \
    if (NULL != ptr) \
    { \
        try \
        { \
            new (ptr) T(CTOR_ARG_LIST_##arg_num); \
        } \
        catch (std::exception& e) \
        { \
            if (NULL != ptr) \
            { \
                chaos_free(ptr); \
                ptr = NULL; \
            } \
        } \
        catch (...) \
        { \
            if (NULL != ptr) \
            { \
                chaos_free(ptr); \
                ptr = NULL; \
            } \
        } \
    } \
    \
    return ptr; \
}

GEN_CHAOS_NEW(0)
GEN_CHAOS_NEW(1)
GEN_CHAOS_NEW(2)
GEN_CHAOS_NEW(3)
GEN_CHAOS_NEW(4)
GEN_CHAOS_NEW(5)
GEN_CHAOS_NEW(6)
GEN_CHAOS_NEW(7)
GEN_CHAOS_NEW(8)
GEN_CHAOS_NEW(9)

template <typename T>
inline void chaos_delete(T* t_)
{
    if (NULL == t_)
    {
        return;
    }

    t_->~T();
    chaos_free(t_);
}

}

}

#endif /* _CHAOS_CMALLOC_H_ */
