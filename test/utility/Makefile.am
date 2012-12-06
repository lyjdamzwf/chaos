CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_test_utility

chaos_test_utility_SOURCES = chaos.cpp

chaos_test_utility_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread
