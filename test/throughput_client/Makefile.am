CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_tpclient

chaos_tpclient_SOURCES = chaos.cpp \
						 ../misc_impl.cpp

chaos_tpclient_LDADD = \
			  $(top_srcdir)/chaos/libchaos_je.a \
			  -lpthread
