/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_LOG_H_
#define _CHAOS_LOG_H_

/*!
 *  @file           log.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.6
 *  @brief          log
 *  @last changed
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>

#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


namespace chaos
{
namespace task_service
{
    class task_service_t;
}
}

namespace chaos
{

namespace log
{

using namespace std;

enum
{
    LF_FATAL = 0,
    LF_ERROR,
    LF_WARN,
    LF_INFO,
    LF_TRACE,
    LF_DEBUG,
};

struct module_t
{
    module_t()
    :
        log_level(LF_DEBUG)
    {}

    module_t(const string& n_, int l_)
    :
        name(n_),
        log_level(l_)
    {}


    bool operator<(const module_t& rhs_) const
    {
        return name < rhs_.name;
    }

    string      name;
    int         log_level;
};

class log_t
{
public:
    log_t();
    ~log_t();

    //! 设置日志目录
    int set_path(const char *path);

    //! 设置日志文件名(不包括路径)
    int set_filename(const char *filename);

    //! 设置单个日志文件最大行数
    int set_maxline(int maxline);

    //! 设置单个日志文件最大文件大小
    int set_maxsize(int maxsize);

    //! 设置日志模块
    int enable_log_module(const char* module_, bool enable_flag_, int log_level_ = LF_DEBUG);

    //! 设置是否写屏
    int enable_print_screen(bool enable_flag);

    //! 设置是否打印到文件
    int enable_print_file(bool enable_flag);

    int open();

    int close();

    int _logfatal(const char* module, const char* fmt, ...);
    int _logerror(const char* module, const char* fmt, ...);
    int _logwarn(const char* module, const char* fmt, ...);
    int _loginfo(const char* module, const char* fmt, ...);
    int _logtrace(const char* module, const char* fmt, ...);
    int _logdebug(const char* module, const char* fmt, ...);

    void handle_print_screen(const std::string& mesg);
    void handle_print_file(const std::string& text);

private:
    int check_module(const char* module, int log_level_);

    const char* get_color_head_by_level(int log_level_);

    int format_log_head(char *log_head, const char* module, int level, struct tm *tmp);

    //! 记录一行日志
    int log(const char* module, int level, const char* fmt, va_list ap);


private:
    //! 每行日志最大长度
    static const int        MAX_LOG_LINE = 102400;

    bool                    m_opened;
    //! 日志目录
    char                    m_path[1024];

    //! 日志文件名(不包括路径)
    char                    m_filename[1024];

    //! 单个日志文件最大行数
    int                     m_maxline;

    //! 单个日志文件最大文件大小
    int                     m_maxsize;

    //! 是否写屏
    bool                    m_print_screen_flag;

    //! 是否写文件
    bool                    m_print_file_flag;

    //! 但前日期
    int                     m_cur_year;
    int                     m_cur_mon;
    int                     m_cur_mday;

    //! 当天日志文件序号
    int                     m_cur_sn;

    //! 当前日志行数
    int                     m_cur_line;

    //! 当前日志大小
    int                     m_cur_size;

    //! 日志级别描述
    static const char*      m_log_level_desp[];

    chaos::task_service::task_service_t                *m_task_service;
    std::ofstream                                       m_ofstream;
    std::set<module_t>                                  m_modules;
};

}

}

#endif

