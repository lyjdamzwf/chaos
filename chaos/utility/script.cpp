#include <chaos/utility/script.h>

#include <inttypes.h>

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


lua_config_t::lua_config_t()
    :
    m_lua_state(NULL)
{
    m_lua_state = lua_open();
    luaL_openlibs(m_lua_state);
}

lua_config_t::~lua_config_t()
{
    lua_close(m_lua_state);
}

int lua_config_t::init(const string& lua_path_, const string& table_)
{
    if (!m_lua_state)
        return -1;

    lua_tinker::dofile(m_lua_state, lua_path_.c_str());

    lua_getglobal(m_lua_state, table_.c_str());
    lua_pushnil(m_lua_state);

    char key_buf[50];
    char val_buf[50];

    const char *key, *val;

    while(lua_next(m_lua_state,-2))
    {
        if(lua_isnumber(m_lua_state,-2))
        {
            sprintf(key_buf, "%" PRId64, lua_tonumber(m_lua_state,-2));
            key = key_buf;
        }
        else if(lua_isstring(m_lua_state,-2))
        {
            key = lua_tostring(m_lua_state,-2);
        }
        if(lua_isnumber(m_lua_state,-1))
        {
            sprintf(val_buf, "%" PRId64, lua_tonumber(m_lua_state,-1));
            val = val_buf;
        }
        else if(lua_isstring(m_lua_state,-1))
        {
            val = lua_tostring(m_lua_state,-1);
        }

        m_config_map[key].push_back(val);

        lua_pop(m_lua_state,1);
    }

    lua_pop(m_lua_state,1);

    return 0;
}

const string& lua_config_t::get(const string& key_) const
{
    const vector<string>& result = get_multi(key_);
    if (result.size())
    {
        return result[0];
    }

    static string empty;

    return empty;
}

const vector<string>& lua_config_t::get_multi(const string& key_) const
{
    map_const_it_t found_it = m_config_map.find(key_);
    if (m_config_map.end() != found_it)
    {
        return found_it->second;
    }

    static vector<string> empty;

    return empty;
}

}

}
