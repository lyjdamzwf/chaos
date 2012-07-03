INCLUDES= -I$(top_srcdir)/chaos/utility \
		  -I$(top_srcdir)/chaos/log \
		  -I$(top_srcdir)/chaos/async_method \
		  -I$(top_srcdir)/chaos/thread \
		  -I$(top_srcdir)/chaos/task_service \
		  -I$(top_srcdir)/chaos/heart_beat

CXXFLAGS = -Wall -g -O2 -fPIC

noinst_LIBRARIES = libchaos_network.a
libchaos_network_a_LIBFLAGS =
libchaos_network_a_LIBADD =

libchaos_network_a_SOURCES = \
						  acceptor_service.cpp \
						  work_service_group.cpp \
						  connection.cpp \
						  tcp_service.cpp \
						  work_service.cpp \
						  msg_buffer.cpp \
						  buffer_list.cpp
