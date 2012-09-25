#ifndef _CHAOS_TEST_TIMER_H_
#define _CHAOS_TEST_TIMER_H_

timer_manager_t timer_manager;

void timer_event()
{
    printf("timer_event called!!!!!\n");
    timer_manager.register_timer(1, bindfunc(timer_event), false);
}

void test_time_event()
{
    timer_manager.initialize(false);

    timer_manager.register_timer(1, bindfunc(timer_event), false, time(NULL) + 10);

    while (1)
    {
        timer_manager.flush_time();
        timer_manager.exec();
    }
}


#endif //! _CHAOS_TEST_TIMER_H_
