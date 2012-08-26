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
 *  @brief
 *  @last changed
 *
 */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <string>
#include <iostream>
using namespace std;

#include <chaos/utility/processor_helper.h>

namespace chaos
{

namespace utility
{

//! daemonize the current process
void processor_helper_t::daemonize()
{
	pid_t pid, sid;

	if ((pid = fork()) < 0)
    {
		cerr<<"processor_helper_t::daemonize fork failed:"<<strerror(errno)<<endl;
		exit(EXIT_FAILURE);
	}
	else if(pid != 0)
    {
	   exit(EXIT_SUCCESS);
    }

	/* chdir to install bin chdir::TODO*/

	/* set a new session id*/
	sid = setsid();
	if (sid < 0)
    {
		cout<<"processor_helper_t::daemonize setsid failed:"<<strerror(errno)<<endl;
		exit (EXIT_FAILURE);
	}

	/* ensure all files created by itself are accessible */
	umask (022);

    /*close all descriptors */
    for (int i = getdtablesize() - 1; i >= 0; --i)
    {
        (void)close(i);
    }
    //! dup the base io
    int fd_dev = open("/dev/null", O_RDWR);
    (void)dup(fd_dev);
    (void)dup(fd_dev);
}

}

}


