INCLUDES= -I$(top_srcdir)/chaos/utility \
		  -I$(top_srcdir)/chaos/log \
		  -I$(top_srcdir)/chaos/async_method \
		  -I$(top_srcdir)/chaos/thread

CXXFLAGS = -Wall -g -O2 -fPIC

noinst_LIBRARIES = libchaos_task_service.a
libchaos_task_service_a_LIBFLAGS =
libchaos_task_service_a_LIBADD =

libchaos_task_service_a_SOURCES = \
						  task_service.cpp \
						  timer_manager.cpp \
						  io_multiplex_handler.cpp \
						  task_service_group.cpp
