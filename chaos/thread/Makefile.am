INCLUDES= -I$(top_srcdir)/chaos/utility \
		  -I$(top_srcdir)/chaos/log \
		  -I$(top_srcdir)/chaos/task_service \
		  -I$(top_srcdir)/chaos/async_method

CXXFLAGS = -Wall -g -O2 -fPIC

noinst_LIBRARIES = libchaos_thread.a
libchaos_thread_a_LIBFLAGS =
libchaos_thread_a_LIBADD =

libchaos_thread_a_SOURCES = \
						  thread.cpp \
						  thread_group.cpp
