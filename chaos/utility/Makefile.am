CXXFLAGS = -Wall -g -O2 -fPIC

## 安装根目录
chaosdir=$(prefix)/chaos-@chaos_ver@

## 安装库目录
libdir=$(chaosdir)/lib

lib_LIBRARIES = libchaos_utility.a
libchaos_utility_a_LIBFLAGS =
libchaos_utility_a_LIBADD =

libchaos_utility_a_SOURCES = \
						processor_helper.cpp \
						random.cpp \
						signal_handler.cpp \
						arg_helper.cpp
