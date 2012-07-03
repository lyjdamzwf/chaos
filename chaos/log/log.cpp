/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

/*! 
 *  @file           log.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.6
 *  @brief          log
 *  @last changed
 *
 */

#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/syscall.h>

#include "utility_inc.h"
using namespace chaos::utility;

#include "log.h"

namespace chaos
{

namespace log
{

#define gettid() syscall(SYS_gettid)

const char* log_t::m_log_level_desp[] =
{
    "FATAL",
    "ERROR",
    "WARN ",
    "INFO ",
    "TRACE",
    "DEBUG"
};

log_t::log_t()
{
    m_opened = false;
    memset(m_path, 0, sizeof(m_path));
    memset(m_filename, 0, sizeof(m_filename));
    m_maxline = 50000;      //! yunjie: 单文件最大50000行 
    m_maxsize = 1024000;    //! yunjie: 单文件最大100M

    m_log_level_flags = 0;

    m_print_screen_flag = false;
    m_print_file_flag = false;

    m_cur_year = 0;
    m_cur_mon = 0;
    m_cur_mday = 0;

    m_cur_sn = 0;
    m_cur_line = 0;
    m_cur_size = 0;

    m_print_screen_callback = NULL;
    m_print_file_callback = NULL;
}

log_t::~log_t()
{
    close();
}

int log_t::set_path(const char *path)
{
    strcpy(m_path, path);

    int l = strlen(m_path);
    if ('/' == m_path[l - 1])
    {
        m_path[l - 1] = 0;
    }

    return 0;
}

int log_t::set_filename(const char *filename)
{
    strcpy(m_filename, filename);
    return 0;
}

int log_t::set_maxline(int maxline)
{
    m_maxline = maxline;
    return 0;
}

int log_t::set_maxsize(int maxsize)
{
    m_maxsize = maxsize;
    return 0;
}

//! 设置日志模块
int log_t::enable_log_module(const char* module, bool enable_flag)
{
    if (enable_flag)
    {
        enable_modules_.insert(module);
    }
    else
    {
        enable_modules_.erase(module);
    }

    return 0;
}

int log_t::enable_log_level(unsigned int log_level_flags, bool enable_flag)
{
    if (true == enable_flag)
    {
        if (LOG_FLAG(ALL_LOG_LEVEL) == log_level_flags)
        {
            unsigned int z = 0;
            m_log_level_flags = ~z;
        }

        m_log_level_flags = m_log_level_flags | log_level_flags;
    }
    else
    {
        if (LOG_FLAG(ALL_LOG_LEVEL) == log_level_flags)
        {
            m_log_level_flags = 0;
        }

        m_log_level_flags = m_log_level_flags & (~log_level_flags);
    }

    return 0;
}

int log_t::enable_print_screen(bool enable_flag)
{
    m_print_screen_flag = enable_flag;
    return 0;
}

int log_t::enable_print_file(bool enable_flag)
{
    m_print_file_flag = enable_flag;
    return 0;
}

int log_t::set_print_screen_callback(print_screen_callback_t callback_)
{
    m_print_screen_callback = callback_;

    return 0;
}

int log_t::set_print_file_callback(print_file_callback_t callback_)
{
    m_print_file_callback = callback_;

    return 0;
}

int log_t::open()
{
    if(m_opened) return 0;

    time_t timep = time(NULL);
    struct tm *tmp = localtime(&timep);

    m_cur_year = tmp->tm_year;
    m_cur_mon = tmp->tm_mon;
    m_cur_mday = tmp->tm_mday;
    m_cur_sn = 0;
    m_cur_line = 0;
    m_cur_size = 0;

    char file[1024];

    int rc = access(m_path, F_OK);
    if (0 != rc)
    {   
        // 目录不存在,创建
        rc = mkdir(m_path, 0777);
        if (rc != 0)
        {
            std::cout << "log_t::open() mkdir=" << m_path << " failed:" << strerror(errno) << std::endl;
            return -1;
        }
    }

    sprintf(file, "%s/%d-%d-%d", m_path, m_cur_year + 1900, m_cur_mon + 1, m_cur_mday);
    rc = access(file, F_OK);
    if (0 != rc)
    {   
        // 目录不存在,创建
        rc = mkdir(file, 0777);
        if (rc != 0)
        {
            std::cout << "log_t::open() mkdir=" << m_path << " failed:" << strerror(errno) << std::endl;
            return -1;
        }
    }

    while (true)
    {
        sprintf(file, "%s/%d-%d-%d/%s.%d", m_path, m_cur_year + 1900, m_cur_mon + 1, m_cur_mday, m_filename, m_cur_sn);
        int rc = access(file, F_OK);
        if (0 == rc)
        {
            m_cur_sn++;
            continue;
        }
        break;
    }

    ofstream_.open(file);

    m_opened = true;

    return 0;
}

int log_t::close()
{
    if (!m_opened)
    {
        return 0;
    }

    enable_modules_.clear();

    return 0;
}


int log_t::_logfatal(const char* module, const char* fmt, ...)
{
    if (!m_opened) return -1;

    va_list vl;
    va_start(vl, fmt);
    int rc = log(module, LF_FATAL, fmt, vl);
    va_end(vl);

    return rc;
}

int log_t::_logerror(const char* module, const char* fmt, ...)
{
    if (!m_opened) return -1;

    va_list vl;
    va_start(vl, fmt);
    int rc = log(module, LF_ERROR, fmt, vl);
    va_end(vl);

    return rc;
}

int log_t::_logwarn(const char* module, const char* fmt, ...)
{
    if (!m_opened) return -1;

    va_list vl;
    va_start(vl, fmt);
    int rc = log(module, LF_WARN, fmt, vl);
    va_end(vl);

    return rc;
}

int log_t::_loginfo(const char* module, const char* fmt, ...)
{
    if (!m_opened) return -1;

    va_list vl;
    va_start(vl, fmt);
    int rc = log(module, LF_INFO, fmt, vl);
    va_end(vl);

    return rc;
}

int log_t::_logtrace(const char* module, const char* fmt, ...)
{
    if (!m_opened) return -1;

    va_list vl;
    va_start(vl, fmt);
    int rc = log(module, LF_TRACE, fmt, vl);
    va_end(vl);

    return rc;
}

int log_t::_logdebug(const char* module, const char* fmt, ...)
{
    if (!m_opened) return -1;

    va_list vl;
    va_start(vl, fmt);
    int rc = log(module, LF_DEBUG, fmt, vl);
    va_end(vl);

    return rc;
}

int log_t::log(const char* module, int level, const char* fmt, va_list ap)
{
    int rc;
    rc = check_module(module);
    if(rc) return rc;

    rc = check_log_level(level);
    if (0 != rc) return rc;

    time_t timep = time(NULL);
    struct tm *tmp = localtime(&timep);

    char logmsg[MAX_LOG_LINE];
    format_log_head(logmsg, module, level, tmp);

    int len = strlen(logmsg);
    vsnprintf(logmsg + len, MAX_LOG_LINE - len - 2 - strlen(COLOR_END), fmt, ap);

    strcat(logmsg, "\n");
    strcat(logmsg, COLOR_END);
    logmsg[MAX_LOG_LINE - 1] = 0;

    std::ostringstream os;
    os << logmsg;

    if (m_print_screen_flag)
    {
        if (NULL != m_print_screen_callback)
        {
            (*m_print_screen_callback)(os.str());
        }
        else
        {
            handle_print_screen(os.str());
        }
    }

    if (m_print_file_flag)
    {
        if (NULL != m_print_file_callback)
        {
            (*m_print_file_callback)(os.str());
        }
        else
        {
            handle_print_file(os.str());
        }
    }
    return 0;
}

int log_t::check_module(const char* module)
{
    if (enable_modules_.find(module) != enable_modules_.end())
    {
        return 0;
    }
    return -1;
}

int log_t::check_log_level(int log_level)
{
    if (0 != (m_log_level_flags & LOG_FLAG(log_level)))
    {
        return 0;
    }

    return -1;
}


const char* log_t::get_color_head_by_level(int log_level_)
{
    switch (log_level_)
    {
        case LF_FATAL:
            return RED_COLOR_HEAD;
        case LF_ERROR:
            return RED_COLOR_HEAD;
        case LF_WARN:
            return YELLOW_COLOR_HEAD;
        case LF_INFO:
            return GREEN_COLOR_HEAD;
        case LF_DEBUG:
            return GREEN_COLOR_HEAD;
        default:
            return NONE_COLOR_HEAD;
    }
}

int log_t::format_log_head(char *log_head, const char* module, int level, struct tm *tmp)
{
    struct timeval curtm;
    gettimeofday(&curtm, NULL);

    sprintf(log_head, "%04d%02d%02d %02d:%02d:%02d.%06ld %s%s [%ld] [%s] ",
        tmp->tm_year + 1900,
        tmp->tm_mon + 1,
        tmp->tm_mday,
        tmp->tm_hour,
        tmp->tm_min,
        tmp->tm_sec,
        curtm.tv_usec /* 1000 */,
        get_color_head_by_level(level),
        m_log_level_desp[level],
        gettid(),
        module
        );

    return 0;
}

void log_t::handle_print_screen(const std::string& mesg)
{
    std::cout << mesg;
}

void log_t::handle_print_file(const std::string& mesg)
{
    time_t timep = time(NULL);
    struct tm *tmp = localtime(&timep);

    // yunjie: 日期变化, 建立新的日期目录
    if ((m_cur_year != tmp->tm_year) || (m_cur_mon != tmp->tm_mon) || (m_cur_mday != tmp->tm_mday))
    {
        ofstream_.close();
        ofstream_.clear();

        m_cur_year = tmp->tm_year;
        m_cur_mon = tmp->tm_mon;
        m_cur_mday = tmp->tm_mday;

        m_cur_sn = 0;
        m_cur_line = 0;
        m_cur_size = 0;

        char file[1024];
        sprintf(file, "%s/%d-%d-%d", m_path, m_cur_year + 1900, m_cur_mon + 1, m_cur_mday);
        mkdir(file, 0777);

        sprintf(file, "%s/%d-%d-%d/%s.%d", m_path, m_cur_year + 1900, m_cur_mon + 1, m_cur_mday, m_filename, m_cur_sn);
        ofstream_.open(file);
    }

    ofstream_ << mesg;
    ofstream_.flush();

    // yunjie: 文件行数或者大小达到限制, 建立新文件
    if ((m_cur_line >= m_maxline) || (m_cur_size > m_maxsize))
    {
        ofstream_.close();
        ofstream_.clear();

        m_cur_sn++;
        m_cur_line = 0;
        m_cur_size = 0;

        char file[1024];
        sprintf(file, "%s/%d-%d-%d/%s.%d", m_path, m_cur_year + 1900, m_cur_mon + 1, m_cur_mday, m_filename, m_cur_sn);
        ofstream_.open(file);
    }

    m_cur_line += 1;
    m_cur_size += mesg.length();
}

}

}
