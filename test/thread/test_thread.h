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

void dead_loop()
{
    while(1)
    {
        //! do nothing
    }
}

void test_thread_state()
{
    for (int i = 0 ; i < 50; ++i)
    {
        thread_t thd;
        thd.start(bindfunc(dead_loop));
        //! sleep(1);
        if (thd.is_alive())
        {
            printf("[%d] thread state alive\n", i);
        }
        else
        {
            printf("[%d] thread state not alive\n", i);
            break;
        }
    }
}


#endif //! _CHAOS_TEST_THREAD_H_
