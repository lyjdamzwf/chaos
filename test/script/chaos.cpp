#include <chaos/utility/script.h>

using namespace chaos::utility;

int main(int argc_, char *argv_[])
{
    script s;
    s.add_package_path("./lua_package");
    s.register_lua_interface();
    s.do_file("./entry.lua");

    sleep(10);
    s.reload();
    
    return 0;
}
