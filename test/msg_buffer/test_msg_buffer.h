#ifndef _CHAOS_TEST_MSG_BUFFER_H_
#define _CHAOS_TEST_MSG_BUFFER_H_

#include <vector>
#include <string>
using namespace std;

static vector<string> s_vt;
static vector<msg_buffer_t> b_vt;

#define VT_INFO(len)    \
s_vt[len - 1].data(), s_vt[len - 1].size()

void test_msg_buffer()
{
    for (int i = 1; i <= 5000; ++i)
    {
        s_vt.push_back(string(i, (char)i));
    }

    for (int i = 1; i <= 20; ++i)
    {
        b_vt.push_back(msg_buffer_t());
    }

    cout << "\n\n\n############# append ret:"
         << b_vt[0].append(18, 32)
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# append ret:"
         << b_vt[0].append(VT_INFO(5))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    b_vt[0].set_no_limit();

    cout << "\n\n\n############# append ret:"
         << b_vt[0].append(VT_INFO(7))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    b_vt[0].set_buffer_max_limit(64);
    cout << "\n\n\n############# append ret:"
         << b_vt[0].append(200, 6)
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# drain ret:"
         << b_vt[0].drain_size(5)
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[0].prepend(VT_INFO(3))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[0].prepend(VT_INFO(6))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# drain ret:"
         << b_vt[0].drain_size(128)
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# append ret:"
         << b_vt[0].append(VT_INFO(50))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[0].prepend(VT_INFO(10))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# drain ret:"
         << b_vt[0].drain_size(20)
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[0].prepend(VT_INFO(10))
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[0].append(23, 19)
         << "#############\n"
         << endl;
    b_vt[0].loop_2_printf_data();
    b_vt[0].loop_2_printf_all();

    /**
    cout << "\n\n\n############# append ret:"
         << b_vt[1].append(VT_INFO(50))
         << "#############\n"
         << endl;
    b_vt[1].loop_2_printf_data();
    b_vt[1].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[2].prepend(VT_INFO(18))
         << "#############\n"
         << endl;
    b_vt[2].loop_2_printf_data();
    b_vt[2].loop_2_printf_all();

    cout << "\n\n\n############# prepend ret:"
         << b_vt[3].prepend(VT_INFO(50))
         << "#############\n"
         << endl;
    b_vt[3].loop_2_printf_data();
    b_vt[3].loop_2_printf_all();
    */
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

    ser.prepend(3, 13);
    ser.dump();

    ser.append(20, 120);
    ser.dump();
}

#endif //! _CHAOS_TEST_MSG_BUFFER_H_
