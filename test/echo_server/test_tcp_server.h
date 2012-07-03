#ifndef _CHAOS_TEST_TCP_SERVER_H_
#define _CHAOS_TEST_TCP_SERVER_H_

void tcp_conn_event(conn_event_e conn_event_, conn_status_e conn_status_, conn_id_t conn_id_)
{
    LOGINFO((TEST_MODULE, "tcp_conn_event args-[conn_event:%d, conn_status:%d, socket fd:%d] begin", conn_event_, conn_status_, conn_id_.socket));

    switch (conn_event_)
    {
        case EV_ACCEPTED_COMPLETE:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event accepted complete"));
        }
        break;

        case EV_CONNECT_SUCCESS:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event connect success"));
        }
        break;

        case EV_ACTIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn active closed"));
        }
        break;

        case EV_PASSIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn passive closed"));
        }
        break;

        case EV_TIMEOUT_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn timeout closed"));
        }
        break;

        case EV_ERROR_OCCURRED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event error occurred"));
            connection_t::async_close(conn_id_);
        }
        break;

        default:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event unknown event"));
        }
    }

    LOGINFO((TEST_MODULE, "tcp_conn_event args-[conn_event:%d, conn_status:%d, socket fd:%d] end", conn_event_, conn_status_, conn_id_.socket));
}

//! yunjie: echo服务器的连接策略类
class test_server_echo_conn_t : public default_conn_strategy_t
{
protected:
    void handle_packet(const packet_header_t& packet_header_, const char* data_ptr_, uint32_t data_size_)
    {
        packet_wrapper_t packet;
        packet.append((char*)&packet_header_, sizeof(packet_header_));
        packet.append((char*)data_ptr_, data_size_);

        connection_t::async_send(this->get_conn_id(), packet);
    }
};

#endif //! _CHAOS_TEST_TCP_SERVER_H_
