CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_perf

chaos_perf_SOURCES = chaos.cpp \
					   ../misc_impl.cpp

chaos_perf_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

