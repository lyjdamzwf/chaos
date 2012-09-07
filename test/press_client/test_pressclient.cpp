#include "test_pressclient.h"

EXTERN_SERVICE_DECL 

uint32_t g_press_conn_num = PRESS_CONN_NUM;
uint32_t g_max_packet_size = MAX_PACKET_SIZE;
connector_service_t<test_press_conn_strategy_t>* g_connector_service_ptr;

static bool broadcast_filter(const conn_id_t& conn_id_, void* user_data_)
{
    return false; 
}

void entity_t::handle_wrapper_message(
                                        const packet_header_t&  packet_header_,
                                        const packet_wrapper_t& message_,
                                        const conn_id_t&        conn_id_
                                     )
{
    handle_message(packet_header_, message_.c_str(), message_.size(), conn_id_);
}


void entity_t::handle_message(
                                const packet_header_t&  packet_header_,
                                const char*             data_ptr_,
                                uint32_t                data_size_,
                                const conn_id_t&        conn_id_
                             )
{
#if CHECK_SUM
    if (packet_header_.cmd != BROADCAST_CMD)
    {
        //! yunjie: check sum begin
        LOGINFO((TEST_MODULE, "entity_t::handle_message check sum"));
        string recv_data;
        recv_data.append((char*)&packet_header_, HEADER_SIZE);
        recv_data.append((char*)data_ptr_, data_size_);
        if (0 != m_last_packet.size()
            && (recv_data.size() != m_last_packet.size()
            || memcmp(recv_data.c_str(), m_last_packet.c_str(), m_last_packet.size()))
           )
        {
            LOGWARN((TEST_MODULE, "entity_t::handle_message recv_data check sum failed!!!!!!"));
            printf("check sum failed exit!!!! last packet size:[%lu] recv size:[%d]\n", m_last_packet.size(), data_size_);
            exit(0);
        }
        //! yunjie: check sum end
    }
#endif

    bool done = false;
    int conn_action = PCA_BEGIN + 1;

    while (!done)
    {
        switch (conn_action)
        {
            case PCA_REPEAT:
                {
                    if (!rand_gen_t::calc_probability(REPEAT_PRO))
                    {
                        goto NEXT_ACTION;
                    }

                    packet_wrapper_t packet;
                    packet.append((char*)&packet_header_, sizeof(packet_header_));
                    packet.append((char*)data_ptr_, data_size_);
                    connection_t::async_send(conn_id_, packet);

                    m_last_packet.clear();
                    m_last_packet.append(packet);

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_REPEAT packet body size:[%u]", data_size_));
                    done = true;
                }
                break;

            case PCA_RESEND:
                {
                    if (!rand_gen_t::calc_probability(RESEND_PRO))
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

                    connection_t::async_send(conn_id_, packet);

                    m_last_packet.clear();
                    m_last_packet.append(packet);

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_RESEND packet body size:[%u]", body_size));
                    done = true;
                }
                break;

            case PCA_BROADCAST:
                {
                    if (!rand_gen_t::calc_probability(BC_PRO))
                    {
                        goto NEXT_ACTION;
                    }

                    packet_wrapper_t packet;

                    char content_buffer[256] = {0};
                    snprintf(content_buffer, sizeof(content_buffer), "broadcast message from socket:[%d]", conn_id_.socket);

                    packet_header_t header;
                    header.cmd = BROADCAST_CMD;
                    header.data_len = strlen(content_buffer);

                    packet.append((char*)&header, sizeof(packet_header_t));
                    packet.append(content_buffer, header.data_len);

                    g_connector_service_ptr->async_broadcast(packet, broadcast_filter);

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_BROADCAST"));
                    done = true;
                }
                break;

            case PCA_CLOSE:
                {
                    if (!rand_gen_t::calc_probability(CLOSE_PRO))
                    {
                        goto NEXT_ACTION;
                    }

                    connection_t::async_close(conn_id_);

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_CLOSE"));
                    done = true;
                }
                break;

            case PCA_WAIT_HEART_BEAT:
                {
                    if (!rand_gen_t::calc_probability(HB_PRO))
                    {
                        goto NEXT_ACTION;
                    }

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_WAIT_HEART_BEAT do nothing"));
                    done = true;
                }
                break;

            default:
                {
                    LOGINFO((TEST_MODULE, "entity_t::handle_message UNKNOW PCA ACTION"));
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

static void delete_entity(entity_t* entity_)
{
    SAFE_DELETE(entity_);
}

void press_client_t::tcp_press_conn_event(
                                            conn_event_e    conn_event_,
                                            conn_status_e   conn_status_,
                                            conn_id_t       conn_id_,
                                            void*           user_data_
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
            entity_t* entity_ptr = (entity_t*)user_data_;
            TS().post(bind_func(delete_entity, entity_ptr));
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

            connection_t::async_send(conn_id_, packet);
        }
        break;

        case EV_CONNECT_FAILED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event connect failed sockfd:[%d]", conn_id_.socket));
        }
        break;

        case EV_ACTIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn active closed sockfd:[%d]", conn_id_.socket));
            //! yunjie: 关闭后再发起一个连接
            test_press_client(1);
        }
        break;

        case EV_PASSIVE_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn passive closed sockfd:[%d]", conn_id_.socket));
            //! yunjie: 关闭后再发起一个连接
            test_press_client(1);
        }
        break;

        case EV_TIMEOUT_CLOSED:
        {
            LOGINFO((TEST_MODULE, "tcp_conn_event conn timeout closed sockfd:[%d]", conn_id_.socket));
            //! yunjie: 关闭后再发起一个连接
            test_press_client(1);
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

int press_client_t::test_press_client(int conn_num_)
{
    for (int i = 0; i < conn_num_; ++i)
    {
        g_connector_service_ptr->async_connect(
                LOCALHOST,
                8880,
                tcp_press_conn_event,
                true
                );
    }

    return 0;
}

void test_press_conn_strategy_t::handle_packet(
                                const packet_header_t&  packet_header_,
                                const char*             data_ptr_,
                                uint32_t                data_size_
                                              )
{
    if (!rand_gen_t::calc_probability(CROSS_THREAD))
    {
        get_entity()->handle_message(packet_header_, data_ptr_, data_size_, get_conn_id()); 
    }
    else
    {
        packet_wrapper_t message(data_ptr_, data_size_);
        TS().post(bind_memfunc(
                    get_entity(),
                    &entity_t::handle_wrapper_message,
                    packet_header_,
                    message,
                    get_conn_id() 
                    )
                );
    }
}

