#ifndef _CALL_LUA_DETAIL_H_
#define _CALL_LUA_DETAIL_H_

#include <chaos/mylua/lua_type.h>
#include <chaos/mylua/lua_table.h>
#include <chaos/mylua/lua_object.h>
#include <chaos/mylua/detail/lua_traits.h>

namespace chaos
{

namespace mylua
{

template<typename T>
struct call_lua_detail_t;

template<>
struct call_lua_detail_t<void>
{
    static void call(lua_State* ls_, const char* func_name_) throw (lua_exception_t)
    {
        lua_getglobal(ls_, func_name_);

        if (lua_pcall(ls_, 0, 0, 0) != 0)
        {
            string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
            lua_pop(ls_, 1);
            throw lua_exception_t(err);
        }
    }
    template<typename ARG1>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                     ARG3 arg3_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                     ARG4 arg4_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                     ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                     ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                     ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                     ARG7 arg7_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                     ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                     ARG8 arg8_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    static void call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                     ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                     ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t);
};

template<typename RET>
struct call_lua_detail_t
{
    static RET call(lua_State* ls_, const char* func_name_) throw (lua_exception_t);
    template<typename ARG1>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                    ARG3 arg3_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                    ARG4 arg4_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                    ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                    ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                    ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                    ARG7 arg7_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                    ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                    ARG8 arg8_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    static RET call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                    ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                    ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t);
};

//!--------------------------------------------------------------------------- impl for lua_table_t
template<>
struct call_lua_detail_t<lua_table_t>
{
    static lua_table_t call(lua_State* ls_, const char* func_name_) throw (lua_exception_t)
    {
        lua_table_t ret;

        //! lua_checkstack(ls_, STACK_CHECK_NUM);
        lua_getglobal(ls_, func_name_);

        if (lua_pcall(ls_, 0, 1, 0) != 0)
        {
            string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
            lua_pop(ls_, 1);
            throw lua_exception_t(err);
        }

        if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
        {
            lua_pop(ls_, 1);
            char buff[512];
            snprintf(buff, sizeof(buff), "call_lua_detail_t::call [table] check_param failed  func_name[%s]", func_name_);
            throw lua_exception_t(buff);
        }

        return ret;
    }

    template<typename ARG1>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                            ARG3 arg3_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                            ARG7 arg7_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                            ARG8 arg8_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    static lua_table_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                            ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t);
};


//!--------------------------------------------------------------------------- impl for auto_lua_table_ptr_t
template<>
struct call_lua_detail_t<auto_lua_table_ptr_t>
{
    static auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_) throw (lua_exception_t)
    {
        auto_lua_table_ptr_t ret(new auto_lua_table_t);

        //! lua_checkstack(ls_, STACK_CHECK_NUM);
        lua_getglobal(ls_, func_name_);

        if (lua_pcall(ls_, 0, 1, 0) != 0)
        {
            string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
            lua_pop(ls_, 1);
            throw lua_exception_t(err);
        }

        if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
        {
            lua_pop(ls_, 1);
            char buff[512];
            snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t] check_param failed  func_name[%s]", func_name_);
            throw lua_exception_t(buff);
        }

        return ret;
    }
    template<typename ARG1>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                              ARG3 arg3_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                              ARG4 arg4_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                              ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                              ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                              ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                              ARG7 arg7_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                              ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                              ARG8 arg8_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    auto_lua_table_ptr_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                              ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                              ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t);
};

template<typename ARG1>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);

    if (lua_pcall(ls_, 1, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_)
                                   throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);

    if (lua_pcall(ls_, 2, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                   ARG3 arg3_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);

    if (lua_pcall(ls_, 3, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                   ARG4 arg4_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);

    if (lua_pcall(ls_, 4, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                   ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);

    if (lua_pcall(ls_, 5, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                   ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);

    if (lua_pcall(ls_, 6, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                   ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                   ARG7 arg7_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);

    if (lua_pcall(ls_, 7, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                   ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                                   ARG8 arg8_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);

    if (lua_pcall(ls_, 8, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
void call_lua_detail_t<void>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                   ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                                   ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t)
{
    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);
    lua_traits_t<ARG9>::push_stack(ls_, arg9_);

    if (lua_pcall(ls_, 9, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }
}

//! impl for common RET
template<typename RET>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    if (lua_pcall(ls_, 0, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg0] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);

    if (lua_pcall(ls_, 1, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg1] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_)
                                 throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);

    if (lua_pcall(ls_, 2, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg2] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                 ARG3 arg3_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);

    if (lua_pcall(ls_, 3, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg3] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                 ARG4 arg4_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);

    if (lua_pcall(ls_, 4, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg4] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                 ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);

    if (lua_pcall(ls_, 5, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg5] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                 ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);

    if (lua_pcall(ls_, 6, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg6] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                 ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                 ARG7 arg7_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);

    if (lua_pcall(ls_, 7, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg7] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7, typename ARG8>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                 ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                                 ARG8 arg8_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);

    if (lua_pcall(ls_, 8, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg8] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

template<typename RET>
template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
RET call_lua_detail_t<RET>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                                 ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                                 ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t)
{
    RET ret = init_value_traits_t<RET>::init_value();

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);
    lua_traits_t<ARG9>::push_stack(ls_, arg9_);

    if (lua_pcall(ls_, 9, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<RET>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [arg9] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    lua_pop(ls_, 1);

    return ret;
}

//!-------------------------------------------------impl code for lua_table_t
template<typename ARG1>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);

    if (lua_pcall(ls_, 1, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg1] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_)
                                                 throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);

    if (lua_pcall(ls_, 2, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg2] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);

    if (lua_pcall(ls_, 3, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg3] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);

    if (lua_pcall(ls_, 4, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg4] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);

    if (lua_pcall(ls_, 5, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg5] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_)
                                                 throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);

    if (lua_pcall(ls_, 6, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg6] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);

    if (lua_pcall(ls_, 7, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg7] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_, ARG8 arg8_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);

    if (lua_pcall(ls_, 8, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg8] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
lua_table_t call_lua_detail_t<lua_table_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_, ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t)
{
    lua_table_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);
    lua_traits_t<ARG9>::push_stack(ls_, arg9_);

    if (lua_pcall(ls_, 9, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_table_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_table_t:arg9] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}


//!-------------------------------------------------impl code for auto_lua_table_ptr_t
template<typename ARG1>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);

    if (lua_pcall(ls_, 1, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg1] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_)
                                                 throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);

    if (lua_pcall(ls_, 2, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg2] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);

    if (lua_pcall(ls_, 3, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg3] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);

    if (lua_pcall(ls_, 4, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg4] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);

    if (lua_pcall(ls_, 5, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg5] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_)
                                                 throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);

    if (lua_pcall(ls_, 6, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg6] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);

    if (lua_pcall(ls_, 7, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg7] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_, ARG8 arg8_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret(new auto_lua_table_t());

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);

    if (lua_pcall(ls_, 8, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg8] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
auto_lua_table_ptr_t call_lua_detail_t<auto_lua_table_ptr_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_, ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t)
{
    auto_lua_table_ptr_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);
    lua_traits_t<ARG9>::push_stack(ls_, arg9_);

    if (lua_pcall(ls_, 9, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<auto_lua_table_ptr_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [auto_lua_table_ptr_t:arg9] check_param failed  func_name[%s]",
                                     func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}



//!--------------------------------------------------------------------------- impl for lua_object_t
template<>
struct call_lua_detail_t<lua_object_t>
{
    static lua_object_t call(lua_State* ls_, const char* func_name_) throw (lua_exception_t)
    {
        lua_object_t ret;

        //! lua_checkstack(ls_, STACK_CHECK_NUM);
        lua_getglobal(ls_, func_name_);

        if (lua_pcall(ls_, 0, 1, 0) != 0)
        {
            string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
            lua_pop(ls_, 1);
            throw lua_exception_t(err);
        }

        if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
        {
            lua_pop(ls_, 1);
            char buff[512];
            snprintf(buff, sizeof(buff), "call_lua_detail_t::call [table] check_param failed  func_name[%s]", func_name_);
            throw lua_exception_t(buff);
        }

        return ret;
    }

    template<typename ARG1>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                            ARG3 arg3_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                            ARG7 arg7_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                            ARG8 arg8_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    static lua_object_t call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_, ARG3 arg3_,
                            ARG4 arg4_, ARG5 arg5_, ARG6 arg6_, ARG7 arg7_,
                            ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t);
};


//!-------------------------------------------------impl code for lua_object_t
template<typename ARG1>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);

    if (lua_pcall(ls_, 1, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg1] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_)
                                                 throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);

    if (lua_pcall(ls_, 2, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg2] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);

    if (lua_pcall(ls_, 3, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg3] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);

    if (lua_pcall(ls_, 4, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg4] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);

    if (lua_pcall(ls_, 5, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg5] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_)
                                                 throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);

    if (lua_pcall(ls_, 6, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg6] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);

    if (lua_pcall(ls_, 7, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg7] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_, ARG8 arg8_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);

    if (lua_pcall(ls_, 8, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg8] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
lua_object_t call_lua_detail_t<lua_object_t>::call(lua_State* ls_, const char* func_name_, ARG1 arg1_, ARG2 arg2_,
                                                 ARG3 arg3_, ARG4 arg4_, ARG5 arg5_, ARG6 arg6_,
                                                 ARG7 arg7_, ARG8 arg8_, ARG9 arg9_) throw (lua_exception_t)
{
    lua_object_t ret;

    //! lua_checkstack(ls_, STACK_CHECK_NUM);
    lua_getglobal(ls_, func_name_);

    lua_traits_t<ARG1>::push_stack(ls_, arg1_);
    lua_traits_t<ARG2>::push_stack(ls_, arg2_);
    lua_traits_t<ARG3>::push_stack(ls_, arg3_);
    lua_traits_t<ARG4>::push_stack(ls_, arg4_);
    lua_traits_t<ARG5>::push_stack(ls_, arg5_);
    lua_traits_t<ARG6>::push_stack(ls_, arg6_);
    lua_traits_t<ARG7>::push_stack(ls_, arg7_);
    lua_traits_t<ARG8>::push_stack(ls_, arg8_);
    lua_traits_t<ARG9>::push_stack(ls_, arg9_);

    if (lua_pcall(ls_, 9, 1, 0) != 0)
    {
        string err = lua_helper::dump_error(ls_, "call_lua_detail_t::call lua_pcall failed func_name[%s]", func_name_);
        lua_pop(ls_, 1);
        throw lua_exception_t(err);
    }

    if (lua_traits_t<lua_object_t>::check_param(ls_, -1, ret))
    {
        lua_pop(ls_, 1);
        char buff[512];
        snprintf(buff, sizeof(buff), "call_lua_detail_t::call [lua_object_t:arg9] check_param failed  func_name[%s]", func_name_);
        throw lua_exception_t(buff);
    }

    return ret;
}

}

}
#endif
