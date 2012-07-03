#ifndef _CHAOS_TEST_TCP_SERVER_H_
#define _CHAOS_TEST_TCP_SERVER_H_

//! yunjie: test press begin

#define PRESS_CONN_NUM  100
#define MIN_PACKET_SIZE (sizeof(packet_header_t))
#define MAX_PACKET_SIZE (sizeof(packet_header_t) + 4096)

#define CHECK_SUM 1

uint32_t g_press_conn_num = PRESS_CONN_NUM;
uint32_t g_max_packet_size = MAX_PACKET_SIZE;

enum press_conn_action_e
{
    PCA_BEGIN = 0,
    PCA_REPEAT,
    PCA_RESEND,
    PCA_CLOSE,
    PCA_WAIT_HEART_BEAT,
    PCA_END
};

int test_press_client(int conn_num_);

void tcp_press_conn_event(conn_event_e conn_event_, conn_status_e conn_status_, conn_id_t conn_id_)
{
    LOGINFO((TEST_MODULE, "tcp_press_conn_event args-[conn_event:%d, conn_status:%d, socket fd:%d] begin", conn_event_, conn_status_, conn_id_.socket));

    switch (conn_event_)
    {
        case EV_ACCEPTED_COMPLETE:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event accepted complete"));
        }
        break;

        case EV_CONNECT_SUCCESS:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event connect success"));
        }
        break;

        case EV_ACTIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event conn active closed"));
            //! yunjie: 关闭后再发起一个连接
            test_press_client(1);
        }
        break;

        case EV_PASSIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event conn passive closed"));
            //! yunjie: 关闭后再发起一个连接
            test_press_client(1);
        }
        break;

        case EV_TIMEOUT_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event conn timeout closed"));
            //! yunjie: 关闭后再发起一个连接
            test_press_client(1);
        }
        break;

        case EV_ERROR_OCCURRED:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event error occurred"));
            connection_t::async_close(conn_id_);
        }
        break;

        default:
        {
            LOGINFO((TEST_MODULE, "tcp_press_conn_event unknown event"));
        }
    }

    LOGINFO((TEST_MODULE, "tcp_server_conn_event args-[conn_event:%d, conn_status:%d, socket fd:%d] end", conn_event_, conn_status_, conn_id_.socket));
}


class test_press_conn_strategy_t : public default_conn_strategy_t
{
protected:
    void handle_packet(const packet_header_t& packet_header_, const char* data_ptr_, uint32_t data_size_)
    {

#if CHECK_SUM 
        //! yunjie: check sum begin
        LOGINFO((TEST_MODULE, "test_press_conn_strategy_t::handle_packet check sum"));
        string recv_data;
        recv_data.append((char*)&packet_header_, HEADER_SIZE);
        recv_data.append((char*)data_ptr_, data_size_);
        if (memcmp(recv_data.c_str(), m_last_packet.c_str(), m_last_packet.size()))
        {
            LOGWARN((TEST_MODULE, "test_press_conn_strategy_t::handle_packet recv_data check sum failed!!!!!!"));
            sleep(10);
            printf("exit!!!!\n");
            exit(0);
        }
        //! yunjie: check sum end
#endif

        bool done = false;
        int conn_action = PCA_BEGIN + 1;

        while (!done)
        {
            switch (conn_action)
            {
                case PCA_REPEAT:
                {
                    if (!rand_gen_t::calc_probability(70))
                    {
                        goto NEXT_ACTION;
                    }

                    packet_wrapper_t packet;
                    packet.append((char*)&packet_header_, sizeof(packet_header_));
                    packet.append((char*)data_ptr_, data_size_);
                    connection_t::async_send(this->get_conn_id(), packet);

                    m_last_packet.clear();
                    m_last_packet.append(packet);

                    LOGINFO((TEST_MODULE, "test_press_conn_strategy_t::handle_packet PCA_REPEAT packet body size:[%u]", data_size_));
                    done = true;
                }
                break;
                
                case PCA_RESEND:
                {
                    if (!rand_gen_t::calc_probability(70))
                    {
                        goto NEXT_ACTION;
                    }

                    uint32_t packet_size = rand_gen_t::get_rand(MIN_PACKET_SIZE, g_max_packet_size + 1);
                    uint32_t body_size = packet_size - sizeof(packet_header_t);

                    packet_header_t header;
                    header.cmd = 1121;
                    header.ext = 1104;
                    header.data_len = body_size;

                    char data[g_max_packet_size];

                    packet_wrapper_t packet;
                    packet.append((char*)&header, sizeof(header));
                    if (0 != body_size)
                    {
                        packet.append(data, body_size);
                    }

                    connection_t::async_send(this->get_conn_id(), packet);

                    m_last_packet.clear();
                    m_last_packet.append(packet);

                    LOGINFO((TEST_MODULE, "test_press_conn_strategy_t::handle_packet PCA_RESEND packet body size:[%u]", body_size));
                    done = true;
                }
                break;

                case PCA_CLOSE:
                {
                    if (!rand_gen_t::calc_probability(20))
                    {
                        goto NEXT_ACTION;
                    }

                    connection_t::async_close(get_conn_id());

                    LOGINFO((TEST_MODULE, "test_press_conn_strategy_t::handle_packet PCA_CLOSE"));
                    done = true;
                }
                break;

                case PCA_WAIT_HEART_BEAT:
                {
                    if (!rand_gen_t::calc_probability(20))
                    {
                        goto NEXT_ACTION;
                    }

                    LOGINFO((TEST_MODULE, "test_press_conn_strategy_t::handle_packet PCA_WAIT_HEART_BEAT do nothing"));
                    done = true;
                }
                break;

                default:
                {
                    LOGINFO((TEST_MODULE, "test_press_conn_strategy_t::handle_packet UNKNOW PCA ACTION"));
                }
                break;
            };

NEXT_ACTION:
            if (PCA_END == ++conn_action)
            {
                conn_action = PCA_BEGIN + 1;
            }
        }
    }

private:
    string                                      m_last_packet;
};


int test_press_client(int conn_num_)
{
    for (int i = 0; i < conn_num_; ++i)
    {
        conn_id_t conn_id;
        int ret = active_connection_t::sync_connect<test_press_conn_strategy_t>(conn_id, tcp_press_conn_event, LOCALHOST, 8880, &WS(), true);
        if (-1 == ret)
        {
            LOGINFO((TEST_MODULE, "sync_connect failed."));
            return -1;
        }

        LOGINFO((TEST_MODULE, "connect success fd:[%u]", conn_id.socket));

        uint32_t packet_size = rand_gen_t::get_rand(MIN_PACKET_SIZE, g_max_packet_size + 1);
        uint32_t body_size = packet_size - sizeof(packet_header_t);

        packet_header_t header;
        header.cmd = 1121;
        header.ext = 1104;
        header.data_len = body_size;

        char data[g_max_packet_size];

        packet_wrapper_t packet;
        packet.append((char*)&header, sizeof(header));
        if (0 != body_size)
        {
            packet.append(data, body_size);
        }

        connection_t::async_send(conn_id, packet);
    }

    return 0;
}

//! yunjie: test press end

#endif //! _CHAOS_TEST_TCP_SERVER_H_
