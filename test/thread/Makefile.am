CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_thread

chaos_thread_SOURCES = chaos.cpp \
					   ../misc_impl.cpp

chaos_thread_LDADD = \
			  $(top_srcdir)/chaos/libchaos_je.a \
			  -lpthread

