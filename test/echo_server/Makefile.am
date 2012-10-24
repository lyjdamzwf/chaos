CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_echo_server

chaos_echo_server_SOURCES = chaos.cpp \
							../misc_impl.cpp

chaos_echo_server_LDADD = \
			  $(top_srcdir)/chaos/libchaos_je.a \
			  -lpthread

