#include <vector>
#include <iostream>
using namespace std;

#include "utility_inc.h"
#include "thread_inc.h"
#include "task_service_inc.h"
#include "async_method_inc.h"
#include "log_inc.h"
#include "network_inc.h"
using namespace chaos::utility;
using namespace chaos::async_method;
using namespace chaos::thread;
using namespace chaos::task_service;
using namespace chaos::log;
using namespace chaos::network;

#include "../misc_def.h"
#include "test_msg_buffer.h"

int main(int argc_, char* argv_[])
{
    //test_msg_buffer();
    //test_buffer_list();
    //test_msg_buffer_limit();
    test_buffer_list_limit();

    /**
    char c[] = "yunjie";
    string s1;
    s1 = c;
    string s2(c);
    string s3 = s2;
    string s4;
    s4.append(c);
    string s5(s2);
    printf("stack arr:%p\n", &c);
    printf("assign by arr:%p\n", s1.c_str());
    printf("constructor:%p\n", s2.c_str());
    printf("assign by string:%p\n", s3.c_str());
    printf("append arr:%p\n", s4.c_str());
    printf("copy constructor:%p\n", s5.c_str());
    */

    return 0;
}

