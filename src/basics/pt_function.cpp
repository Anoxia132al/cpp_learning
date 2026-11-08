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

string::size_type find_char (const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())  ret = i;
            ++occurs;
        }
    }
    return ret;
}

void run_find_char ()
{
    string str = "hello";
    string::size_type cnt = 0;
    char c;
    while (std::cin >> c)
    {
        std::cout << "the fist pos : " << find_char (str, c, cnt) << std::endl;
        std::cout << "aps times : " << cnt << std::endl;
    }
}