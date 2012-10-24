CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_log

chaos_log_SOURCES = chaos.cpp \
					../misc_impl.cpp

chaos_log_LDADD = \
			  $(top_srcdir)/chaos/libchaos_je.a \
			  -lpthread

