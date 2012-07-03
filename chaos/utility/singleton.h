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
            if (s_instance == 0)
            {
                s_instance = new(Type)();
                atexit(destroy);
            }
            return *s_instance;
        }
    protected:
        singleton_t() {}
        virtual ~singleton_t() {}
    private:
        static void destroy() // Destroy the only instance
        {
            if (s_instance != 0)
            {
                delete(s_instance);
                s_instance = 0;
            }
        }
        static Type* volatile s_instance; // The one and oly instance
    };

    template <typename Type>
    Type* volatile singleton_t<Type >::s_instance = 0;


}

}

#endif

