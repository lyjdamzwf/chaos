/*
* Copyright 2012, Yunjie Lu.  All rights reserved.
* https://github.com/lyjdamzwf/chaos
*
* Use of this source code is governed by a BSD-style
* license that can be found in the License file.
*/

/**
*  @file           processor_helper.cpp
*  @author         yunjie.lu
*  @email          lyjdamzwf@gmail.com
*  @weibo          http://weibo.com/crazyprogramerlyj
*  @date
*  @brief          该文件由chaos_new.gen.cpp生成, 请勿直接include
*  @last changed
*
*/

template<typename T, typename A0>
inline T* construct(A0& a0)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0>
inline T* construct(const A0& a0)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1>
inline T* construct(A0& a0,A1& a1)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1>
inline T* construct(A0& a0,const A1& a1)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1>
inline T* construct(const A0& a0,A1& a1)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1>
inline T* construct(const A0& a0,const A1& a1)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(A0& a0,A1& a1,A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(A0& a0,A1& a1,const A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(A0& a0,const A1& a1,A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(A0& a0,const A1& a1,const A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(const A0& a0,A1& a1,A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(const A0& a0,A1& a1,const A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(const A0& a0,const A1& a1,A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2>
inline T* construct(const A0& a0,const A1& a1,const A2& a2)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
template<typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
inline T* construct(const A0& a0,const A1& a1,const A2& a2,const A3& a3,const A4& a4,const A5& a5,const A6& a6,const A7& a7,const A8& a8)
{
    T* ptr = (T*)chaos_malloc(sizeof(T));
    if (NULL != ptr)
    {
        try
        {
            new (ptr) T(a0,a1,a2,a3,a4,a5,a6,a7,a8);
        }
        catch (...)
        {
            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }
        }
    }
    return ptr;
}
