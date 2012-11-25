#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_perf.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    application_tool_t::block_all_signal();
    log_tool_t::start_log_service("test_perf.log", 6, 1, 0);
    WSG().start(WSG_THREAD_NUM);

    test_atomic_perf();

    application_tool_t::wait_signal();
    WSG().stop();
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}

