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
#include "test_timer.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    test_time_event();

    application_tool_t::wait_signal();

    DEL_SERVICE();

    return 0;
}

