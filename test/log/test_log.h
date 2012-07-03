#ifndef _CHAOS_TEST_LOG_H_
#define _CHAOS_TEST_LOG_H_

void test_log()
{
    LOGFATAL((TEST_MODULE, "weibo - %s", "http://weibo.com/crazyprogramerlyj"));
    LOGERROR((TEST_MODULE, "my name is %s", "yunjie"));
    LOGWARN((TEST_MODULE, "maya's birthday:%d", 1104));
    LOGTRACE((TEST_MODULE, "I will wait for you"));
    LOGDEBUG((TEST_MODULE, "value:%lu", 1121));
}


#endif //! _CHAOS_TEST_LOG_H_
