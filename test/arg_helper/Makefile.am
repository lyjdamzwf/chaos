CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_arg_helper

chaos_arg_helper_SOURCES = chaos.cpp

chaos_arg_helper_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread
