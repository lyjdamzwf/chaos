#ifndef _CHAOS_TEST_MYLUA_H_
#define _CHAOS_TEST_MYLUA_H_

#include <iostream>
#include <string>
using namespace std;

#define PARAM (uint8_t a1, uint16_t a2, uint32_t a3, uint64_t a4, string a5, lua_table_t ret_table, int a7, lua_object_t obj_, void* a9)

int global_foo PARAM
{
    cout <<"global_foo: <" << int(a1) <<">"<<"<" << int(a2) <<">"<<"<" << (a3) <<">"<<"<" << (a4) <<">"<<"<" << (a5) <<">"
         <<"<" << (a7) <<">"<<"<" << *((int*)a9) <<">";
    cout <<"\n";
    return 0;
}

struct foo_t
{
    static int static_foo PARAM
    {
        cout <<"global_foo: <" << int(a1) <<">"<<"<" << int(a2) <<">"<<"<" << (a3) <<">"<<"<" << (a4) <<">"<<"<" << (a5) <<">"
        <<"<" << (a7) <<">"<<"<" << *((int*)a9) <<">";
        cout <<"\n";
        return 0;
    }
};

class test_reg_parent_t
{
public:
    void foo()
    {
        cout <<"test_reg_parent_t::foo:\n";
    }
};

class obj_t
{
public:
    obj_t(int a_):m_a(a_){}
    ~obj_t(){cout <<"obj_t::~obj_t...\n";}

    void foo(){cout <<"obj_t::foo..."<<m_a<<"xxx\n";}
    string name(){return "obj_t_obj";}

private:
    int m_a;
};

class test_reg_t: public test_reg_parent_t
{
public:
    int field;
    lua_object_t lua_obj;
    string ok;

    test_reg_t PARAM
    {
        cout <<"<" << int(a1) <<">"<<"<" << int(a2) <<">"<<"<" << (a3) <<">"<<"<" << (a4) <<">"<<"<" << (a5) <<">"
        <<"<" << (a7) <<">"<<"<" << *((int*)a9) <<">";
        cout <<"\n";

        //! lua table must invoke begin method before get operation.
        //! last, must release lua_table, or lua stack will memory leak
        for (ret_table.begin(); false == ret_table.end(); ret_table.next())
        {
            string v;
            pair<string, string> ret;
            int ret_flag = ret_table.get_pair(ret.first, ret.second);
            cout <<"table pair:<" << ret_flag << "><" << ret.first << "><" << ret.second << ">\n";
            break;
        }
        ret_table.release();
        field = 11223344;
    }
    ~test_reg_t()
    {
        lua_obj.release();
        cout <<"test_reg_t::~test_reg_t() done ok\n";
    }
    void* dump PARAM
    {
        cout << "test_reg_t:dump ok:"<<a3<<"\n";
        return a9;
    }

    obj_t* creat_ptr(){
        obj_t* p = new obj_t(123);
        return  p;
    }
    void   test_ptr(obj_t* p) {cout << "test_reg_t:test_ptr ok:"<<p->name()<<"\n";}
};


LUA_REGISTER_BEGIN(cpp_register)
REGISTER_GLOBAL_FUNCTION("global_foo", global_foo)
REGISTER_TABLE_FUNCTION("foo_t", "static_foo", foo_t::static_foo)
REGISTER_CLASS_BASE("test_reg_t", test_reg_t, void PARAM )
REGISTER_CLASS_METHOD("test_reg_t", "dump", test_reg_t, &test_reg_t::dump)
REGISTER_CLASS_METHOD("test_reg_t", "foo", test_reg_t, &test_reg_parent_t::foo)
REGISTER_CLASS_METHOD("test_reg_t", "creat_ptr", test_reg_t, &test_reg_t::creat_ptr)
REGISTER_CLASS_METHOD("test_reg_t", "test_ptr", test_reg_t, &test_reg_t::test_ptr)

REGISTER_CLASS_PROPERTY(test_reg_t, "field", &test_reg_t::field)
REGISTER_CLASS_PROPERTY(test_reg_t, "lua_obj", &test_reg_t::lua_obj)
REGISTER_CLASS_PROPERTY(test_reg_t, "ok", &test_reg_t::ok)

REGISTER_CLASS_BASE("obj_t", obj_t, void (int) )
REGISTER_CLASS_METHOD("obj_t", "foo", obj_t, &obj_t::foo)
LUA_REGISTER_END

struct A
{
    int a;
};

struct A g_a;
void fooxx(int A::* p)
{
    typedef int A::* xx;
    (g_a.*p) = 123;

}

int do_test_lua(mylua_t* lua_handler_ptr)
{
    try
    {
        fooxx(&A::a);
        cout <<"g_a:"<< g_a.a <<"\n";

        //! load lua file example.
        const char* filename = "test.lua";
        string path = "/home/zark/github/chaos/test/mylua/";
        lua_handler_ptr->add_lib_path(path);
        lua_handler_ptr->load_file(path + filename);

        int a = 669933;

        lua_handler_ptr->multi_register(cpp_register);

        cout << " stack dump begin\n";
        lua_handler_ptr->stack_dump();
        cout << " stack dump end\n";

        int ret = lua_handler_ptr->call<int>("test_class", (void*)&a);
        cout << " lua return:" << ret <<"\n";

        cout << " stack dump begin\n";
        lua_handler_ptr->stack_dump();
        cout << " stack dump end\n";
        return 0;
    }
    catch(const exception& e)
    {
        cout << "exception:" << e.what() << "\n";
        return -1;
    }

	cout <<"\n";
	return 0;
}
//! lua extention example

void thread_loop(int loops_ = 1)
{
    mylua_t* ptr = NULL;
    ptr = new mylua_t();

    for (int i = 0; i < loops_; ++i)
    {
        do_test_lua(ptr);
    }

    delete ptr;
}

#endif //! _CHAOS_TEST_MYLUA_H_
