#include <chaos/mylua/mylua.h>

namespace chaos
{

namespace mylua
{

mylua_t::mylua_t():
    m_ls(NULL)
{
    m_ls = lua_open();
    luaL_openlibs(m_ls);
}

mylua_t::~mylua_t()
{
    if (m_ls)
    {
        lua_close(m_ls);
        m_ls = NULL;
    }
}

lua_State* mylua_t::get_lua_state() const
{
    return m_ls;
}

int  mylua_t::add_lib_path(const string& str_)
{
    string new_path = "package.path = package.path .. \"";
    if (str_.empty())
    {
        return -1;
    }

    if (str_[0] != ';')
    {
       new_path += ";";
    }

    new_path += str_;

    if (str_[str_.length() - 1] != '/')
    {
        new_path += "/";
    }

    new_path += "?.lua\" ";

    run_string(new_path);
    return 0;
}

int  mylua_t::load_file(const string& file_name_) throw (lua_exception_t)
{
    //! this func must be invoken once
    //! if has invoed, return -1.
    //! func will open lua lib: base, table, io, string, math

    if (luaL_dofile(m_ls, file_name_.c_str()))
	{
		string err = lua_helper::dump_error(m_ls, "mylua_t::load_file cannot load file<%s>", file_name_.c_str());
		lua_pop(m_ls, 1);
		throw lua_exception_t(err);
	}

    return 0;
}

void mylua_t::call(const char* func_name_) throw (lua_exception_t)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);
    lua_getglobal(m_ls, func_name_);

    if (lua_pcall(m_ls, 0, 0, 0) != 0)
    {
        string err = lua_helper::dump_error(m_ls, "mylua_t::call lua_pcall faled func_name<%s>", func_name_);
        lua_pop(m_ls, 1);
        throw lua_exception_t(err);
    }
}

void mylua_t::run_string(const string& str_) throw (lua_exception_t)
{
    run_string(str_.c_str(), str_.length());
}

void mylua_t::run_string(const char* str_, size_t len_) throw (lua_exception_t)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);

    if (luaL_dostring(m_ls, str_))
    {
        string err = lua_helper::dump_error(m_ls, "mylua_t::run_string lua_pcall faled str<%s>", str_);
        lua_pop(m_ls, 1);
        throw lua_exception_t(err);
    }
}

void mylua_t::stack_dump() const
{
    lua_helper::stack_dump(m_ls);
}

void  mylua_t::register_raw_function(const char* func_name_, lua_function_t func_)
{
    lua_checkstack(m_ls, STACK_CHECK_NUM);

    lua_pushcfunction(m_ls, func_);
    lua_setglobal(m_ls, func_name_);
}

}

}
