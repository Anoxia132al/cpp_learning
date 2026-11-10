#include "pt_function.h"

void slp_in_function ()
{
    int val;

    while (std::cin >> val)
    {
        int ed = 1;
        while (val != 1)
        {
            ed *= val--;
        }
        std::cout << ed << std::endl;
    }
}

int fix_stg (int val)
{
    if (val <= 1)   return 1;
    return val * fix_stg(val - 1);
}

void run_stg_one ()
{
    int val;
    while (std::cin >> val)
    {
        std::cout << fix_stg (val) << std::endl;
    }
}

string::size_type find_char (const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())    ret = i;
            ++occurs;
        }
    }
    return ret;
}

size_t find_char2 (const string &s, char c, size_t &occurs)
{
    size_t ret = 0;
    occurs = 0;
    for (size_t i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == 0)   ret = i;
            ++occurs;
        }
    }
    return ret;
}

void run_find_char2 ()
{
    string str = "hello";
    size_t cnt = 0;
    char c;
    while (std::cin >> c)
    {
        std::cout << "the fist pos : " << find_char2 (str, c, cnt) << std::endl;
        std::cout << "aps times : " << cnt << std::endl;
    }
}

void ts_initializer_list (std::initializer_list<string> ls)
{
    for (auto i = ls.begin(); i != ls.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int static_arr[10];
int (*back_arrypointer (int i))[10]
{
    for (int j = 0; j != 10; ++j)
    {
        static_arr[j] = i + j;
    }
    return &static_arr;
}

void run_back_arryppointer ()
{
    int tp;
    while (std::cin >> tp)
    {
        auto p = back_arrypointer (tp);
        for (int i = 0; i != 10; ++i)
        {
            std::cout << (*p)[i] << " ";
        }
        std::cout << std::endl;
    }
}
