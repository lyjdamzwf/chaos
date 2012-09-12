#ifndef _CHAOS_TEST_TCP_SERVER_H_
#define _CHAOS_TEST_TCP_SERVER_H_

#include "../misc_def.h"

//! yunjie: test press begin

#define PRESS_CONN_NUM  100
#define MIN_PACKET_SIZE (sizeof(packet_header_t))
#define MAX_PACKET_SIZE (sizeof(packet_header_t) + 4096)

#define CHECK_SUM 1

#define BROADCAST_CMD   1104
#define GENERAL_CMD     1121

enum press_conn_action_e
{
    PCA_BEGIN = 0,
    PCA_REPEAT,
    PCA_RESEND,
    PCA_BROADCAST,
    PCA_CLOSE,
    PCA_WAIT_HEART_BEAT,
    PCA_END
};

#define CROSS_THREAD    100

#define REPEAT_PRO  70
#define RESEND_PRO  70
#define BC_PRO      50
#define CLOSE_PRO   20
#define HB_PRO      20

class entity_t
{
public:
    void handle_wrapper_message(
                                const packet_header_t&  packet_header_,
                                const packet_wrapper_t& message_,
                                const conn_id_t&        conn_id_,
                                const string&           service_name_
                               );

    void handle_message(
                        const packet_header_t&  packet_header_,
                        const char*             data_ptr_,
                        uint32_t                data_size_,
                        const conn_id_t&        conn_id_,
                        const string&           service_name_
                       );

    packet_wrapper_t last_packet() const { return m_last_packet; }

private:
    packet_wrapper_t                    m_last_packet;
};

class press_client_t
{
public:

    static void tcp_press_conn_event(
                                        conn_event_e    conn_event_,
                                        conn_status_e   conn_status_,
                                        conn_id_t       conn_id_,
                                        void*           user_data_
                                      );

    static int test_press_client(int conn_num_);
};

class test_press_conn_strategy_t : public default_conn_strategy_t
{
protected:
    void handle_packet(
                        const packet_header_t&  packet_header_,
                        const char*             data_ptr_,
                        uint32_t                data_size_
                      );

private:
    void init_entity() { get_entity(); }

    entity_t* get_entity()
    {
        entity_t* ret;
        while (NULL == (ret = (entity_t*)get_userdata()))
        {
            set_userdata(new entity_t);
        }

        return ret;
    }
};


//! yunjie: test press end

#endif //! _CHAOS_TEST_TCP_SERVER_H_
