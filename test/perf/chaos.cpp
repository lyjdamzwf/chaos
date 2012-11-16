#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_perf.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    WS().start(WS_THREAD_NUM);

    test_atomic_perf();

    application_tool_t::wait_signal();
    WS().stop();

    DEL_SERVICE();

    return 0;
}

