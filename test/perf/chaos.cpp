#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_perf.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    application_tool_t::block_all_signal();

    test_atomic_perf();

    application_tool_t::wait_signal();

    DEL_SERVICE();

    return 0;
}

