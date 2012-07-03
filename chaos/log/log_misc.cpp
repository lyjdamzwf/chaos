/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */
 
/*! 
 *  @file           log_misc.cpp
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2012.4.6
 *  @brief          log misc
 *  @last changed
 *
 */

#include "log_misc.h"

namespace chaos
{

namespace log
{

int init_log(const std::string& path,
			 const std::string& file,
			 const int	flag_print_file,
			 const int	flag_print_screen,
			 const int  flag_log_level,
			 const std::vector<std::string>& modules,
             log_t::print_screen_callback_t screen_callback_,
             log_t::print_file_callback_t file_callback_,
			 const int  max_line,
			 const int  maz_size)
{
	singleton_t<log_t>::instance().set_path(path.c_str());
	singleton_t<log_t>::instance().set_filename(file.c_str());
	singleton_t<log_t>::instance().set_maxline(max_line);
	singleton_t<log_t>::instance().set_maxsize(maz_size);
	if(flag_print_file)	singleton_t<log_t>::instance().enable_print_file(true);	
	if(flag_print_screen)	singleton_t<log_t>::instance().enable_print_screen(true);
	if( flag_log_level >=1 ) singleton_t<log_t>::instance().enable_log_level(LOG_FLAG(LF_FATAL), true);
	if( flag_log_level >=2 ) singleton_t<log_t>::instance().enable_log_level(LOG_FLAG(LF_ERROR), true);
	if( flag_log_level >=3 ) singleton_t<log_t>::instance().enable_log_level(LOG_FLAG(LF_WARN), true);
	if( flag_log_level >=4 ) singleton_t<log_t>::instance().enable_log_level(LOG_FLAG(LF_INFO), true);
	if( flag_log_level >=5 ) singleton_t<log_t>::instance().enable_log_level(LOG_FLAG(LF_TRACE), true);
	if( flag_log_level >=6 ) singleton_t<log_t>::instance().enable_log_level(LOG_FLAG(LF_DEBUG), true);
    singleton_t<log_t>::instance().set_print_screen_callback(screen_callback_);
    singleton_t<log_t>::instance().set_print_file_callback(file_callback_);
	for(std::size_t i = 0 ; i < modules.size() ; i++)
	{
		singleton_t<log_t>::instance().enable_log_module(modules[i].c_str(), true);
	}
	return singleton_t<log_t>::instance().open();
}

}

}
