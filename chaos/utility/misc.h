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

class memory_holder_t
{
public:
    memory_holder_t()
        :
            m_rel_flag(true)
    {
    }

    virtual ~memory_holder_t() {}
    virtual void release() = 0;

    bool get_rel_flag() const { return m_rel_flag; }
    void set_rel_flag(bool flag_) { m_rel_flag = flag_; }

private:
    bool            m_rel_flag;
};

class memory_holder_safe_free_t
{
public:
    memory_holder_safe_free_t(memory_holder_t* t_)
        :
            m_t(t_),
            m_rel_flag(true)
    {
    }

    memory_holder_safe_free_t(memory_holder_t* t_, bool rel_flag_)
        :
            m_t(t_),
            m_rel_flag(rel_flag_)
    {
    }

    ~memory_holder_safe_free_t()
    {
        if (m_rel_flag && NULL != m_t && m_t->get_rel_flag())
        {
            m_t->release();
        }
    }

    memory_holder_t*                    m_t;
    bool                                m_rel_flag;
};

template <typename T>
class memory_holder_safe_free_container_t
{
public:
    memory_holder_safe_free_container_t(T* container_, bool rel_flag_)
        :
            m_container(container_),
            m_rel_flag(rel_flag_)
    {
    }

    ~memory_holder_safe_free_container_t()
    {
        if (m_rel_flag && NULL != m_container)
        {
            for (
                    typename T::iterator it = m_container->begin();
                    it != m_container->end();
                    ++it
                )
            {
                if (it->get_rel_flag())
                {
                    it->release();
                }
            }
        }
    }

private:
    T*                  m_container;
    bool                m_rel_flag;
};

#define MH_SAFE_FREE(x, rel_flag) \
memory_holder_safe_free_t __##1104##x##1121##__(&x, rel_flag);

#define MH_SAFE_FREE_CTN(ctn_t, x, rel_flag) \
memory_holder_safe_free_container_t<ctn_t> __##1104##x##1121##__(&x, rel_flag);

#define EXCEPTION_BEGIN \
try \
{

#define EXCEPTION_END(module, ext)   \
} \
catch (std::exception& e) \
{ \
    LOGWARN((module, "%s, %s, exception:[%s]", __PRETTY_FUNCTION__, ext, e.what())); \
} \
catch (...) \
{ \
    LOGWARN((module, "%s, %s, unknown exception", __PRETTY_FUNCTION__, ext)); \
}

}

}

#endif //! _CHAOS_MISC_H_
