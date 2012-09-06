#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_log.h"

EXTERN_SERVICE_DECL

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    log_tool_t::start_log_service("testlog.log", 6, 1, 1);

    test_log();

    application_tool_t::wait_signal();
    log_tool_t::stop_log_service();

    DEL_SERVICE();

    return 0;
}

