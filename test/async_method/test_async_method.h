#ifndef _CHAOS_TEST_ASYNC_METHOD_H_
#define _CHAOS_TEST_ASYNC_METHOD_H_

class hw_t
{
public:
    hw_t()
    {
    }

    void call0()
    {
        printf("call0.\n");
    }

    void call1(int arg_)
    {
        printf("call1:%d\n", arg_);
    }

    void call2(int arg_, string arg2_)
    {
        printf("call2:%d, %s\n", arg_, arg2_.c_str());
    }

    void call3(int arg_, const string& arg2_, double arg3_)
    {
        printf("call2:%d, %s, %f\n", arg_, arg2_.c_str(), arg3_);
    }

    void call4(int arg_, string arg2_, double arg3_, const string arg4_)
    {
        printf("call2:%d, %s, %f, %s\n", arg_, arg2_.c_str(), arg3_, arg4_.c_str());
    }

    void call5(int arg_, string& arg2_, double arg3_, string arg4_, uint64_t arg5_)
    {
        printf("call2:%d, %s, %f, %s, %lu\n", arg_, arg2_.c_str(), arg3_, arg4_.c_str(), arg5_);
    }
};


void test_static_func(string& s_)
{
    printf("test_static_func:%s\n", s_.c_str());
}

class foo_t
{
public:
    static void test_static_func(string s_)
    {
        printf("foo_t::test_static_func:%s\n", s_.c_str());
    }
};

void test_async_method()
{
    hw_t hw;
    const string tmp_str = "yunjie";
    string tmp_str2 = "luyunjie";

    async_method_t m1 = bindfunc(&hw, &hw_t::call0);
    async_method_t m2 = bindfunc(&hw, &hw_t::call1, 123456);
    async_method_t m3 = bindfunc(&hw, &hw_t::call2, 1121, string("lyj"));
    async_method_t m4 = bindfunc(&hw, &hw_t::call3, 1121, string("lyj"), 123.456);
    async_method_t m5 = bindfunc(&hw, &hw_t::call4, 1121, string("lyj"), 123.456, string("zark"));
    async_method_t m6 = bindfunc(&hw, &hw_t::call5, 1121, string("lyj"), 123.456, string("zark"), (uint64_t)123456789);
    async_method_t m7 = bindfunc(&test_static_func, tmp_str);
    async_method_t m8 = bindfunc(&foo_t::test_static_func, tmp_str2);

    vector<async_method_t>  task_queue;
    task_queue.push_back(m1);
    task_queue.push_back(m2);
    task_queue.push_back(m3);
    task_queue.push_back(m4);
    task_queue.push_back(m5);
    task_queue.push_back(m6);
    task_queue.push_back(m7);
    task_queue.push_back(m8);
    for (vector<async_method_t>::iterator it = task_queue.begin(); it != task_queue.end(); ++it)
    {
        (*it)();
        it->release();
    }
}


#endif //! _CHAOS_TEST_ASYNC_METHOD_H_
