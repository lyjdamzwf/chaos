INCLUDES= -I$(top_srcdir)/chaos/utility \
		  -I$(top_srcdir)/chaos/log \
		  -I$(top_srcdir)/chaos/async_method \
		  -I$(top_srcdir)/chaos/thread \
		  -I$(top_srcdir)/chaos/task_service \
		  -I$(top_srcdir)/chaos/heart_beat

CXXFLAGS = -Wall -g -O2 -fPIC

noinst_LIBRARIES = libchaos_statistic.a
libchaos_statistic_a_LIBFLAGS =
libchaos_statistic_a_LIBADD =

libchaos_statistic_a_SOURCES = \
							   statistic_service.cpp
