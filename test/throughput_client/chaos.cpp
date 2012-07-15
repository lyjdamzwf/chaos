#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_tpclient.h"

arg_option_t       arg_options[] =
{
    //! yunjie: 信息输出
    arg_option_t("args", "show all args", false, NULL),
    arg_option_t("pt", "progress type", false, NULL),

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
    arg_option_t("sc", "send count", true, NULL),
    arg_option_t("ps", "packet size", true, NULL),
    arg_option_t("acc", "active connection count", true, NULL),
};

extern uint32_t g_send_count;
extern uint32_t g_send_packet_size;
extern uint32_t g_active_conn_count;

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
                printf("throughput client\n");
                exit(0);
            }
            break;

            case 2:
            {
                singleton_t<processor_helper_t>::instance().daemonize();
            }
            break;

            case 3:
            {
                hb_param.timeout_flag = true;
                hb_param.timeout = atoi(pair_arr[i].arg_val);
            }
            break;

            case 4:
            {
                work_thread_num = atoi(pair_arr[i].arg_val);
            }
            break;

            case 5:
            {
                log_level = atoi(pair_arr[i].arg_val);
            }
            break;

            case 6:
            {
                network_config.tcp_sndbuf_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 7:
            {
                network_config.tcp_rcvbuf_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 8:
            {
                network_config.max_send_buffer_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 9:
            {
                network_config.max_read_buffer_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 10:
            {
                network_config.is_enable_tcp_nodelay = true;
            }
            break;

            case 11:
            {
                g_send_count = atoi(pair_arr[i].arg_val);
            }
            break;

            case 12:
            {
                g_send_packet_size = atoi(pair_arr[i].arg_val);
            }
            break;

            case 13:
            {
                g_active_conn_count = atoi(pair_arr[i].arg_val);
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

    log_tool_t::start_log_service("tpclient.log", log_level, 1, 1);

    packet_header_t header;
    header.cmd = 1121;
    header.ext = 1104;
    header.data_len = g_send_packet_size;
    g_send_data.append((char*)&header, HEADER_SIZE);
    g_send_data.append(g_send_packet_size, 'a');

    connector_service_t<test_tp_conn_strategt_t>* connector_service_ptr =
        new connector_service_t<test_tp_conn_strategt_t>();
    if (NULL == connector_service_ptr)
    {
        //! mem error
        exit(-1);
    }

    if (hb_param.timeout_flag)
    {
        connector_service_ptr->enable_conn_heart_beat(hb_param);
    }

    connector_service_ptr->set_network_config(network_config);

    connector_service_ptr->start(work_thread_num);

    for (uint32_t i = 0; i < g_active_conn_count; ++i)
    {
        connector_service_ptr->async_connect(
                                                LOCALHOST,
                                                8880,
                                                tcp_conn_event,
                                                true
                                            );
    }

    
    gettimeofday(&g_timeval, NULL);
    uint64_t total_bytes = 2 * g_active_conn_count * g_send_count * (g_send_packet_size + sizeof(packet_header_t));
    LOGINFO((TEST_MODULE, "test_tp_press_client total need transfer data size:[%lu] bytes, [%lu] MB",
                            total_bytes,
                            total_bytes / 1000 / 1000
            ));


    application_tool_t::wait_signal();

    connector_service_ptr->stop();
    delete connector_service_ptr;

    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}


