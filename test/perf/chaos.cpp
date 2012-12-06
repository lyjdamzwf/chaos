#include <vector>
#include <iostream>
using namespace std;

#include "../misc_def.h"
#include "test_perf.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    test_atomic_perf();

    application_tool_t::wait_signal();

    DEL_SERVICE();

    return 0;
}

