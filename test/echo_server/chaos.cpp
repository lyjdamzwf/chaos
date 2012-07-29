#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_tcp_server.h"

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
                printf("echo server\n");
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
                tcp_server_thread = atoi(pair_arr[i].arg_val);
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

    //! yunjie: 启动statistic service
    //! SS().set_timeout(10);
    //! SS().start(&LOGS());

    tcp_service_t<test_server_echo_conn_t>* tcp_service_ptr = new tcp_service_t<test_server_echo_conn_t>();
    if (NULL == tcp_service_ptr)
    {
        //! mem error
        exit(-1);
    }

    //! yunjie: 初始化并启动网络
    tcp_service_ptr->initialize(LOCALHOST, 8880, tcp_conn_event, network_config);
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

