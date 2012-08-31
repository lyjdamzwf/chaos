/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_SIGNAL_HANDLER_H_
#define _CHAOS_SIGNAL_HANDLER_H_

/**
 *  @file           signal_handler.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */

#include <signal.h>
#include <stddef.h>

#include <map>
using namespace std;

namespace chaos
{

namespace utility
{

class signal_handler_t
{
public:

    //! yunjie: 注册的信号callback函数
    typedef                                                 void (*signal_callback_func_t)();
    typedef map<unsigned int, signal_callback_func_t>       m_signal_func_map_t;

public:

    signal_handler_t();

    ~signal_handler_t();

    //! yunjie: 阻塞当前线程对所有信号的接受
    int block_all_signal();

    int register_quit_signal(unsigned int signal_num_);

    int register_signal(unsigned int signal_num_, signal_callback_func_t signal_callback_func_ = NULL);

    int event_loop();

private:

    sigset_t                        m_wait_mask;            //! yunjie: 信号掩码
    m_signal_func_map_t             m_signal_func_map;
};

}

}

#endif //! _CHAOS_SIGNAL_HANDLER_H_


