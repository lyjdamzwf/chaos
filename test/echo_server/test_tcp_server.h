#ifndef _CHAOS_TEST_TCP_SERVER_H_
#define _CHAOS_TEST_TCP_SERVER_H_

#include <netinet/tcp.h>

void tcp_conn_event(
                    conn_event_e        conn_event_,
                    conn_status_e       conn_status_,
                    conn_id_t           conn_id_,
                    void*               use_data_
                   )
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

//! yunjie: echo服务器的连接策略类
class test_server_echo_conn_t : public default_conn_strategy_t
{
protected:
    void on_write_complete(uint32_t transferred_size_)
    {
        //! TP_STAT(SS(), "throughput", transferred_size_);
        default_conn_strategy_t::on_write_complete(transferred_size_);
    }

    void handle_packet(const packet_header_t& packet_header_, const char* data_ptr_, uint32_t data_size_)
    {
        //! PERF_GUARD(SS(), "handle request perf");
        //! ACT_CNT_STAT(SS(), "handle request count");
        //! TP_STAT(SS(), "throughput", (data_size_ + HEADER_SIZE));
        /*
        LOGINFO((TEST_MODULE,
                    "test_server_echo_conn_t::handle_packet fd:[%d] cmd:[%d] data size:[%d]",
                    native_socket(), packet_header_.cmd, data_size_
               ));
               */

        packet_wrapper_t packet;
        packet.append((char*)&packet_header_, sizeof(packet_header_));
        packet.append((char*)data_ptr_, data_size_);

        connection_t::async_send(this->get_conn_id(), packet, true);
    }
};

#endif //! _CHAOS_TEST_TCP_SERVER_H_
