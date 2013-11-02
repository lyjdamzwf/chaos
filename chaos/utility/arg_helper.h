/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_ARG_HELPER_H_
#define _CHAOS_ARG_HELPER_H_

/*!
 *  @file           arg_helper.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.6.2
 *  @brief          arg helper
 *  @last changed
 *
 */

#include <string>

namespace chaos
{

namespace utility
{

typedef                     void (*arg_handler_t) (int, const char*, const char*);

struct arg_option_t
{
    arg_option_t()
        :
            name(NULL),
            description(NULL),
            has_val(false),
            handler(NULL)
    {
    }

    arg_option_t(const char* name_, const char* des_, bool has_val_, arg_handler_t handler_)
        :
            name(name_),
            description(des_),
            has_val(has_val_),
            handler(handler_)
    {
    }

    const char*             name;
    const char*             description;
    bool                    has_val;
    arg_handler_t           handler;
};

struct arg_pair_t
{
    arg_pair_t()
        :
            arg_index(0),
            arg_val(NULL)
    {
    }

    int         arg_index;
    char*       arg_val;
};

class arg_helper_t
{
public:
    arg_helper_t()
        :
            m_arg_options_ptr(NULL)
    {
    }

    int parse_arg(
                    arg_option_t*       options_,
                    int                 option_count_,
                    char**              argv_,
                    int                 argc_,
                    arg_pair_t**        ret_arr_,
                    int*                ret_count_
                  );

    void show_args(
                    arg_option_t*       options_,
                    int                 option_count_
                );

private:
    arg_option_t*                       m_arg_options_ptr;
    arg_pair_t                          m_pair_ret[255];
};

}

}

#endif //! _CHAOS_ARG_HELPER_H_
