echo_server_config = 
{
    -- yunjie: 进程相关选项配置
    daemon                  = 0,
    log_level               = 4,
    log_print_to_file       = 1,
    log_print_to_screen     = 1,

    -- yunjie: 网络选项配置
    tcp_sndbuf_size         = 0,
    tcp_rcvbuf_size         = 0,
    max_send_buffer_size    = 16 * 1024 * 1024,
    max_recv_buffer_size    = 16 * 1024 * 1024,
    tcp_nodelay             = 0,

    -- yunjie: 服务相关选项配置
    address                 = "127.0.0.1",
    port                    = 8880,
    conn_timeout            = 10,
    work_thread_num         = 2,
}

