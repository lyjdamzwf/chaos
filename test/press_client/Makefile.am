CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_pressclient

chaos_pressclient_SOURCES = chaos.cpp \
							../misc_impl.cpp \
							test_pressclient.cpp

chaos_pressclient_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

