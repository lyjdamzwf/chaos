CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_pressclient

chaos_pressclient_SOURCES = chaos.cpp
					
chaos_pressclient_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

