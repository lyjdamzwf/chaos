/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_LOG_MISC_H_
#define _CHAOS_LOG_MISC_H_

/*! 
 *  @file           log_misc.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.6
 *  @brief          log misc
 *  @last changed
 *
 */

#include <string>
#include <vector>

#ifdef HAVE_CONFIG_H
#include <chaos/conf.h>
#endif

#include <chaos/utility/singleton.h>
#include <chaos/log/log.h>

/**
#define ENABLE_LOG_FATAL
#define ENABLE_LOG_ERROR
#define ENABLE_LOG_WARN
#define ENABLE_LOG_INFO
#define ENABLE_LOG_TRACE
#define ENABLE_LOG_DEBUG
*/

//! yunjie: log modules begin
#ifndef THREAD_MODULE
#define THREAD_MODULE               "THREAD_MODULE"
#endif

#ifndef TASK_SERVICE_MODULE
#define TASK_SERVICE_MODULE         "TASK_SERVICE_MODULE"
#endif

#ifndef TIMER_MANAGER_MODULE
#define TIMER_MANAGER_MODULE        "TIMER_MANAGER_MODULE"
#endif

#ifndef IO_MULTIPLEX_MODULE
#define IO_MULTIPLEX_MODULE         "IO_MULTIPLEX_MODULE"
#endif

#ifndef ACCEPTOR_SERVICE_MODULE
#define ACCEPTOR_SERVICE_MODULE     "ACCEPTOR_SERVICE_MODULE"
#endif

#ifndef WORK_SERVICE_MODULE
#define WORK_SERVICE_MODULE         "WORK_SERVICE_MODULE"
#endif

#ifndef TCP_SERVICE_MODULE
#define TCP_SERVICE_MODULE          "TCP_SERVICE_MODULE"
#endif

#ifndef CONNECTION_MODULE
#define CONNECTION_MODULE           "CONNECTION_MODULE"
#endif

#ifndef HEART_BEAT_MOUDLE
#define HEART_BEAT_MOUDLE           "HEART_BEAT_MOUDLE"
#endif

#ifndef STATISTIC_MOUDLE
#define STATISTIC_MOUDLE            "STATISTIC_MOUDLE"
#endif

#ifndef CONNECTOR_SERVICE
#define CONNECTOR_SERVICE           "CONNECTOR_SERVICE"
#endif

//! yunjie: log modules end


namespace chaos
{

namespace log
{

using namespace std;
using namespace chaos::utility;

#ifdef ENABLE_LOG_FATAL
#define LOGFATAL(x) singleton_t<log_t>::instance()._logfatal x
#else
#define LOGFATAL(x) {}
#endif

#ifdef ENABLE_LOG_ERROR
#define LOGERROR(x) singleton_t<log_t>::instance()._logerror x
#else
#define LOGERROR(x) {}
#endif

#ifdef ENABLE_LOG_WARN
#define LOGWARN(x) singleton_t<log_t>::instance()._logwarn x
#else
#define LOGWARN(x) {}
#endif

#ifdef ENABLE_LOG_INFO
#define LOGINFO(x) singleton_t<log_t>::instance()._loginfo x
#else
#define LOGINFO(x) {}
#endif

#ifdef ENABLE_LOG_TRACE
#define LOGTRACE(x) singleton_t<log_t>::instance()._logtrace x
#else
#define LOGTRACE(x) {}
#endif

#ifdef ENABLE_LOG_DEBUG
#define LOGDEBUG(x) singleton_t<log_t>::instance()._logdebug x
#else
#define LOGDEBUG(x) {}
#endif


int init_log(const std::string& path,
			 const std::string& file,
			 const int	flag_print_file,
			 const int	flag_print_screen,
			 const int  flag_log_level,
			 const std::vector<std::string>& modules,
             log_t::print_screen_callback_t screen_callback_ = NULL,
             log_t::print_file_callback_t file_callback = NULL,
			 const int  max_line = 100000,
			 const int  maz_size = 5000000);

}

}

#endif //! _CHAOS_LOG_MISC_H_
