#include <vector>
#include <iostream>
using namespace std;

#include "../misc.h"
#include "test_timer.h"

int main(int argc_, char* argv_[])
{
    NEW_SERVICE();

    test_time_event();

    application_tool_t::wait_signal();

    DEL_SERVICE();

    return 0;
}

