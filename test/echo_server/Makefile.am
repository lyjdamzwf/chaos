CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_echo_server

chaos_echo_server_SOURCES = chaos.cpp

chaos_echo_server_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

