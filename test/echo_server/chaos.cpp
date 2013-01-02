#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "server_config.h"
#include "test_tcp_server.h"

EXTERN_SERVICE_DECL

#define PROGRESS_TYPE       "echo server"

arg_option_t       arg_options[] =
{
    //! yunjie: 信息输出
    arg_option_t("args", "show all args", false, NULL),
    arg_option_t("pt", "progress type", false, NULL),
    arg_option_t("v", "version", false, NULL),

    //! yunjie: 进程相关选项配置
    arg_option_t("cfg", "config path and name", true, NULL),
    arg_option_t("d", "daemon progress", false, NULL),
    arg_option_t("ll", "log level", true, NULL),
    arg_option_t("lf", "log file", true, NULL),
    arg_option_t("ls", "log screen", true, NULL),

    //! yunjie: 网络选项配置
    arg_option_t("tss", "tcp sndbuf size", true, NULL),
    arg_option_t("trs", "tcp rcvbuf size", true, NULL),
    arg_option_t("msbs", "max send buffer size", true, NULL),
    arg_option_t("mrbs", "max recv buffer size", true, NULL),
    arg_option_t("tn", "enable tcp nodelay option", false, NULL),

    //! yunjie: 服务相关选项配置
    arg_option_t("address", "listen address", true, NULL),
    arg_option_t("port", "listen port", true, NULL),
    arg_option_t("ct", "connection timeout", true, NULL),
    arg_option_t("wt", "number of work thread", true, NULL),
};

tcp_service_t<test_server_echo_conn_t>* tcp_service_ptr = NULL;
lua_config_t g_lua_config;
server_config_t g_server_config;

void parse_cmdarg(int argc_, char* argv_[]);
void init_config(network_config_t& net_cfg_, conn_heart_beat_param_t& hb_cfg_);

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    conn_heart_beat_param_t hb_param;
    hb_param.timeout_flag = false;
    hb_param.timeout = 0;

    network_config_t network_config;

    parse_cmdarg(argc_, argv_);
    init_config(network_config, hb_param);
    
    //! yunjie: 对于先创建的所有线程阻塞所有信号
    application_tool_t::block_all_signal();
    log_tool_t::start_log_service(
                                    "echoserver.log",
                                    g_server_config.log_level,
                                    g_server_config.log_print_to_file,
                                    g_server_config.log_print_to_screen
                                 );

    //! yunjie: 启动statistic service
    //! SS().set_timeout(10);
    //! SS().start(&LOGS());

    tcp_service_ptr = new tcp_service_t<test_server_echo_conn_t>();
    if (NULL == tcp_service_ptr)
    {
        exit(-1);
    }

    //! yunjie: 初始化并启动网络
    tcp_service_ptr->initialize(g_server_config.address, g_server_config.port, tcp_conn_event, network_config);
    if (hb_param.timeout_flag)
    {
        tcp_service_ptr->enable_conn_heart_beat(hb_param);
    }
    tcp_service_ptr->start(g_server_config.work_thread_num);

    //! yunjie: 主线程等待信号
    application_tool_t::wait_signal();
    tcp_service_ptr->stop();
    SAFE_DELETE(tcp_service_ptr);
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}

void parse_cmdarg(int argc_, char* argv_[])
{
    arg_pair_t* pair_arr = NULL;
    int pair_count = 0;

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
                    printf("%s\n", PROGRESS_TYPE);
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
                    g_lua_config.load_from_lua(pair_arr[i].arg_val);
                    lua_config_to_server_config(g_lua_config, g_server_config);
                    printf("%s",g_server_config.dump().c_str());
                }
                break;

            case 4:
                {
                    g_server_config.daemon = 1;
                }
                break;

            case 5:
                {
                    g_server_config.log_level = atoi(pair_arr[i].arg_val);
                }
                break;

            case 6:
                {
                    g_server_config.log_print_to_file = atoi(pair_arr[i].arg_val);
                }
                break;

            case 7:
                {
                    g_server_config.log_print_to_screen = atoi(pair_arr[i].arg_val);
                }
                break;

            case 8:
                {
                    g_server_config.tcp_sndbuf_size = atoi(pair_arr[i].arg_val);
                }
                break;

            case 9:
                {
                    g_server_config.tcp_rcvbuf_size = atoi(pair_arr[i].arg_val);
                }
                break;

            case 10:
                {
                    g_server_config.max_send_buffer_size = atoi(pair_arr[i].arg_val);
                }
                break;

            case 11:
                {
                    g_server_config.max_recv_buffer_size = atoi(pair_arr[i].arg_val);
                }
                break;

            case 12:
                {
                    g_server_config.tcp_nodelay = true;
                }
                break;

            case 13:
                {
                }
                break;

            case 14:
                {
                }
                break;

            case 15:
                {
                    g_server_config.conn_timeout = atoi(pair_arr[i].arg_val);
                }
                break;

            case 16:
                {
                    g_server_config.work_thread_num = atoi(pair_arr[i].arg_val);
                }
                break;

            default:
                {
                }
                break;
        }
    }
    //! yunjie: arg parse end
}

void init_config(network_config_t& net_cfg_, conn_heart_beat_param_t& hb_cfg_)
{
    if (g_server_config.daemon)
    {
        singleton_t<processor_helper_t>::instance().daemonize();
    }

    if (g_server_config.conn_timeout)
    {
        hb_cfg_.timeout_flag = true;
        hb_cfg_.timeout = g_server_config.conn_timeout;
    }

    if (g_server_config.tcp_sndbuf_size)
    {
        net_cfg_.tcp_sndbuf_size = g_server_config.tcp_sndbuf_size;
    }

    if (g_server_config.tcp_rcvbuf_size)
    {
        net_cfg_.tcp_rcvbuf_size = g_server_config.tcp_rcvbuf_size;
    }

    if (g_server_config.max_send_buffer_size)
    {
        net_cfg_.max_send_buffer_size = g_server_config.max_send_buffer_size;
    }

    if (g_server_config.max_recv_buffer_size)
    {
        net_cfg_.max_recv_buffer_size = g_server_config.max_recv_buffer_size;
    }

    if (g_server_config.tcp_nodelay)
    {
        net_cfg_.tcp_nodelay = g_server_config.tcp_nodelay;
    }
}

