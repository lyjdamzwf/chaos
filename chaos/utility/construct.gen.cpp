#include <stdio.h>

#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define ENTER "\r\n"
#define MAX_CTOR_ARG_NUM    9

#define TITLE \
"/*"ENTER \
"* Copyright 2012, Yunjie Lu.  All rights reserved."ENTER  \
"* https://github.com/lyjdamzwf/chaos"ENTER  \
"*"ENTER  \
"* Use of this source code is governed by a BSD-style"ENTER  \
"* license that can be found in the License file."ENTER  \
"*/"ENTER ENTER \
"/**"ENTER  \
"*  @file           processor_helper.cpp"ENTER  \
"*  @author         yunjie.lu"ENTER  \
"*  @email          lyjdamzwf@gmail.com"ENTER  \
"*  @weibo          http://weibo.com/crazyprogramerlyj"ENTER  \
"*  @date"ENTER  \
"*  @brief          该文件由chaos_new.gen.cpp生成, 请勿直接include"ENTER  \
"*  @last changed"ENTER  \
"*"ENTER  \
"*/"ENTER ENTER

enum embellish_e
{
    E_NONCONST = 0,
    E_CONST,
    E_COUNT
};

struct info_t
{
    info_t()
        :
            index(0),
            embellish(0)
    {
    }

    bool inc()
    {
        if (++embellish >= (int)E_COUNT)
        {
            embellish = (int)E_NONCONST;
            return false;
        }

        return true;
    }

    int             index;
    int             embellish;
};

vector< vector<info_t> > total_v;
vector<info_t> cur_v;

#define PC \
for (vector<info_t>::iterator it = cur_v.begin(); \
     it != cur_v.end(); \
     ++it \
    ) \
{ \
    printf(" %d ", it->embellish); \
} \
printf("\n");

int tmp = 0;


void foo(int index_, bool& change_)
{
    do
    {
l1:
        if (!cur_v.size())
        {
            return;
        }

        if (index_ == cur_v.size() - 1)
        {
            total_v.push_back(cur_v);
            change_ = (cur_v[index_].inc());

            if (0 == index_ && change_)
            {
                continue;
            }

            return;
        }

        foo(index_ + 1, change_);

        if (change_)
        {
            if (0 == index_)
            {
                goto l1;
            }
            continue;
        }
        else
        {
            change_ = cur_v[index_].inc();
            
            if (!change_)
            {
                return;
            }
        }
    }
    while (
            0 != index_ 
            || (0 == index_ && 0 != cur_v[0].embellish)
          );
}

int main(int argc_, char* argv_[])
{
    ofstream ofs;
    ofs.open("construct.h");

    string strbeg;
    strbeg.reserve(65535);

    strbeg += TITLE;

    //! strbeg += "namespace chaos"ENTER"{"ENTER ENTER"namespace utility"ENTER"{"ENTER ENTER;

    for (int i = 0; i <= MAX_CTOR_ARG_NUM; ++i)
    {
        cur_v.clear();

        for (int j = 0; j < i; ++j)
        {
            cur_v.push_back(info_t());
        }

        bool change = true;
        foo(0, change);
    }

    for (vector< vector<info_t> >::iterator it = total_v.begin();
         it != total_v.end();
         ++it
        )
    {
        int arg_num = it->size();
        vector<info_t>& cur_args = *it;

        strbeg += "template<typename T";
        for (int i = 0; i < arg_num; ++i)
        {
            char buf[20] = {0};
            snprintf(buf, sizeof(buf), "%d", i);
            strbeg += ", typename A";
            strbeg += buf;
        }
        strbeg += ">"ENTER;

        strbeg += "inline T* construct(";
        for (int i = 0; i < arg_num; ++i)
        {
            char buf[20] = {0};
            snprintf(buf, sizeof(buf), "%d", i);

            if (E_CONST == cur_args[i].embellish)
            {
                strbeg += "const ";
            }
            strbeg += "A";
            strbeg += buf;
            strbeg += "&";
            strbeg += " a";
            strbeg += buf;
            strbeg += ",";
        }
        if (strbeg.length() > 1)
        {
            strbeg[strbeg.length() - 1] = ')';
            strbeg += ENTER;
        }

        strbeg += "{"ENTER;
        strbeg += "    T* ptr = (T*)chaos_malloc(sizeof(T));"ENTER;
        strbeg += "    if (NULL != ptr)"ENTER;
        strbeg += "    {"ENTER;
        strbeg += "        try"ENTER;
        strbeg += "        {"ENTER;
        strbeg += "            new (ptr) T(";
        for (int i = 0; i < arg_num; ++i)
        {
            char buf[20] = {0};
            snprintf(buf, sizeof(buf), "%d", i);

            strbeg += "a";
            strbeg += buf;
            strbeg += ",";
        }
        if (strbeg.length() > 1)
        {
            strbeg[strbeg.length() - 1] = ')';
        }
        strbeg += ";"ENTER;
        strbeg += "        }"ENTER;
        strbeg += "        catch (...)"ENTER;
        strbeg += "        {"ENTER;
        strbeg += "            if (NULL != ptr) { chaos_free(ptr); ptr = NULL; }"ENTER;
        strbeg += "        }"ENTER;
        strbeg += "    }"ENTER;

        strbeg += "    return ptr;"ENTER;
        strbeg += "}"ENTER;
    }

    //! strbeg += ENTER"}"ENTER ENTER"}";

    ofs << strbeg;
    ofs.flush();

    return 0;
}

