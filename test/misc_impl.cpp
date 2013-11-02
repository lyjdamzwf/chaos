#include "misc_def.h"

task_service_t*             task_service_1104;
work_service_t*             work_service_1104;
work_service_group_t*       work_service_group_1104;
task_service_t*             log_service_1104;
statistic_service_t*        stat_service_1104;

volatile bool log_tool_t::is_started = false;


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

int lua_config_t::init(const string& lua_path_)
{
    regist_to_lua();
    load_from_lua(lua_path_);

    return 0;
}

int lua_config_t::regist_to_lua()
{
    // lua_tinker::class_add<lua_config_t>(m_lua_state, "lua_config_t");

    return 0;
}

int lua_config_t::load_from_lua(const string& lua_path_)
{
    if (!m_lua_state)
        return -1;

    lua_tinker::dofile(m_lua_state, lua_path_.c_str());

    lua_getglobal(m_lua_state, "echo_server_config");
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

        printf("%s : %s\n", key, val);
        add_cpp_config(key, val);
        
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

void lua_config_t::add_cpp_config(const char *key_, const char *val_)
{
    map_it_t found_it = m_config_map.find(key_);
    if (m_config_map.end() == found_it)
    {
        vector<string> new_vt;
        new_vt.push_back(val_);
        m_config_map.insert(make_pair(key_, new_vt));
    }
    else
    {
        vector<string>& found_vt = found_it->second;
        found_vt.push_back(val_);
    }
}

