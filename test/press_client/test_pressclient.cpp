#include <signal.h>

#include "test_pressclient.h"

EXTERN_SERVICE_DECL

uint32_t g_press_conn_num = PRESS_CONN_NUM;
uint32_t g_max_packet_size = MAX_PACKET_SIZE;
connector_service_t<test_press_conn_strategy_t>* g_connector_service_ptr;

static bool broadcast_filter(const conn_id_t& conn_id_, void* user_data_)
{
    return true;
}

void entity_t::handle_wrapper_message(
                                        const packet_header_t&  packet_header_,
                                        const packet_wrapper_t& message_,
                                        const conn_id_t&        conn_id_,
                                        const string&           service_name_
                                     )
{
    handle_message(packet_header_, message_.data(), message_.size(), conn_id_, service_name_);
}


void entity_t::handle_message(
                                const packet_header_t&  packet_header_,
                                const char*             data_ptr_,
                                uint32_t                data_size_,
                                const conn_id_t&        conn_id_,
                                const string&           service_name_
                             )
{
    //! yunjie: 如果收到的不是自己发的broadcast消息则不响应
    if (packet_header_.cmd == BROADCAST_CMD)
    {
        void* zero_ret = memchr(data_ptr_, 0, data_size_);
        if (NULL == zero_ret)
            return;
        conn_id_t* conn_id_ptr = (conn_id_t*)((char*)zero_ret + 1);
        if (!(conn_id_ == *conn_id_ptr))
            return;
    }

#if CHECK_SUM
    //! yunjie: check sum begin
    //! LOGINFO((TEST_MODULE, "entity_t::handle_message check sum"));
    string recv_data;
    recv_data.append((char*)&packet_header_, HEADER_SIZE);
    recv_data.append((char*)data_ptr_, data_size_);

    if (0 != m_last_packet.size()
        && (recv_data.size() != m_last_packet.size()
        || memcmp(recv_data.data(), m_last_packet.data(), m_last_packet.size()))
       )
    {
        LOGWARN((TEST_MODULE, "entity_t::check sum failed"
                    " service:[%s] fd:[%d]"
                    " last packet - [cmd:%d, size:%lu]"
                    " recv packet - [cmd:%d, size:%lu]",
                    service_name_.c_str(), conn_id_.socket,
                    *(header_cmd_t*)m_last_packet.data(), m_last_packet.size(),
                    packet_header_.cmd, recv_data.size()
                ));

        //! yunjie: 0表示发送给同一进程组的所有进程
        //          raise只能发给当前线程
        kill(0, SIGINT);

        return;
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
                    if (!rand_gen_t::calc_probability(REPEAT_PRO))
                    {
                        goto NEXT_ACTION;
                    }

                    packet_wrapper_t packet;
                    packet.append((char*)&packet_header_, sizeof(packet_header_));
                    packet.append((char*)data_ptr_, data_size_);
                    m_last_packet = packet;

                    connection_t::async_send(conn_id_, packet);

                    LOGINFO((TEST_MODULE,
                                "entity_t::handle_message PCA_REPEAT service:[%s] fd:[%d] packet size:[%u]",
                                service_name_.c_str(), conn_id_.socket, packet.size()
                           ));
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
                    header.cmd = GENERAL_CMD;
                    header.ext = conn_id_.socket;
                    header.data_len = body_size;

                    packet_wrapper_t packet;
                    packet.append((char*)&header, sizeof(header));
                    if (0 != body_size)
                    {
                        packet.append(body_size, 'a');
                    }

                    m_last_packet = packet;

                    connection_t::async_send(conn_id_, packet);

                    LOGINFO((TEST_MODULE,
                                "entity_t::handle_message PCA_RESEND service:[%s] fd:[%d] packet size:[%u]",
                                service_name_.c_str(), conn_id_.socket, packet.size()
                           ));
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

                    char content_buffer[512] = {0};
                    snprintf(content_buffer, sizeof(content_buffer), "broadcast message from socket:%d", conn_id_.socket);
                    //! yunjie: 将conn_id放到字符串'\0'的后面
                    memcpy(&content_buffer[strlen(content_buffer) + 1], &conn_id_, sizeof(conn_id_t));
                    int data_len = strlen(content_buffer) + 1 + sizeof(conn_id_t);

                    packet_header_t header;
                    header.cmd = BROADCAST_CMD;
                    header.ext = conn_id_.socket;
                    header.data_len = data_len;

                    packet.append((char*)&header, sizeof(packet_header_t));
                    packet.append(content_buffer, header.data_len);

                    m_last_packet = packet;

                    g_connector_service_ptr->async_broadcast(packet, broadcast_filter);

                    LOGINFO((TEST_MODULE,
                                "entity_t::handle_message PCA_BROADCAST service:[%s] fd:[%d] packet size:[%lu]",
                                service_name_.c_str(), conn_id_.socket, packet.size()
                           ));
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

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_CLOSE service:[%s] fd:[%d]",
                                service_name_.c_str(), conn_id_.socket
                           ));
                    done = true;
                }
                break;

            case PCA_WAIT_HEART_BEAT:
                {
                    if (!rand_gen_t::calc_probability(HB_PRO))
                    {
                        goto NEXT_ACTION;
                    }

                    LOGINFO((TEST_MODULE, "entity_t::handle_message PCA_WAIT_HEART_BEAT service:[%s] fd:[%d]",
                                service_name_.c_str(), conn_id_.socket
                           ));
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
            header.cmd = GENERAL_CMD;
            header.ext = conn_id_.socket;
            header.data_len = body_size;

            packet_wrapper_t packet;
            packet.append((char*)&header, sizeof(header));
            if (0 != body_size)
            {
                packet.append(body_size, 'a');
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
        get_entity()->handle_message(packet_header_, data_ptr_, data_size_, get_conn_id(), string("work service"));
    }
    else
    {
        packet_wrapper_t message(data_ptr_, data_size_);
        TS().post(bind_memfunc(
                    get_entity(),
                    &entity_t::handle_wrapper_message,
                    packet_header_,
                    message,
                    get_conn_id(),
                    TS().get_name()
                    )
                );
    }
}

