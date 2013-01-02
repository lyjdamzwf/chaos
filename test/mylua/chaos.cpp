#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_mylua.h"

EXTERN_SERVICE_DECL

arg_option_t       arg_options[] =
{
    //! yunjie: 信息输出
    arg_option_t("args", "show all args", false, NULL),
    arg_option_t("pt", "progress type", false, NULL),
    arg_option_t("v", "version", false, NULL),

    //! yunjie: 进程相关选项配置
    arg_option_t("d", "daemon progress", false, NULL),
    arg_option_t("ll", "log level", true, NULL),

    //! yunjie: lua测试参数
    arg_option_t("lc", "loop count", true, NULL),
};


int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    arg_pair_t* pair_arr = NULL;
    int pair_count = 0;

    int loop_count = 1;
    int log_level = 4;

    //! yunjie: arg parse begin
    int parse_ret = singleton_t<arg_helper_t>::instance().parse_arg
        (
         arg_options,
         sizeof(arg_options) / sizeof(arg_option_t),
         argv_,
         argc_,
         &pair_arr,
         &pair_count
        );

    if (-1 == parse_ret)
    {
        printf("arg parse error.\n");
        exit(0);
    }

    for (int i = 0; i < pair_count; ++i)
    {
        switch (pair_arr[i].arg_index)
        {
            case 0:
            {
                singleton_t<arg_helper_t>::instance().show_args(
                                                                 arg_options,
                                                                 sizeof(arg_options) / sizeof(arg_option_t)
                                                                );
                exit(0);
            }
            break;

            case 1:
            {
                printf("test mylua\n");
                exit(0);
            }
            break;

            case 2:
            {
                printf("%s-%s\n", PACKAGE_NAME, VERSION);
                exit(0);
            }
            break;

            case 3:
            {
                singleton_t<processor_helper_t>::instance().daemonize();
            }
            break;

            case 4:
            {
                log_level = atoi(pair_arr[i].arg_val);
            }
            break;

            case 5:
            {
                loop_count = atoi(pair_arr[i].arg_val);
            }
            break;

            default:
            {
            }
            break;
        }
    }
    //! yunjie: arg parse end

    TS().start();

    //! yunjie: 对于先创建的所有线程阻塞所有信号
    application_tool_t::block_all_signal();
    log_tool_t::start_log_service("test_mylua.log", log_level, 1, 1);

    TS().post(bindfunc(&thread_loop, loop_count));

    //! yunjie: 主线程等待信号
    application_tool_t::wait_signal();
    TS().stop();
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}


