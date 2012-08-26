CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_msg_buffer

chaos_msg_buffer_SOURCES = chaos.cpp
					
chaos_msg_buffer_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

