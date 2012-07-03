INCLUDES= \
		  -I$(top_srcdir)/chaos/utility \
		  -I$(top_srcdir)/chaos/log \
		  -I$(top_srcdir)/chaos/thread \
		  -I$(top_srcdir)/chaos/async_method \
		  -I$(top_srcdir)/chaos/task_service \
		  -I$(top_srcdir)/chaos/network \
		  -I$(top_srcdir)/chaos/heart_beat \
		  -I$(top_srcdir)/chaos/test


CXXFLAGS += -Wall -static -g -O2 -fPIC

bin_PROGRAMS = chaos_echo_server

chaos_echo_server_SOURCES = chaos.cpp

chaos_echo_server_LDADD = -lpthread	\
			  $(top_srcdir)/chaos/network/libchaos_network.a \
			  $(top_srcdir)/chaos/task_service/libchaos_task_service.a \
			  $(top_srcdir)/chaos/thread/libchaos_thread.a \
			  $(top_srcdir)/chaos/log/libchaos_log.a \
			  $(top_srcdir)/chaos/utility/libchaos_utility.a
