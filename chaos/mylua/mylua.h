#ifndef _FM_LUA_H_
#define _FM_LUA_H_

#include <stdint.h>
#include <stdlib.h>

#include <string>
using namespace std;

#include <chaos/mylua/lua-5.1.4/src/lua.hpp>
#include <chaos/mylua/lua_type.h>
#include <chaos/mylua/lua_macro.h>
#include <chaos/mylua/lua_object.h>
#include <chaos/mylua/lua_table.h>
#include <chaos/mylua/detail/lua_traits.h>
#include <chaos/mylua/detail/function_dispather.h>
#include <chaos/mylua/detail/call_lua_detail.h>
#include <chaos/mylua/detail/class_register.h>

namespace chaos
{

namespace mylua
{

class mylua_t: private noncopyable_t
{
    enum stack_check_num_e
    {
        STACK_CHECK_NUM = 20
    };
public:
    mylua_t();
    ~mylua_t();
    void stack_dump() const;

    lua_State* get_lua_state() const;

    int  add_lib_path(const string& str_);
    int  load_file(const string& file_name_) throw (lua_exception_t);
    template<typename T>
    void open_lib(T arg_);
    void run_string(const string& str_) throw (lua_exception_t);
    void run_string(const char* str_, size_t len_) throw (lua_exception_t);

    template<typename T>
    int  get_global_field(const string& field_name_, T& ret_);
    template<typename T>
    int  get_global_field(const char* field_name_, T& ret_);

    template<typename T>
    int  set_global_field(const string& field_name_, const T& value_);
    template<typename T>
    int  set_global_field(const char* field_name_, const T& value_);

    void  register_raw_function(const char* func_name_, lua_function_t func_);
    template<typename FUNC>
    void  register_static_function(const char* mod_name_, const char* func_name_, FUNC func_);
    template<typename FUNC>
    void  register_global_function(const char* func_name_, FUNC func_);

    template<typename CLASS_TYPE, typename FUNC_TYPE>
    void  register_class_base(const string& class_name_);
    template<typename CLASS_TYPE, typename FUNC_TYPE>
    void  register_class_method(const string& class_name, const string& func_name, FUNC_TYPE func_);
    template<typename CLASS_TYPE, typename PROPERTY_TYPE>
    void  register_class_property(const string& property_name_, PROPERTY_TYPE p_);

    template<typename T>
    void  multi_register(T a);

    void call(const char* func_name_) throw (lua_exception_t);
    template<typename T>
    void call(T func_);

    template<typename RET>
    RET call(const char* func_name_) throw (lua_exception_t);

    template<typename RET, typename ARG1>
    RET call(const char* func_name_, const ARG1& arg1_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_,
             const ARG3& arg3_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_,
             const ARG7& arg7_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
             const ARG8& arg8_) throw (lua_exception_t);

    template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    RET call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
             const ARG8& arg8_, const ARG9& arg9_) throw (lua_exception_t);

    //! ---------------------------------------------------call method for void return value type
    template<typename ARG1>
    void call(const string& func_name_, const ARG1& arg1_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_,
             const ARG3& arg3_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_,
             const ARG7& arg7_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
             const ARG8& arg8_) throw (lua_exception_t);

    template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
             typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
    void call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
             const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
             const ARG8& arg8_, const ARG9& arg9_) throw (lua_exception_t);

private:
    lua_State*  m_ls;
};

template<typename T>
void mylua_t::open_lib(T arg_)
{
    arg_(m_ls);
}

template<typename T>
int  mylua_t::get_global_field(const string& field_name_, T& ret_)
{
    return get_global_field<T>(field_name_.c_str(), ret_);
}

template<typename T>
int  mylua_t::get_global_field(const char* field_name_, T& ret_)
{
     int ret = 0;

     lua_getglobal(m_ls, field_name_);
     ret = lua_traits_t<T>::check_param(m_ls, -1, ret_);

     lua_pop(m_ls, 1);
     return ret;
}

template<typename T>
int  mylua_t::set_global_field(const string& field_name_, const T& value_)
{
    return set_global_field<T>(field_name_.c_str(), value_);
}

template<typename T>
int  mylua_t::set_global_field(const char* field_name_, const T& value_)
{
    lua_traits_t<T>::push_stack(m_ls, value_);
    lua_setglobal(m_ls, field_name_);
    return 0;
}

template<typename T>
void mylua_t::call(T func_)
{
    func_.call(m_ls);
}

template<typename RET>
RET mylua_t::call(const char* func_name_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_);
}

template<typename RET, typename ARG1>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_);
}

template<typename RET, typename ARG1, typename ARG2>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_,
                                  const ARG3& arg3_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                  const ARG4& arg4_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_, arg4_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                  const ARG4& arg4_, const ARG5& arg5_) throw (lua_exception_t)
{
     return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_, arg4_, arg5_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                  const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                  const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_,
                                  const ARG7& arg7_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                  const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
                                  const ARG8& arg8_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_);
}

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4,
         typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
RET mylua_t::call(const char* func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                  const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
                                  const ARG8& arg8_, const ARG9& arg9_) throw (lua_exception_t)
{
    return call_lua_detail_t<RET>::call(m_ls, func_name_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_, arg8_, arg9_);
}

template<typename FUNC>
void  mylua_t::register_static_function(const char* mod_name_, const char* func_name_, FUNC func_)
{
    char buff[1024];
    const char* tmp_func_name = "__tmp_cpp_register_func__";

    //! if mod == nil then mod = {} end
    //! tmp_func = func
    //! mod.func_name = tmp_func
    //! tmp_func = nil

    snprintf(buff, sizeof(buff),
             "if %s == nil then %s = {} end %s.%s = %s %s = nil",
             mod_name_, mod_name_, mod_name_, func_name_, tmp_func_name, tmp_func_name);

    lua_checkstack(m_ls, STACK_CHECK_NUM);
    function_dispather_t::dispather_static_function(m_ls, func_);
    lua_setglobal(m_ls, tmp_func_name);

    run_string(buff);
}

template<typename FUNC>
void  mylua_t::register_global_function(const char* func_name_, FUNC func_)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);
    function_dispather_t::dispather_global_function(m_ls, func_);
    lua_setglobal(m_ls, func_name_);
}

template<typename CLASS_TYPE, typename FUNC_TYPE>
void  mylua_t::register_class_base(const string& class_name_)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);
    class_register_t::register_class_base<CLASS_TYPE, FUNC_TYPE>(m_ls, class_name_);
}

template<typename CLASS_TYPE, typename FUNC_TYPE>
void  mylua_t::register_class_method(const string& class_name_, const string& func_name_, FUNC_TYPE func_)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);
    class_register_t::register_class_method<CLASS_TYPE>(m_ls, class_name_, func_name_, func_);
}

template<typename CLASS_TYPE, typename PROPERTY_TYPE>
void  mylua_t::register_class_property(const string& property_name_, PROPERTY_TYPE p_)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);
    class_register_t::register_class_property<CLASS_TYPE>(m_ls, property_name_, p_);
}

template<typename T>
void  mylua_t::multi_register(T a)
{
    a(*this);
}

//! -----------------------------------------------------------------------------for process return type void
template<typename ARG1>
void mylua_t::call(const string& func_name_, const ARG1& arg1_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_);
}

template<typename ARG1, typename ARG2>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_);
}

template<typename ARG1, typename ARG2, typename ARG3>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_,
                                   const ARG3& arg3_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_);
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                   const ARG4& arg4_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_, arg4_);
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                   const ARG4& arg4_, const ARG5& arg5_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_, arg4_, arg5_);
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                   const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_, arg4_, arg5_, arg6_);
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                   const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_,
                                   const ARG7& arg7_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_, arg4_, arg5_, arg6_,
                                  arg7_);
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7, typename ARG8>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                   const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
                                   const ARG8& arg8_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_, arg4_, arg5_, arg6_,
                                  arg7_, arg8_);
}

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4,
                typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
void mylua_t::call(const string& func_name_, const ARG1& arg1_, const ARG2& arg2_, const ARG3& arg3_,
                                   const ARG4& arg4_, const ARG5& arg5_, const ARG6& arg6_, const ARG7& arg7_,
                                   const ARG8& arg8_, const ARG9& arg9_) throw (lua_exception_t)
{
    call_lua_detail_t<void>::call(m_ls, func_name_.c_str(), arg1_, arg2_, arg3_, arg4_, arg5_, arg6_,
                                  arg7_, arg8_, arg9_);
}

}

}

#endif
