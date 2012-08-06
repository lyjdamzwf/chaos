#ifndef _CHAOS_TEST_ARG_HELER_H_
#define _CHAOS_TEST_ARG_HELER_H_

void arg1_handler(int index, const char* arg_name_, const char* arg_val_)
{
    printf("arg_handler1 val:[%d %s %s]\n", index, arg_name_, arg_val_);
}

void arg2_handler(int index, const char* arg_name_, const char* arg_val_)
{
    printf("arg_handler2 val:[%d %s %s]\n", index, arg_name_, arg_val_);
}

void arg3_handler(int index, const char* arg_name_, const char* arg_val_)
{
    printf("arg_handler3 val:[%d %s %s]\n", index, arg_name_, arg_val_);
}

arg_option_t       test_arg_options[] =
{
    arg_option_t("arg1", "this is arg1", true, arg1_handler),
    arg_option_t("arg2", "this is arg2", true, arg2_handler),
    arg_option_t("arg3", "this is arg3", false, arg3_handler),
    arg_option_t("arg4", "this is arg4", true, arg1_handler)
};

void test_arg_helper(int argc_, char* argv_[])
{
    singleton_t<arg_helper_t>::instance().show_args(
                                                     test_arg_options,
                                                     sizeof(test_arg_options) / sizeof(arg_option_t)
                                                     );
    arg_pair_t* pair_arr;
    int pair_count;

    int parse_ret = singleton_t<arg_helper_t>::instance().parse_arg
        (
         test_arg_options,
         sizeof(test_arg_options) / sizeof(arg_option_t),
         argv_,
         argc_,
         &pair_arr,
         &pair_count
        );

    for (int i = 0; i < pair_count; ++i)
    {
        arg_pair_t pair = pair_arr[i];
        printf("index:%d val:%s\n", pair.arg_index, pair.arg_val);
    }

    printf("arg parse ret:[%d]\n", parse_ret);
}

#endif //! _CHAOS_TEST_ARG_HELER_H_
