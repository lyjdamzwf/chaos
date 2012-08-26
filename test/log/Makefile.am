CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_log

chaos_log_SOURCES = chaos.cpp
					
chaos_log_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

