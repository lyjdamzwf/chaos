CXXFLAGS += -Wall -static -g -O2 -fPIC

noinst_PROGRAMS = chaos_task_service

chaos_task_service_SOURCES = chaos.cpp
					
chaos_task_service_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread

