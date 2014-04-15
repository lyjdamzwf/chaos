#include <chaos/utility/utility_inc.h>

#include <chaos/script/script.h>

namespace chaos
{

namespace script
{

using namespace chaos::utility;

script_t::script_t()
{
	_L = lua_open();
	luaL_openlibs(_L);
    add_package_path("./");
}

script_t::~script_t()
{
    lua_close(_L);
}

void script_t::do_file(const char * fn)
{
	lua_tinker::dofile(_L, fn);
	_scriptName = fn;
}

void script_t::run_script(const char * str)
{
	lua_tinker::dostring(_L, str);
}

lua_tinker::table script_t::get_table()
{
	return lua_tinker::table(_L);
}

lua_tinker::table script_t::get_table( int index )
{
	return lua_tinker::table(_L, index);
}

lua_tinker::table script_t::get_table( const char * name )
{
	return lua_tinker::table(_L, name);
}

void script_t::reload()
{
	lua_close(_L);
	_L = lua_open();
	luaL_openlibs(_L);
	add_package_path(_pkg_path.c_str());
    register_lua_interface();

    if (!_scriptName.empty())
        do_file(_scriptName.c_str());
}

void script_t::register_lua_interface()
{
    lua_tinker::def(_L, "logfatal", &script_t::logfatal);
    lua_tinker::def(_L, "logerror", &script_t::logerror);
    lua_tinker::def(_L, "logwarn", &script_t::logwarn);
    lua_tinker::def(_L, "loginfo", &script_t::loginfo);
    lua_tinker::def(_L, "logtrace", &script_t::logtrace);
    lua_tinker::def(_L, "logdebug", &script_t::logdebug);

    lua_tinker::def(_L, "get_rand", &rand_gen_t::get_rand);
}

void script_t::add_package_path(const string& path_)
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

service_script_t::service_script_t(task_service_t *service_)
    :
    m_service(service_)
{
}

service_script_t::~service_script_t()
{
}

void service_script_t::register_timer()
{
}

}

}
