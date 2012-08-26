CXXFLAGS = -Wall -g -O2 -fPIC

## 安装根目录
chaosdir=$(prefix)/chaos-@chaos_ver@

## 安装库目录
libdir=$(chaosdir)/lib

lib_LIBRARIES = libchaos_thread.a
libchaos_thread_a_LIBFLAGS =
libchaos_thread_a_LIBADD =

libchaos_thread_a_SOURCES = \
						  thread.cpp \
						  thread_group.cpp
