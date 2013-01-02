SUBDIRS= thread utility task_service log network statistic mylua

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
jemallocdir=$(includedir)/deps/jemalloc
jeinterdir=$(includedir)/deps/jemalloc/internal

include_HEADERS= *.h
async_method_HEADERS=async_method/*.h
heart_beat_HEADERS=heart_beat/*.h
log_HEADERS=log/*.h
network_HEADERS=network/*.h
statistic_HEADERS=statistic/*.h
task_service_HEADERS=task_service/*.h
thread_HEADERS=thread/*.h
utility_HEADERS=utility/*.h
jemalloc_HEADERS=deps/jemalloc/include/jemalloc/*.h
jeinter_HEADERS=deps/jemalloc/include/jemalloc/internal/*.h

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
					 network/default_conn_strategy.cpp \
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
					 utility/signal_handler.cpp \
					 mylua/lua-5.1.4/src/ldo.c \
					 mylua/lua-5.1.4/src/lcode.c \
					 mylua/lua-5.1.4/src/lauxlib.c \
					 mylua/lua-5.1.4/src/lstrlib.c \
					 mylua/lua-5.1.4/src/ldblib.c \
					 mylua/lua-5.1.4/src/lundump.c \
					 mylua/lua-5.1.4/src/lopcodes.c \
					 mylua/lua-5.1.4/src/lbaselib.c \
					 mylua/lua-5.1.4/src/lapi.c \
					 mylua/lua-5.1.4/src/lua.c \
					 mylua/lua-5.1.4/src/lmathlib.c \
					 mylua/lua-5.1.4/src/lmem.c \
					 mylua/lua-5.1.4/src/lparser.c \
					 mylua/lua-5.1.4/src/lvm.c \
					 mylua/lua-5.1.4/src/ltable.c \
					 mylua/lua-5.1.4/src/lfunc.c \
					 mylua/lua-5.1.4/src/llex.c \
					 mylua/lua-5.1.4/src/ldump.c \
					 mylua/lua-5.1.4/src/lobject.c \
					 mylua/lua-5.1.4/src/loadlib.c \
					 mylua/lua-5.1.4/src/liolib.c \
					 mylua/lua-5.1.4/src/lgc.c \
					 mylua/lua-5.1.4/src/lzio.c \
					 mylua/lua-5.1.4/src/ltablib.c \
					 mylua/lua-5.1.4/src/ltm.c \
					 mylua/lua-5.1.4/src/lstring.c \
					 mylua/lua-5.1.4/src/linit.c \
					 mylua/lua-5.1.4/src/loslib.c \
					 mylua/lua-5.1.4/src/luac.c \
					 mylua/lua-5.1.4/src/print.c \
					 mylua/lua-5.1.4/src/ldebug.c \
					 mylua/lua-5.1.4/src/lstate.c \
					 mylua/mylua.cpp \
					 mylua/lua_table.cpp \
					 mylua/lua_type.cpp \
					 mylua/lua_object.cpp


