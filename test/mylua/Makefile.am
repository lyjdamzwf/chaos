CXXFLAGS = -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_mylua

chaos_mylua_SOURCES = \
		chaos.cpp \
		../misc_impl.cpp

chaos_mylua_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

