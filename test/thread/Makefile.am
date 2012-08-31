CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_thread

chaos_thread_SOURCES = chaos.cpp

chaos_thread_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

