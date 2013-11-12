INCLUDES = -I/opt/local/boost/include/boost-1_44

noinst_PROGRAMS = chaos_task_service

chaos_task_service_SOURCES = chaos.cpp \
							 ../misc.cpp

chaos_task_service_LDFLAGS =  -L/opt/local/boost.1.44/lib/
#chaos_task_service_LDFLAGS =  -L/opt/local/boost/lib/boost-1_44/

chaos_task_service_LDADD = \
			  $(top_srcdir)/chaos/libchaos.a \
			  -lpthread \
				-lboost_system -lboost_thread -lboost_regex

