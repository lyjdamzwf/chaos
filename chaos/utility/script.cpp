#include <chaos/utility/script.h>

namespace chaos
{

namespace utility
{

script::script()
{
	_L = lua_open();
	luaL_openlibs(_L);
    add_package_path("./");
}

script::~script()
{
    lua_close(_L);
}

void script::do_file(const char * fn)
{
	lua_tinker::dofile(_L, fn);
	_scriptName = fn;
}

void script::run_script(const char * str)
{
	lua_tinker::dostring(_L, str);
}

lua_tinker::table script::get_table()
{
	return lua_tinker::table(_L);
}

lua_tinker::table script::get_table( int index )
{
	return lua_tinker::table(_L, index);
}

lua_tinker::table script::get_table( const char * name )
{
	return lua_tinker::table(_L, name);
}

void script::reload()
{
	lua_close(_L);
	_L = lua_open();
	luaL_openlibs(_L);
	add_package_path(_pkg_path.c_str());
    register_lua_interface();

    if (!_scriptName.empty())
        do_file(_scriptName.c_str());
}

void script::register_lua_interface()
{
    
}

void script::add_package_path(const string& path_)
{
	if(!path_.empty())
	{
		lua_tinker::table pkg = lua_tinker::get<lua_tinker::table>(_L, "package");
		const char * path = pkg.get<const char *>("path");
		std::string newpath = path;
		newpath = newpath + ";" + path_ + "/?.lua";
		pkg.set("path", newpath.c_str());

        _pkg_path = path_;
	}
}

}

}
