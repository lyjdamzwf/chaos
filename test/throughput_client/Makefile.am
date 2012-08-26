CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_tpclient

chaos_tpclient_SOURCES = chaos.cpp
					
chaos_tpclient_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread
