#ifndef _LUA_TRAITS_H_
#define _LUA_TRAITS_H_

#include <stdint.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include <chaos/utility/utility_inc.h>
using namespace chaos::utility;

#include <chaos/mylua/lua-5.1.4/src/lua.hpp>
#include <chaos/mylua/lua_type.h>

//! this traits avoid G++ warnging
//! for example, ARG1 arg1;
//! when type of ARG1 is void *, gcc will print warnging info.
//! so we use ARG1 arg1 = init_value_traits_t<ARG1>::init_value();

namespace chaos
{

namespace mylua
{

template <typename T>
struct init_value_traits_t;

template <typename T>
struct init_value_traits_t
{
    inline static T init_value(){ return 0; }
};

template <>
struct init_value_traits_t<string>
{
    inline static const char* init_value(){ return ""; }
};

class lua_table_t;
template <>
struct init_value_traits_t<lua_table_t>
{
    inline static lua_State* init_value(){ return NULL; }
};

class lua_object_t;
template <>
struct init_value_traits_t<lua_object_t>
{
    inline static lua_State* init_value(){ return NULL; }
};

template <>
struct init_value_traits_t<pair<char*, size_t> >
{
    inline static pair<char*, size_t> init_value(){ return pair<char*, size_t>(NULL, 0); }
};

template <>
struct init_value_traits_t<pair<char*, int> >
{
    inline static pair<char*, int> init_value(){ return pair<char*, int>(NULL, 0); }
};

template <>
struct init_value_traits_t<pair<const char*, size_t> >
{
    inline static pair<const char*, size_t> init_value(){ return pair<const char*, size_t>(NULL, 0); }
};

template <>
struct init_value_traits_t<pair<const char*, int> >
{
    inline static pair<const char*, int> init_value(){ return pair<const char*, int>(NULL, 0); }
};


template<typename T>
class lua_traits_t;

#define LUA_TRAITS_NUM_GEN(X) template<> class lua_traits_t<X> \
    {\
    public:\
        static void push_stack(lua_State* ls_, X arg_)\
        {\
            lua_pushnumber(ls_, (lua_Number)arg_);\
        }\
        static int check_param(lua_State* ls_, int nres_, X& param_)\
        {\
            if (!lua_isnumber(ls_, nres_))\
            {\
                return -1;\
            }\
            param_ = (X)lua_tonumber(ls_, nres_);\
            return 0;\
        }\
        static int check_lua_param(lua_State* ls_, int nres_, X& param_)\
        {\
            param_ = (X)luaL_checknumber(ls_, nres_);\
            return 0;\
        }\
    }

template<>
class lua_traits_t<char>
{
public:
    static void push_stack(lua_State* ls_, char arg_)
    {
        lua_pushnumber(ls_, arg_);
    }

    static int check_param(lua_State* ls_, int nres_, char& param_)
    {
        if (!lua_isnumber(ls_, nres_))
        {
            return -1;
        }

        param_ = (char)lua_tonumber(ls_, nres_);
        return 0;
    }
    static int check_lua_param(lua_State* ls_, int nres_, char& param_)
    {
        param_ = (char)luaL_checknumber(ls_, nres_);
        return 0;
    }
};

template<>
class lua_traits_t<int>
{
public:
    static void push_stack(lua_State* ls_, int arg_)
    {
        lua_pushnumber(ls_, arg_);
    }

    static int check_param(lua_State* ls_, int nres_, int& param_)
    {
        if (!lua_isnumber(ls_, nres_))
        {
            return -1;
        }

        param_ = (int)lua_tonumber(ls_, nres_);
        return 0;
    }

    static int check_lua_param(lua_State* ls_, int nres_, int& param_)
    {
        param_ = (int)luaL_checknumber(ls_, nres_);
        return 0;
    }
};

template<>
class lua_traits_t<void*>
{
public:
    static void push_stack(lua_State* ls_, void* arg_)
    {
        lua_pushlightuserdata(ls_, arg_);
    }

    static int check_param(lua_State* ls_, int nres_, void* & param_)
    {
        if (!lua_isuserdata(ls_, nres_))
        {
            char buff[512];
            snprintf(buff, sizeof(buff), "userdata param expected, but type<%s> provided",
                                         lua_typename(ls_, lua_type(ls_, nres_)));
            cout << buff << "\n";
            return -1;
        }

        param_ = lua_touserdata(ls_, nres_);
        return 0;
    }

    static int check_lua_param(lua_State* ls_, int nres_, void*& param_)
    {
        if (!lua_isuserdata(ls_, nres_))
        {
            luaL_argerror (ls_, 1, "userdata param expected");
            return -1;
        }
        param_ = lua_touserdata(ls_, nres_);
        return 0;
    }
};

template<typename T>
class lua_traits_t<T*>
{
public:
    static void push_stack(lua_State* ls_, T* arg_)
    {
        void* ptr = lua_newuserdata(ls_, sizeof(class_userdata_t<T>));
        new (ptr) class_userdata_t<T>(arg_);

        luaL_getmetatable(ls_, lua_type_registry_t<T>::get_type_name());
        lua_setmetatable(ls_, -2);
    }

    static int check_param(lua_State* ls_, int nres_, T* & param_)
    {
        if (false == lua_type_registry_t<T>::is_registed())
        {
            luaL_argerror(ls_, nres_, "arg can't convert to class*, because the class has not registed to Lua");
        }

        //! void* arg_data = luaL_checkudata(ls_, nres_, lua_type_registry_t<T>::get_type_name());
        void *arg_data = lua_touserdata(ls_, nres_);

        if (NULL == arg_data)
        {
            char buff[512];
            snprintf(buff, sizeof(buff), "userdata<%s> param expected, but type<%s> provided",
                                         lua_type_registry_t<T>::get_type_name(),
                                         lua_typename(ls_, lua_type(ls_, nres_)));
            cout << buff << "\n";
            return -1;
        }

        if (0 == lua_getmetatable(ls_, nres_))
        {  //! does it have a metatable?
            return -1;
        }

        //! get correct metatable
        lua_getfield(ls_, LUA_REGISTRYINDEX, lua_type_registry_t<T>::get_type_name());
        if (0 == lua_rawequal(ls_, -1, -2))
        {//! does it have the correct mt?
            char buff[512];
            snprintf(buff, sizeof(buff), "userdata<%s> param expected, but type<%s> provided",
                                         lua_type_registry_t<T>::get_type_name(),
                                         lua_typename(ls_, lua_type(ls_, nres_)));
            cout << buff << "\n";
            lua_pop(ls_, 2);
            return -1;
        }

        //1 remove both metatables
        lua_pop(ls_, 2);

        T* ret_ptr = ((class_userdata_t<T>*)arg_data)->obj_ptr;
        if (NULL == ret_ptr)
        {
            return -1;
        }

        param_ = ret_ptr;
        return 0;
    }

    static int check_lua_param(lua_State* ls_, int nres_, T*& param_)
    {
        if (false == lua_type_registry_t<T>::is_registed())
        {
            luaL_argerror(ls_, nres_, "arg can't convert to class*, because the class has not registed to Lua");
        }

        void* arg_data = luaL_checkudata(ls_, nres_, lua_type_registry_t<T>::get_type_name());

        if (NULL == arg_data)
        {
            char buff[512];
            snprintf(buff, sizeof(buff), "`%s` expect arg 1, but arg == null",
                                         lua_type_registry_t<T>::get_type_name());
            luaL_argerror(ls_, nres_, buff);
        }

        T* ret_ptr = ((class_userdata_t<T>*)arg_data)->obj_ptr;
        if (NULL == ret_ptr)
        {
            char buff[512];
            snprintf(buff, sizeof(buff), "`%s` object ptr can't be null",
                                         lua_type_registry_t<T>::get_type_name());
            luaL_argerror(ls_, nres_, buff);
        }

        param_ = ret_ptr;
        return 0;
    }
};
LUA_TRAITS_NUM_GEN(int8_t);
LUA_TRAITS_NUM_GEN(uint8_t);
LUA_TRAITS_NUM_GEN(int16_t);
LUA_TRAITS_NUM_GEN(uint16_t);
LUA_TRAITS_NUM_GEN(uint32_t);
LUA_TRAITS_NUM_GEN(int64_t);
LUA_TRAITS_NUM_GEN(uint64_t);

LUA_TRAITS_NUM_GEN(long long);
LUA_TRAITS_NUM_GEN(long long unsigned int);

LUA_TRAITS_NUM_GEN(float);
LUA_TRAITS_NUM_GEN(double);

template<>
class lua_traits_t<bool>
{
public:
    static void push_stack(lua_State* ls_, bool arg_)
    {
        lua_pushboolean(ls_, arg_);
    }

    static int check_param(lua_State* ls_, int nres_, bool& param_)
    {
        if (!lua_isboolean(ls_, nres_))
        {
            return -1;
        }

        param_ = (bool)lua_toboolean(ls_, nres_);
        return 0;
    }
    static int check_lua_param(lua_State* ls_, int nres_, bool& param_)
    {
        param_ = (bool)luaL_checknumber(ls_, nres_);
        return 0;
    }
};

template<>
class lua_traits_t<string>
{
public:
    static void push_stack(lua_State* ls_, const string& arg_)
    {
        lua_pushlstring(ls_, arg_.c_str(), arg_.length());
    }

    static int check_param(lua_State* ls_, int nres_, string& param_)
    {
        if (!lua_isstring(ls_, nres_))
        {
            return -1;
        }

        //! what's amazing!  lua_tolstring also changes the actual value in the stack to a string
        //! This change confuses lua_next when lua_tolstring is applied to keys during a table traversal.
        lua_pushvalue(ls_, nres_);
        size_t len  = 0;
        const char* src = lua_tolstring(ls_, -1, &len);
        param_.assign(src, len);
        lua_pop(ls_, 1);

        return 0;
    }
    static int check_lua_param(lua_State* ls_, int nres_, string& param_)
    {
        size_t len = 0;
        const char* str = luaL_checklstring(ls_, nres_, &len);
        param_.assign(str, len);
        return 0;
    }
};

template<>
class lua_traits_t<const char*>
{
public:
    static void push_stack(lua_State* ls_, const char* arg_)
    {
        lua_pushstring(ls_, arg_);
    }
};

template<>
class lua_traits_t<lua_nil_t>
{
public:
    static void push_stack(lua_State* ls_, const lua_nil_t& arg_)
    {
        lua_pushnil (ls_);
    }

};

template<>
class lua_traits_t<pair<const char*, size_t> >
{
public:
    static void push_stack(lua_State* ls_, const pair<const char*, size_t>& arg_)
    {
        lua_pushlstring(ls_, arg_.first, arg_.second);
    }

    static int check_lua_param(lua_State* ls_, int nres_, pair<const char*, size_t>& param_)
    {
        size_t len = 0;
        param_.first  = luaL_checklstring(ls_, nres_, &len);
        param_.second = len;
        return 0;
    }
};

template<>
class lua_traits_t<pair<const char*, int> >
{
public:
    static void push_stack(lua_State* ls_, const pair<const char*, int>& arg_)
    {
        lua_pushlstring(ls_, arg_.first, arg_.second);
    }

    static int check_lua_param(lua_State* ls_, int nres_, pair<const char*, int>& param_)
    {
        size_t len = 0;
        param_.first  = luaL_checklstring(ls_, nres_, &len);
        param_.second = (int)len;
        return 0;
    }
};

class lua_table_t;
class auto_lua_table_t;
typedef shared_ptr_t<auto_lua_table_t> auto_lua_table_ptr_t;

template<>
class lua_traits_t<lua_table_t>
{
public:

    template<typename T>
    static void push_stack(lua_State* ls_, const T& arg_)
    {
        lua_pushvalue(ls_, arg_.table_index());
    }

    template<typename T>
    static int check_param(lua_State* ls_, int nres_, T& param_)
    {
        if (!lua_istable(ls_, nres_))
        {
            return -1;
        }
/*
        int t = lua_gettop(ls_);
        lua_pushnil(ls_);
        while (lua_next(ls_, t) != 0) {
            printf("%d %s - %s %s - %s\n",
              t,
              lua_typename(ls_, lua_type(ls_, -2)),
              lua_typename(ls_, lua_type(ls_, -1)),
              lua_tostring(ls_, -2),
              lua_tostring(ls_, -1));
            lua_pop(ls_, 1);
        }
*/
        param_.init(ls_, lua_gettop(ls_), true);//! auto relese
        return 0;
    }

    template<typename T>
    static int check_lua_param(lua_State* ls_, int nres_, T& param_)
    {
        luaL_checktype(ls_, nres_, LUA_TTABLE);
        param_.init(ls_, nres_, false);//! no auto relese
        return 0;
    }

};

template<>
class lua_traits_t<auto_lua_table_ptr_t>
{
public:
    template<typename T>
    static int check_param(lua_State* ls_, int nres_, T& param_)
    {
        if (!lua_istable(ls_, nres_))
        {
            return -1;
        }

        param_->init(ls_, lua_gettop(ls_), true);
        return 0;
    }
};

template<>
class lua_traits_t<lua_function_t>
{
public:
    static void push_stack(lua_State* ls_, lua_function_t arg_)
    {
        lua_pushcfunction(ls_, arg_);
    }

    static int check_param(lua_State* ls_, int nres_, lua_function_t& param_)
    {
        if (!lua_isfunction(ls_, nres_))
        {
            return -1;
        }

        param_ = lua_tocfunction(ls_, nres_);
        return 0;
    }
    static int check_lua_param(lua_State* ls_, int nres_, lua_function_t& param_)
    {
        if (!lua_iscfunction(ls_, nres_))
        {
            char buff[512];
            snprintf(buff, sizeof(buff), "cfunction param expected, but type<%s> provided",
                                         lua_typename(ls_, lua_type(ls_, nres_)));
            luaL_argerror (ls_, 1, buff);
            return -1;
        }

        param_ = lua_tocfunction(ls_, nres_);
        return 0;
    }
};

class lua_object_t;
template<>
class lua_traits_t<lua_object_t>
{
public:

    template<typename T>
    static void push_stack(lua_State* ls_, const T& arg_)
    {
        lua_pushvalue(ls_, arg_.stack_index());
    }

    template<typename T>
    static int check_param(lua_State* ls_, int nres_, T& param_)
    {
        param_.init(ls_, lua_gettop(ls_), true);//! auto relese
        return 0;
    }

    template<typename T>
    static int check_lua_param(lua_State* ls_, int nres_, T& param_)
    {
        param_.init(ls_, nres_, false);//! no auto relese
        return 0;
    }

};

}

}
#endif
