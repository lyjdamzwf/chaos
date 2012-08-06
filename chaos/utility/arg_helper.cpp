/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#include <string.h>
#include <stdio.h>

#include "arg_helper.h"

/*! 
 *  @file           arg_helper.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.6.2
 *  @brief          arg helper
 *  @last changed
 *
 */

namespace chaos
{

namespace utility
{

int arg_helper_t::parse_arg(
                                arg_option_t*       options_,
                                int                 option_count_,
                                char**              argv_,
                                int                 argc_,
                                arg_pair_t**        ret_arr_,
                                int*                ret_count_
                            )
{
    int ret = 0;

    if (NULL == options_)
    {
        goto PARSE_ERR;
    }

    m_arg_options_ptr = options_;
    *ret_arr_ = m_pair_ret;
    *ret_count_ = 0;

    //! yunjie: argv_[0] 是二进制文件名
    for (int i = 1; i < argc_; ++i)
    {
        bool is_match = false;
        char* cur_arg = argv_[i];
        int cur_arg_index = i;

        //! yunjie: 进行匹配
        for (int j = 0 ; j < option_count_; ++j)
        {
            arg_option_t cur_option = options_[j];
            
            if (strlen(cur_arg) <= 1)
            {
                goto PARSE_ERR;
            }

            if ('-' != cur_arg[0])
            {
                goto PARSE_ERR;
            }

            //! yunjie: 去掉参数前的'-'
            if (0 == strcmp(&cur_arg[1], cur_option.name))
            {
                if (cur_option.has_val)
                {
                    if (cur_arg_index + 1 >= argc_)
                    {
                        goto PARSE_ERR;
                    }

                    //! yunjie: 下次取命令行参数要跳过该次参数对应的值
                    ++i;
                }

                m_pair_ret[*ret_count_].arg_index = j;
                m_pair_ret[*ret_count_].arg_val = cur_option.has_val ? argv_[cur_arg_index + 1] : NULL;
                is_match = true;
                ++*ret_count_;

                if (NULL != cur_option.handler)
                {
                    cur_option.handler(
                            j,
                            cur_option.name,
                            cur_option.has_val ? argv_[cur_arg_index + 1] : NULL
                                    );
                    break;
                }
            }
        }

        if (!is_match)
        {
            ret = -1;
        }
    }

    return ret;

PARSE_ERR:
    ret = -1;

    return ret;
}

void arg_helper_t::show_args(
                                arg_option_t*       options_,
                                int                 option_count_
                            )
{
    printf("---------------- show args begin ----------------\n");

    for (int j = 0 ; j < option_count_; ++j)
    {
        arg_option_t cur_option = options_[j];
        printf("-%s         %s\n", cur_option.name, cur_option.description);
    }

    printf("---------------- show args end ----------------\n\n");
}

}

}
