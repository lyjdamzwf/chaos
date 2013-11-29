#ifndef _CHAOS_MISC_DEF_H_
#define _CHAOS_MISC_DEF_H_



#include <algorithm>

#ifdef HAVE_CONFIG_H
#include <chaos/conf.h>
#endif

#include <chaos/deps/lua_tinker/lua_tinker.h>

#include <chaos/utility/utility_inc.h>
#include <chaos/async_method/async_method_inc.h>
#include <chaos/thread/thread_inc.h>
#include <chaos/log/log_inc.h>
#include <chaos/task_service/task_service_inc.h>
#include <chaos/statistic/statistic_inc.h>
#include <chaos/heart_beat/heart_beat_inc.h>
#include <chaos/network/network_inc.h>
#include <chaos/script/script_inc.h>

using namespace chaos::utility;
using namespace chaos::async_method;
using namespace chaos::thread;
using namespace chaos::log;
using namespace chaos::task_service;
using namespace chaos::statistic;
using namespace chaos::heart_beat;
using namespace chaos::network;
using namespace chaos::script;


//! yunjie: 日志模块定义
#ifndef LOG_MODULE
#define TEST_MODULE                 "TEST_MODULE"
#endif

#define LOCALHOST       "127.0.0.1"

//! yunjie: 所有service对象, 注: service类不要使用单例
//  因为static变量析构顺序的不确定性和依赖性, 会导致关
//  闭进程时crash

#define EXTERN_SERVICE_DECL                                     \
    extern task_service_t*             task_service_1104;       \
    extern work_service_t*             work_service_1104;       \
    extern work_service_group_t*       work_service_group_1104; \
    extern task_service_t*             log_service_1104;        \
    extern statistic_service_t*        stat_service_1104;       \

#define NEW_SERVICE()                                               \
    task_service_1104 = new task_service_t("global task service");  \
    work_service_1104 = new work_service_t("global work service");  \
    work_service_group_1104 = new work_service_group_t();           \
    log_service_1104 = new task_service_t("log service");           \
    stat_service_1104 = new statistic_service_t();                  \

#define DEL_SERVICE()                           \
    SAFE_DELETE(task_service_1104);             \
    SAFE_DELETE(work_service_1104);             \
    SAFE_DELETE(work_service_group_1104);       \
    SAFE_DELETE(log_service_1104);              \
    SAFE_DELETE(stat_service_1104);             \

#define TS()    (*task_service_1104)
#define WS()    (*work_service_1104)
#define LOGS()  (*log_service_1104)
#define WSG()   (*work_service_group_1104)
#define SS()    (*stat_service_1104)

EXTERN_SERVICE_DECL

//! yunjie: 日志模块封装
class log_tool_t
{
public:
    static void print_screen_callback(const std::string& msg_)
    {
        if (is_started)
        {
            LOGS().post(bindfunc(&singleton_t<log_t>::instance(), &log_t::handle_print_screen, msg_));
        }
    }

    static void print_file_callback(const std::string& msg_)
    {
        if (is_started)
        {
            LOGS().post(bindfunc(&singleton_t<log_t>::instance(), &log_t::handle_print_file, msg_));
        }
    }

    static void enable_log_module(const string& module_, int log_level_)
    {
        singleton_t<log_t>::instance().enable_log_module(module_.c_str(), true, log_level_);
    }

    static void enable_log_module(const string& module_)
    {
        singleton_t<log_t>::instance().enable_log_module(module_.c_str(), true);
    }

    static void enable_log_module(const string& key_, const string& val_)
    {
        if (val_.empty())
            enable_log_module(key_);
        else
            enable_log_module(key_, atoi(val_.c_str()));
    }

    static int start_log_service(const char* log_path_, int log_level_, int file_, int screen_)
    {
        singleton_t<log_t>::instance().set_path(log_path_);
        singleton_t<log_t>::instance().set_filename("log");
        singleton_t<log_t>::instance().set_maxline(100000);
        singleton_t<log_t>::instance().set_maxsize(5000000);

        if(file_)
            singleton_t<log_t>::instance().enable_print_file(true);

        if(screen_)
            singleton_t<log_t>::instance().enable_print_screen(true);

        singleton_t<log_t>::instance().set_print_screen_callback(print_screen_callback);
        singleton_t<log_t>::instance().set_print_file_callback(print_file_callback);

        singleton_t<log_t>::instance().enable_log_module(THREAD_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(TASK_SERVICE_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(TIMER_MANAGER_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(IO_MULTIPLEX_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(ACCEPTOR_SERVICE_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(WORK_SERVICE_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(TCP_SERVICE_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(CONNECTION_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(HEART_BEAT_MOUDLE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(STATISTIC_MOUDLE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(CONNECTION_MODULE, true, log_level_);
        singleton_t<log_t>::instance().enable_log_module(TEST_MODULE, true, log_level_);

        singleton_t<log_t>::instance().open();

        LOGS().start(1);
        is_started = true;

        return 0;
    }

    static int stop_log_service()
    {
        LOGS().stop();
        is_started = false;

        return 0;
    }

private:
    volatile static bool             is_started;
};

class application_tool_t
{
public:

    static int block_all_signal()
    {
        singleton_t<signal_handler_t>::instance().block_all_signal();

        return 0;
    }

    //! yunjie: 信号注册及监听内核信号队列
    static int wait_signal()
    {
        singleton_t<signal_handler_t>::instance().register_quit_signal(SIGINT);
        singleton_t<signal_handler_t>::instance().register_quit_signal(SIGQUIT);
        singleton_t<signal_handler_t>::instance().register_quit_signal(SIGTERM);
        singleton_t<signal_handler_t>::instance().register_quit_signal(SIGHUP);
        singleton_t<signal_handler_t>::instance().event_loop();     //! event loop to wait for signal

        return 0;
    }
};

#endif //! _CHAOS_MISC_DEF_H_
