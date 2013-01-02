#include "misc_def.h"

task_service_t*             task_service_1104;
work_service_t*             work_service_1104;
work_service_group_t*       work_service_group_1104;
task_service_t*             log_service_1104;
statistic_service_t*        stat_service_1104;

volatile bool log_tool_t::is_started = false;

LUA_REGISTER_BEGIN(lua_config_register)
REGISTER_CLASS_BASE("string_t", string, void (void))
REGISTER_CLASS_BASE("lua_config_t", lua_config_t, void (void))
REGISTER_CLASS_METHOD("lua_config_t", "add_cpp_config", lua_config_t, &lua_config_t::add_cpp_config)
LUA_REGISTER_END

lua_config_t::lua_config_t()
    :
        m_mylua_ptr(NULL)
{
}

int lua_config_t::load_from_lua(const string& lua_path_)
{
    SAFE_DELETE(m_mylua_ptr);
    m_mylua_ptr = new mylua_t;
    if (NULL == m_mylua_ptr)
    {
        return -1;
    }

    m_mylua_ptr->multi_register(lua_config_register);
    m_mylua_ptr->load_file(lua_path_);
    m_mylua_ptr->call("read_config", this);

    return 0;
}

string lua_config_t::get(const string& key_) const
{
    vector<string> result = get_multi(key_);
    if (result.size())
    {
        return result[0];
    }

    return "";
}

vector<string> lua_config_t::get_multi(const string& key_) const
{
    vector<string> ret;
    map_const_it_t found_it = m_config_map.find(key_);
    if (m_config_map.end() != found_it)
    {
        const vector<string>& found_vt = found_it->second;
        if (found_vt.size())
        {
            ret.resize(found_vt.size());
            std::copy(found_vt.begin(), found_vt.end(), ret.begin());
        }
    }

    return ret;
}

void lua_config_t::add_cpp_config(string key_, string val_)
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

