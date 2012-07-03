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
#include "test_tcp_server.h"

arg_option_t       arg_options[] =
{
    arg_option_t("args", "show all args", false, NULL),
    arg_option_t("d", "daemon progress", false, NULL),
    arg_option_t("ct", "connection timeout", true, NULL),
    arg_option_t("wt", "number of work thread", true, NULL),
    arg_option_t("pt", "progress type", false, NULL),
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

    int tcp_server_thread = 1;
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
                tcp_server_thread = atoi(pair_arr[i].arg_val);
            }
            break;
            case 4:
            {
                printf("echo server\n");
                exit(0);
            }
            break;
            case 5:
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
    log_tool_t::start_log_service("echoserver.log", log_level, 1, 1);
    tcp_service_t<test_server_echo_conn_t>* tcp_service_ptr = new tcp_service_t<test_server_echo_conn_t>();
    if (NULL == tcp_service_ptr)
    {
        //! mem error
        exit(-1);
    }

    //! yunjie: 初始化并启动网络
    tcp_service_ptr->initialize(LOCALHOST, 8880, tcp_conn_event);
    if (hb_param.timeout_flag)
    {
        tcp_service_ptr->enable_conn_heart_beat(hb_param);
    }
    tcp_service_ptr->start(tcp_server_thread);

    //! yunjie: 主线程等待信号
    application_tool_t::wait_signal();
    tcp_service_ptr->stop();
    SAFE_DELETE(tcp_service_ptr);
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}

