#include "bt_statement.h"

void for_statement()
{
    std::vector<std::string> vec;
    std::string str;

    while (std::cin >> str)
    {
        vec.push_back(str);
    }

    if (vec.empty())
    {
        std::cout << "no input" << std::endl;
        return;
    }

    int maxcnt = 1;
    int currcount = 1;
    std::string maxWd = " ";
    for (auto i = vec.cbegin() + 1; i != vec.cend(); ++i)
    {
        if (*i == *(i - 1))
            ++currcount;
        else
        {
            if (currcount > maxcnt)
            {
                maxcnt = currcount;
                maxWd = *(i - 1);
            }
            currcount = 1;
        }
    }
    if (currcount > maxcnt) //  以防最后一个单词是出现次数最多的单词, 需要在循环结束后再判断一次
    {
        maxcnt = currcount;
        maxWd = vec.back();
    }
    if (maxcnt == 1)
        std::cout << "no word appears more than once" << std::endl;
    else
        std::cout << "maxWd : " << maxWd << " appears " << maxcnt << " times" << std::endl;
}

void break_statement()
{
    std::string str;
    while (std::cin >> str)
    {
        for (std::string::size_type i = 1; i != str.size(); ++i)
        {
            if (str[i - 1] == str[i])
            {
                std::cout << "the first pair char is : " <<  str[i] << std::endl;
                break;
            }
            if (i == str.size() - 1)
            {
                std::cout << "no pair char" << std::endl;
                std::cout << str << std::endl;
            }
        }
    }
}
void break_statement_2 ()
{
    std::string str;
    while (std::cin >> str)
    {
        bool found = false;

        for (std::string::size_type i = 1; i < str.size(); ++i)
        {
            if (str[i - 1] == str[i])
            {
                std::cout << "the first pair char is : " << str[i] << std::endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << "no pair char\n";
            std::cout << str << std::endl;
        }
    }
}

void break_on_book ()
{
    std::string prevWord, currWord;
    if (std::cin >> prevWord)
    {
        while (std::cin >> currWord)
        {
            if (currWord == prevWord)
            {
                std::cout << "appears csl : ";
                std::cout << currWord << std::endl;
                break;
            }
            prevWord = currWord;
        }
    }
}