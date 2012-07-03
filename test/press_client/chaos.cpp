#include <vector>
#include <iostream>
using namespace std;

#include "utility_inc.h"
#include "thread_inc.h"
#include "task_service_inc.h"
#include "async_method_inc.h"
#include "log_inc.h"
#include "network_inc.h"
using namespace chaos::utility;
using namespace chaos::async_method;
using namespace chaos::thread;
using namespace chaos::task_service;
using namespace chaos::log;
using namespace chaos::network;


#include "../misc_def.h"
#include "test_pressclient.h"

extern uint32_t g_press_conn_num;
extern uint32_t g_max_packet_size;

arg_option_t       arg_options[] =
{
    arg_option_t("args", "show all args", false, NULL),
    arg_option_t("d", "daemon progress", false, NULL),
    arg_option_t("ct", "connection timeout", true, NULL),
    arg_option_t("pt", "progress type", false, NULL),
    arg_option_t("pcn", "press connection num", true, NULL),
    arg_option_t("mps", "max packet size", true, NULL),
    arg_option_t("ll", "log level", true, NULL),
};

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    arg_pair_t* pair_arr = NULL;
    int pair_count = 0;

    conn_heart_beat_param_t hb_param;
    hb_param.timeout_flag = false;
    hb_param.timeout = 0;

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
                singleton_t<processor_helper_t>::instance().daemonize();
            }
            break;
            case 2:
            {
                hb_param.timeout_flag = true;
                hb_param.timeout = atoi(pair_arr[i].arg_val);
            }
            break;
            case 3:
            {
                printf("press client\n");
                exit(0);
            }
            break;
            case 4:
            {
                g_press_conn_num = atoi(pair_arr[i].arg_val);
            }
            break;
            case 5:
            {
                g_max_packet_size = atoi(pair_arr[i].arg_val);
            }
            break;
            case 6:
            {
                log_level = atoi(pair_arr[i].arg_val);
            }
            break;
            default:
            {
            }
            break;
        }
    }
    //! yunjie: arg parse end

    //! yunjie: 对于先创建的所有线程阻塞所有信号
    application_tool_t::block_all_signal();

    log_tool_t::start_log_service("pressclient.log", log_level, 1, 1);

    if (hb_param.timeout_flag)
    {
        WS().start_heart_beat_service(hb_param);
    }
    WS().start(1);
    test_press_client(g_press_conn_num);

    application_tool_t::wait_signal();
    WS().stop();
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}


