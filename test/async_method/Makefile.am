CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_async_method

chaos_async_method_SOURCES = chaos.cpp
					
chaos_async_method_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread
