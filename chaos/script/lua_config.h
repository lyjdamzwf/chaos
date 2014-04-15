/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_LUA_CONFIG_H_
#define _CHAOS_LUA_CONFIG_H_

/*!
 *  @file           script.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2013.11.30
 *  @brief          lua config
 *  @last changed
 *
 */

#include <string>
#include <vector>
#include <map>

#include <chaos/deps/lua_tinker/lua_tinker.h>
#include <chaos/utility/noncopyable.h>

namespace chaos
{

namespace script
{

using namespace std;

using namespace chaos::utility;

class lua_config_t : private noncopyable_t
{
public:
    typedef vector<string>                                          vct_val_t;
    typedef map<string, vct_val_t>                                  map_attr_t;
    typedef map<string, map_attr_t>                                 map_table_t;

    typedef void (*process_table_attr) (const string& key_, const string& val_);

public:
    lua_config_t();
    ~lua_config_t();

    int init(const string& lua_path_, const string& table_);
    int init(const string& lua_path_, const vector<string>& tables_);

    const string& operator[](const string& key_) const
    {
        return get(key_);
    }

    const string& get(const string& key_) const;
    const string& get(const string& table_, const string& key_) const;
    const vector<string>& get_multi(const string& key_) const;
    const vector<string>& get_multi(const string& table_, const string& key_) const;
    int enumerate(const string& table_, process_table_attr func_) const;

private:
    map_table_t                                                 m_map_table;
    lua_State                                                  *m_lua_state;
};

}

}

#endif // _CHAOS_LUA_CONFIG_H_
