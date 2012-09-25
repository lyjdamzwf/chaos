#ifndef _CHAOS_TEST_TASK_SERVICE_H_
#define _CHAOS_TEST_TASK_SERVICE_H_

#define USE_BOOST 0
#define TASK_SERVICE_PERFORMANCE_COUNT 100000000

#if USE_BOOST
#include "boost/function.hpp"
#include "boost/thread.hpp"
#include "boost/asio.hpp"
#include "boost/shared_ptr.hpp"

typedef boost::shared_ptr<boost::asio::io_service> io_service_ptr;
typedef boost::shared_ptr<boost::asio::io_service::work> work_ptr;
work_ptr gwp;

#endif

struct timeval begin_tv;
struct timeval post_end_tv;
struct timeval fin_tv;

void task_service_productor(string str_, int index_)
{
    if ("task_service_press" == str_)
    {
        LOGDEBUG((TEST_MODULE, "press index:%d", index_));
        return;
    }

    if (TASK_SERVICE_PERFORMANCE_COUNT - 1 == index_)
    {
        LOGDEBUG((TEST_MODULE, "%s done", str_.c_str()));
        gettimeofday(&fin_tv, NULL);
        uint64_t cost_us = (fin_tv.tv_sec - begin_tv.tv_sec) * 1000 * 1000 + (fin_tv.tv_usec - begin_tv.tv_usec);
        printf("task exec cost:[%lu us]\n", cost_us);
    }
}

void test_task_service_press()
{
    int index = 0;
    while (1)
    {
        if (0 == index % 100000)
        {
            thread_t::sleep(2);
        }

        TS().post(bindfunc(&task_service_productor, string("task_service_press"), index));
        ++index ;
    }
}

void test_task_service_performance()
{
    LOGDEBUG((TEST_MODULE, "test_task_service_performance begin"));

    int index = 0;
    gettimeofday(&begin_tv, NULL);

#if USE_BOOST
    io_service_ptr isptr = io_service_ptr(new boost::asio::io_service());
    gwp = work_ptr(new boost::asio::io_service::work(*isptr));
    boost::shared_ptr<boost::thread> thread(new boost::thread(boost::bind(&boost::asio::io_service::run, isptr)));

    while (index <= TASK_SERVICE_PERFORMANCE_COUNT)
    {
        isptr->post(boost::bind(&task_service_productor, string("asio_service"), index++));
    }
    LOGDEBUG((TEST_MODULE, "boost post end"));
    gwp.reset();

    LOGDEBUG((TEST_MODULE, "boost thread join start"));
    thread->join();
    LOGDEBUG((TEST_MODULE, "boost thread join end"));
#else
    while (index <= TASK_SERVICE_PERFORMANCE_COUNT)
    {
        TS().post(bindfunc(&task_service_productor, string("task_service"), index++));
    }
    LOGDEBUG((TEST_MODULE, "chaos post end"));
#endif

    gettimeofday(&post_end_tv, NULL);
    uint64_t cost_us = (post_end_tv.tv_sec - begin_tv.tv_sec) * 1000 * 1000 + (post_end_tv.tv_usec - begin_tv.tv_usec);
    printf("post cost:[%lu us]\n", cost_us);

    LOGDEBUG((TEST_MODULE, "test_task_service_performance end"));
}

void test_ring_buffer()
{
    ring_buffer_t<int> ring_buffer;

    for (int i = 0; i < 10; ++i)
    {
        printf("[%d] writeable:%d\n", i, ring_buffer.writeable());
        printf("[%d] readable before put:%d\n", i, ring_buffer.readable());

        ring_buffer.put(i);
        printf("[%d] readable after put:%d\n", i, ring_buffer.readable());
        printf("read vaue:[%d]\n", ring_buffer.get());
        printf("[%d] readable after read:%d\n", i, ring_buffer.readable());
    }

}

void task_service_timer_event_persist()
{
    LOGDEBUG((TEST_MODULE, "task_service_timer_event_persist called!!!!!"));
}

void test_task_service_timer_persist()
{
    LOGDEBUG((TEST_MODULE, "test_task_service_timer_persist begin"));

    TS().register_timer(1, bindfunc(task_service_timer_event_persist), true);

    LOGDEBUG((TEST_MODULE, "test_task_service_timer_persist end"));
}

//! yunjie: task_service_t 是 noncopyable的, 所以只能传指针
void task_service_timer_event(task_service_t* service_)
{
    printf("task_service_timer_event called!!!!!\n");
    service_->register_timer(2, bindfunc(&task_service_timer_event, service_), false);
}

void test_task_service_timer()
{
    TS().register_timer(2, bindfunc(&task_service_timer_event, &TS()), false);
}

void test_mutil_timer(string str_)
{
    printf("test_mutil_timer:%s\n", str_.c_str());
}

void test_task_service_mutil_timer()
{
    TS().register_timer(1, bindfunc(test_mutil_timer, string("111")), true);
    TS().register_timer(2, bindfunc(test_mutil_timer, string("222")), true);
}

void callback(const string& str_)
{
    printf("callback[%s]!!!\n", str_.c_str());
}

void async_call(const string& str_, void(*callback)(const string&))
{
    printf("async_call!!!\n");
    (*callback)("zark lu");
}

void test_callback()
{
    string str = "call";
    TS().post(bindfunc(&async_call, str, &callback));
}

#define PRESS_TIMER_COUNT 20000

void test_timer_press()
{
    for (int i = 0; i < PRESS_TIMER_COUNT; ++i)
    {
        uint32_t interval = rand_gen_t::get_rand(1, 11);
        bool persist = rand_gen_t::get_rand(0, 2);
        async_method_t method;

        if (persist)
        {
            method = bindfunc(task_service_timer_event_persist);
        }
        else
        {
            method = bindfunc(&task_service_timer_event, &TS());
        }

        TS().register_timer(interval, method, persist);
    }
}

#endif //! _CHAOS_TASK_SERVICE_H_

