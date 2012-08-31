#ifndef _CHAOS_TEST_TCP_SERVER_H_
#define _CHAOS_TEST_TCP_SERVER_H_

#include <netinet/tcp.h>

//! yunjie: test throughput begin

#define SEND_COUNT          10000
#define SEND_PACKET_SIZE    (16*1024)
#define ACTIVE_CONN_COUNT   10

#define CHECK_SUM 0

//! yunjie: 可配选项
uint32_t                        g_send_count = SEND_COUNT;
uint32_t                        g_send_packet_size = SEND_PACKET_SIZE;
uint32_t                        g_active_conn_count = ACTIVE_CONN_COUNT;

//! yunjie: 统计数据
atomic_val_t<uint64_t>          g_finished_conn;
struct timeval                  g_timeval;
atomic_val_t<int>               g_connected_num;
string                          g_send_data;


void tcp_conn_event(conn_event_e conn_event_, conn_status_e conn_status_, conn_id_t conn_id_)
{
    switch (conn_event_)
    {
        case EV_INIT_COMPLETE:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event init complete sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_DECONSTRUCT:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event deconstruct sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_ACCEPTED_COMPLETE:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event accepted complete sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_CONNECT_SUCCESS:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event connect success sockfd:[%d]", conn_id_.socket));

            connection_t::async_send(conn_id_, g_send_data);

            uint32_t connected_num = ++g_connected_num;
            if (connected_num == g_active_conn_count)
            {
                struct timeval now;
                gettimeofday(&now, NULL);

                uint32_t aps = 0;

                uint64_t total_sec = now.tv_sec - g_timeval.tv_sec;
                if (0 != total_sec)
                {
                    aps = connected_num / total_sec;

                    LOGWARN((TEST_MODULE, "cost:[%lu s] accepted num:[%lu] connection accepted per second:[%u]",
                                total_sec,
                                connected_num,
                                aps
                            ));

                }
                else
                {

                    uint64_t total_usec = (now.tv_sec - g_timeval.tv_sec) * 1000000 + (now.tv_usec - g_timeval.tv_usec);
                    aps = 1000000 / total_usec * connected_num;

                    LOGWARN((TEST_MODULE, "cost:[%lu us] accepted num:[%lu] connection accepted per second:[%u]",
                                total_usec ,
                                connected_num,
                                aps
                            ));
                }

            }
        }
        break;

        case EV_CONNECT_FAILED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event connect failed sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_PASSIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn passive closed sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_ACTIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn active closed sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_TIMEOUT_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn timeout closed sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_ERROR_OCCURRED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event error occurred sockfd:[%d]", conn_id_.socket));
            connection_t::async_close(conn_id_);
        }
        break;

        default:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event unknown event sockfd:[%d]", conn_id_.socket));
        }
    }
}


#define STAT_TP(x) \
if (m_transferred_bytes == 2 * g_send_count * (g_send_packet_size + sizeof(packet_header_t)))                                       \
{                                                                                                                                   \
    LOGWARN((TEST_MODULE, "\nsend_buffer -\n%s", m_send_buffer.format_buffer_list_info().c_str()));                                   \
    LOGWARN((TEST_MODULE, "\nread_buffer -\n%s", m_read_buffer.format_buffer_list_info().c_str()));                                   \
    if (++g_finished_conn == g_active_conn_count) \
    {   \
        struct timeval now;                                                                                                         \
        gettimeofday(&now, NULL);                                                                                                   \
        uint64_t total_bytes = g_active_conn_count * m_transferred_bytes; \
        uint64_t total_mb = total_bytes / 1000 / 1000;                                                                              \
        uint64_t total_sec = now.tv_sec - g_timeval.tv_sec;                                                                         \
        if (0 != total_sec)                                                                                                         \
        {                                                                                                                           \
            uint64_t total_usec = (now.tv_sec - g_timeval.tv_sec) * 1000000 + (now.tv_usec - g_timeval.tv_usec);                    \
            LOGWARN((TEST_MODULE, x " cost:[%lu s], [%lu us] total bytes:[%lu bytes] tp:[%lu mb/s]",                               \
                        total_sec,                                                                                                  \
                        total_usec,                                                                                                 \
                        total_bytes,                                                                                                \
                        total_mb / total_sec                                                                                        \
                     ));                                                                                                            \
        }                                                                                                                           \
        else                                                                                                                        \
        {                                                                                                                           \
            uint64_t total_usec = (now.tv_sec - g_timeval.tv_sec) * 1000000 + (now.tv_usec - g_timeval.tv_usec);                    \
            LOGWARN((TEST_MODULE, x " cost:[%lu s], [%lu us] total bytes:[%lu bytes]",                                              \
                        total_sec,                                                                                                  \
                        total_usec,                                                                                                 \
                        total_bytes                                                                                                 \
                     ));                                                                                                            \
        }                                                                                                                           \
    }   \
}

//! yunjie: 客户端吞吐量测试的连接策略类
class test_tp_conn_strategt_t : public default_conn_strategy_t
{
public:
    test_tp_conn_strategt_t()
        :
            m_transferred_bytes(0)
    {
    }

protected:
    void on_read_complete(buffer_list_t& buffer_)
    {
        default_conn_strategy_t::on_read_complete(buffer_);        //! yunjie: 解析数据包, 完整后调用handle_packet
    }

    void on_write_complete(uint32_t transferred_size_)
    {
        m_transferred_bytes += transferred_size_;
        default_conn_strategy_t::on_write_complete(transferred_size_);
    }

    void handle_packet(const packet_header_t& packet_header_, const char* data_ptr_, uint32_t data_size_)
    {
        m_transferred_bytes += (data_size_ + HEADER_SIZE);

#if CHECK_SUM
        //! yunjie: check sum begin
        LOGINFO((TEST_MODULE, "test_tp_conn_strategt_t::handle_packet check sum"));
        string recv_data;
        recv_data.append((char*)&packet_header_, HEADER_SIZE);
        recv_data.append((char*)data_ptr_, data_size_);
        if (memcmp(recv_data.c_str(), g_send_data.c_str(), g_send_data.size()))
        {
            LOGWARN((TEST_MODULE, "test_tp_conn_strategt_t::handle_packet recv_data check sum failed!!!!!!"));
        }
        //! yunjie: check sum end
#endif

        STAT_TP("client")
        else
        {
            connection_t::async_send(this->get_conn_id(), g_send_data);
        }
    }

private:
    uint64_t                                            m_transferred_bytes;
};

//! yunjie: test throughput end

#endif //! _CHAOS_TEST_TCP_SERVER_H_
