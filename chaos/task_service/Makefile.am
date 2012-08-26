CXXFLAGS = -Wall -g -O2 -fPIC

## 安装根目录
chaosdir=$(prefix)/chaos-@chaos_ver@

## 安装库目录
libdir=$(chaosdir)/lib

lib_LIBRARIES = libchaos_task_service.a
libchaos_task_service_a_LIBFLAGS =
libchaos_task_service_a_LIBADD =

libchaos_task_service_a_SOURCES = \
						  task_service.cpp \
						  timer_manager.cpp \
						  io_multiplex_handler.cpp \
						  task_service_group.cpp
