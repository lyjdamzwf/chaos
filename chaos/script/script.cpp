#include <chaos/utility/utility_inc.h>

#include <chaos/script/script.h>

#include <inttypes.h>

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
    vector<string> v;
    v.push_back(table_);
    init(lua_path_, v);

    return 0;
}

int lua_config_t::init(const string& lua_path_, const vector<string>& tables_)
{
   if (!m_lua_state)
        return -1;

    lua_tinker::dofile(m_lua_state, lua_path_.c_str());

    for (size_t i = 0; i < tables_.size(); ++i)
    {
        const string& table = tables_[i];

        lua_getglobal(m_lua_state, table.c_str());
        lua_pushnil(m_lua_state);

        char key_buf[50];
        char val_buf[50];

        const char *key, *val;

        while (lua_next(m_lua_state,-2))
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

            m_map_table[table][key].push_back(val);

            lua_pop(m_lua_state,1);
        }

        lua_pop(m_lua_state,1);
    }

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

const string& lua_config_t::get(const string& table_, const string& key_) const
{
    const vector<string>& result = get_multi(table_, key_);
    if (result.size())
    {
        return result[0];
    }

    static string empty;

    return empty;
}

const vector<string>& lua_config_t::get_multi(const string& key_) const
{
    static vector<string> empty;

    if (!m_map_table.size())
        return empty;

    return get_multi(m_map_table.begin()->first, key_);
}

const vector<string>& lua_config_t::get_multi(const string& table_, const string& key_) const
{
    map_table_t::const_iterator table_it = m_map_table.find(table_);
    if (m_map_table.end() != table_it)
    {
        map_attr_t::const_iterator attr_it =  table_it->second.find(key_);
        if (table_it->second.end() != attr_it)
        {
            return attr_it->second;
        }
    }

    static vector<string> empty;

    return empty;
}

int lua_config_t::enumerate(const string& table_, process_table_attr func_) const
{
    int count = 0;

    map_table_t::const_iterator tbl_it = m_map_table.find(table_);
    if (tbl_it != m_map_table.end())
    {
        const map_attr_t& map_attr = tbl_it->second;
        for (map_attr_t::const_iterator attr_it = map_attr.begin();
             attr_it != map_attr.end();
             ++attr_it
            )
        {
            const string& key = attr_it->first;
            const vct_val_t& vct_val = attr_it->second;

            for (size_t i = 0; i < vct_val.size(); ++i)
            {
                func_(key, vct_val[i]);
                count++;
            }
        }
    }

    return count;
}

}

}
