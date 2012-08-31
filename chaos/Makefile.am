SUBDIRS= thread utility task_service log network statistic

CXXFLAGS = -Wall -g -O2 -fPIC

lib_LIBRARIES = libchaos.a

## 安装根目录
chaosdir=$(prefix)/chaos-@chaos_ver@

## 安装库目录
libdir=$(chaosdir)/lib

## 安装头文件目录
includedir=$(chaosdir)/include/chaos
async_methoddir=$(includedir)/async_method
heart_beatdir=$(includedir)/heart_beat
logdir=$(includedir)/log
networkdir=$(includedir)/network
statisticdir=$(includedir)/statistic
task_servicedir=$(includedir)/task_service
threaddir=$(includedir)/thread
utilitydir=$(includedir)/utility

include_HEADERS= *.h
async_method_HEADERS=async_method/*.h
heart_beat_HEADERS=heart_beat/*.h
log_HEADERS=log/*.h
network_HEADERS=network/*.h
statistic_HEADERS=statistic/*.h
task_service_HEADERS=task_service/*.h
thread_HEADERS=thread/*.h
utility_HEADERS=utility/*.h

libchaos_a_LIBFLAGS =
libchaos_a_LIBADD =

libchaos_a_SOURCES = \
					 log/log.cpp \
					 log/log_misc.cpp \
					 network/acceptor_service.cpp \
					 network/buffer_list.cpp \
					 network/connection.cpp \
					 network/msg_buffer.cpp \
					 network/tcp_service.cpp \
					 network/work_service.cpp \
					 network/work_service_group.cpp \
					 statistic/statistic_service.cpp \
					 task_service/io_multiplex_handler.cpp \
					 task_service/task_service.cpp \
					 task_service/task_service_group.cpp \
					 task_service/timer_manager.cpp \
					 thread/thread.cpp \
					 thread/thread_group.cpp \
					 utility/arg_helper.cpp \
					 utility/processor_helper.cpp \
					 utility/random.cpp \
					 utility/signal_handler.cpp
