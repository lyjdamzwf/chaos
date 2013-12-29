/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef SINGLETON_INC
#define SINGLETON_INC

/**
 *  @file           singleton.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */

#include <stdlib.h>
#include <pthread.h>

namespace chaos
{

namespace utility
{
    /**
      * usage: chaos::utility::singleton_t<your_class_name>::instance().m_member;
    **/

    template <typename Type>
    class singleton_t
    {
    public:
        static Type& instance() // Unique point of access
        {
            pthread_once(&s_pthread_once, &singleton_t::init);
            return *s_instance;
        }

    private:
        singleton_t() {}
        virtual ~singleton_t() {}

        static void init()
        {
            s_instance = new(Type)();
            atexit(destroy);
        }

        static void destroy() // Destroy the only instance
        {
            if (s_instance != 0)
            {
                delete(s_instance);
                s_instance = 0;
            }
        }

    private:
        static pthread_once_t       s_pthread_once;
        static Type*                s_instance; // The one and oly instance
    };

    template <typename Type>
    pthread_once_t singleton_t<Type >::s_pthread_once = PTHREAD_ONCE_INIT;

    template <typename Type>
    Type* singleton_t<Type >::s_instance = 0;
}

}

#endif

