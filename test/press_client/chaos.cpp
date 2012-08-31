#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_pressclient.h"

extern uint32_t g_press_conn_num;
extern uint32_t g_max_packet_size;

arg_option_t       arg_options[] =
{
    //! yunjie: 信息输出
    arg_option_t("args", "show all args", false, NULL),
    arg_option_t("pt", "progress type", false, NULL),
    arg_option_t("v", "version", false, NULL),

    //! yunjie: 进程相关选项配置
    arg_option_t("d", "daemon progress", false, NULL),
    arg_option_t("ct", "connection timeout", true, NULL),
    arg_option_t("wt", "number of work thread", true, NULL),
    arg_option_t("ll", "log level", true, NULL),

    //! yunjie: 网络选项配置
    arg_option_t("tss", "tcp sndbuf size", true, NULL),
    arg_option_t("trs", "tcp rcvbuf size", true, NULL),
    arg_option_t("msbs", "max send buffer size", true, NULL),
    arg_option_t("mrbs", "max read buffer size", true, NULL),
    arg_option_t("tn", "enable tcp nodelay option", false, NULL),

    //! yunjie: 程序逻辑相关
    arg_option_t("pcn", "press connection num", true, NULL),
    arg_option_t("mps", "max packet size", true, NULL),
};

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    arg_pair_t* pair_arr = NULL;
    int pair_count = 0;

    conn_heart_beat_param_t hb_param;
    hb_param.timeout_flag = false;
    hb_param.timeout = 0;

    int work_thread_num = 1;
    int log_level = 4;

    network_config_t network_config;

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
                printf("press client\n");
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
                hb_param.timeout_flag = true;
                hb_param.timeout = atoi(pair_arr[i].arg_val);
            }
            break;

            case 5:
            {
                work_thread_num = atoi(pair_arr[i].arg_val);
            }
            break;

            case 6:
            {
                log_level = atoi(pair_arr[i].arg_val);
            }
            break;

            case 7:
            {
                network_config.tcp_sndbuf_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 8:
            {
                network_config.tcp_rcvbuf_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 9:
            {
                network_config.max_send_buffer_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 10:
            {
                network_config.max_read_buffer_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 11:
            {
                network_config.is_enable_tcp_nodelay = true;
            }
            break;

            case 12:
            {
                g_press_conn_num = atoi(pair_arr[i].arg_val);
            }
            break;

            case 13:
            {
                g_max_packet_size = atoi(pair_arr[i].arg_val);
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

    connector_service_ptr =
        new connector_service_t<test_press_conn_strategy_t>();
    if (NULL == connector_service_ptr)
    {
        //! mem error
        exit(-1);
    }

    connector_service_ptr->set_network_config(network_config);

    if (hb_param.timeout_flag)
    {
        connector_service_ptr->enable_conn_heart_beat(hb_param);
    }
    connector_service_ptr->start(work_thread_num);

    test_press_client(g_press_conn_num);

    application_tool_t::wait_signal();

    connector_service_ptr->stop();
    delete connector_service_ptr;

    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}


