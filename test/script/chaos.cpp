#include <chaos/utility/script.h>

using namespace chaos::utility;

class a_t
{
  public:
    void func1(int64_t v_)
    {
        printf("%lu\n", v_);
    }
};

class script2_t : public chaos::utility::script
{
  public:
    void register_lua_interface()
    {
#define CLASS_DEF(klass,member)                                     \
        lua_tinker::class_def<klass>(_L, #member, &klass::member)
#define CLASS_ADD(klass)                            \
        lua_tinker::class_add<klass>(_L, #klass);
#define CLASS_STATIC_DEF(klass,member)                                  \
        lua_tinker::class_def<klass>(_L, #klass "_" #member, &klass::member)

        CLASS_ADD(a_t);
        CLASS_DEF(a_t, func1);
    }
};

int main(int argc_, char *argv_[])
{
    script2_t s;
    s.add_package_path("./lua_package");
    s.register_lua_interface();
    s.do_file("./entry.lua");

    a_t a;
    s.call<void>("callback", &a);

    sleep(10);
    s.reload();

    return 0;
}
