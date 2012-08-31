#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <vector>

using namespace std;

template<typename type_t>
void loop_2_printf(vector<type_t>& vector_)
{
    for (typename vector<type_t>::iterator it = vector_.begin(); it != vector_.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

#endif // TEST_H_INCLUDED
