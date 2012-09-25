#ifndef _CHAOS_TEST_THREAD_H_
#define _CHAOS_TEST_THREAD_H_

void thread_func(string str_, int count_)
{
    for (int i = 0; i < count_; ++i)
    {
        printf("[%d]thread_func:%s\n", i + 1, str_.c_str());
    }
}

void test_thread()
{
    thread_t thd;
    thd.start(bindfunc(thread_func, string("my name is yunjie.lu"), 10));

    printf("thread join\n");
    thd.join();
    printf("thread join finish\n");
}



#endif //! _CHAOS_TEST_THREAD_H_
