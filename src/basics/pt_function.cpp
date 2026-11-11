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

//  处理多维数组
int (*get_row(int matrix[][1920], int row_index))[1920]
{
    return &matrix[row_index];
}

int tt_func (int a, int b)
{
    return a + b;
}

int tt_func2 (int a, int b)
{
    return a * b;
}

void run_tt_func ()
{
    std::vector<int (*)(int a, int b)> vec;
    vec.push_back (tt_func);
    vec.push_back (tt_func2);

    int result1 = vec[0] (1, 2);
    int result2 = vec[1] (2, 3);

    std::cout << result1 << " and " << result2 << std::endl;
}

