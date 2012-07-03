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
#include "test_task_service.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    application_tool_t::block_all_signal();
    log_tool_t::start_log_service("echoserver.log", 6, 1, 1);
    TS().start(4);

    test_task_service_performance();
    
    application_tool_t::wait_signal();
    TS().stop();
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}

