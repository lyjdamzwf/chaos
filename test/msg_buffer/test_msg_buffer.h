#ifndef _CHAOS_TEST_MSG_BUFFER_H_
#define _CHAOS_TEST_MSG_BUFFER_H_

void test_msg_buffer()
{
    msg_buffer_t buffer;
    buffer.loop_2_printf_data();
    buffer.loop_2_printf_all();

    string s1(6, (char)1);
    cout << "append ret:" << buffer.append(s1.c_str(), s1.size()) << endl;
    buffer.loop_2_printf_data();
    buffer.loop_2_printf_all();

    cout << "append ret:" << buffer.append("1234", 4) << endl;
    buffer.loop_2_printf_data();
    buffer.loop_2_printf_all();

    cout << "append ret:" << buffer.append("9999999", 7) << endl;
    buffer.loop_2_printf_data();
    buffer.loop_2_printf_all();
}

void test_msg_buffer_limit()
{
    msg_buffer_t buffer;
    buffer.loop_2_printf_data();
    buffer.loop_2_printf_all();

    buffer.set_buffer_max_limit(8);

    string s(5, (char)1);
    cout << buffer.append(s.c_str(), s.size()) << endl;
    cout << buffer.capacity() << endl;

    cout << buffer.append(s.c_str(), s.size()) << endl;
    cout << buffer.capacity() << endl;
}

void test_buffer_list()
{
    buffer_list_t bl;

    string s1(7, (char)1);
    bl.append(s1.c_str(), s1.size());
    cout << bl.format_buffer_list_info() << endl;

    bl.append(s1.c_str(), s1.size());
    cout << bl.format_buffer_list_info() << endl;

    bl.append(s1.c_str(), s1.size());
    cout << bl.format_buffer_list_info() << endl;

    string s2(64, (char)9);
    bl.append(s2.c_str(), s2.size());
    cout << bl.format_buffer_list_info() << endl;

    bl.drain_size(999);
    cout << bl.format_buffer_list_info() << endl;

    bl.drain_size(999);
    cout << bl.format_buffer_list_info() << endl;

    bl.drain_size(999);
    bl.drain_size(999);
    bl.drain_size(999);
    bl.drain_size(999);
    cout << bl.format_buffer_list_info() << endl;
}

void test_buffer_list_limit()
{
    buffer_list_t bl;
    bl.set_buffer_max_limit(2048);

    string s(2000, (char)1);

    bl.append(s.c_str(), s.size());
    cout << bl.format_buffer_list_info() << endl;

    bl.append(s.c_str(), s.size());
    cout << bl.format_buffer_list_info() << endl;

    bl.set_buffer_max_limit(4096);
    bl.append(s.c_str(), s.size());
    cout << bl.format_buffer_list_info() << endl;
}

void test_serialize()
{
    serialize_t ser;
    ser.dump();

    ser.prepend("12345", strlen("12345"));
    ser.dump();

    ser << (int)1;
    ser.dump();

    ser << (uint64_t)1;
    ser.dump();

    ser.prepend("66666", strlen("66666"));
    ser.dump();

    ser.prepend("aaa", strlen("aaa"));
    ser.dump();
}

#endif //! _CHAOS_TEST_MSG_BUFFER_H_
