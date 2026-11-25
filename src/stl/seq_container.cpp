#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <forward_list>

void test1_deque()
{
    std::deque<std::string> deq;
    std::string str;

    while (std::cin >> str)
        deq.push_back(str);

    for (const auto& word : deq)
        std::cout << word << ' ';
    std::cout << '\n';
}

void test2_list()
{
    std::list<std::string> li;
    std::string str;

    while (std::cin >> str)
        li.push_back(str);

    for (const auto& word : li)
        std::cout << word << ' ';
    std::cout << '\n';
}

void list_to_deque()
{
    const std::list<int> li{1, 2, 3, 4, 5, 6,7};
    std::deque<int> odd;
    std::deque<int> even;

    for (int value : li)
    {
        if (value % 2 == 0)
            even.push_back(value);
        else
            odd.push_back(value);
    }

    std::cout << "odd: ";
    for (int value : odd)
        std::cout << value << ' ';
    std::cout << '\n';

    std::cout << "even: ";
    for (int value : even)
        std::cout << value << ' ';
    std::cout << '\n';
}

void forward_list_test (
    std::forward_list<std::string>& fli,
    const std::string& s1,
    const std::string& s2)
{
    auto prev = fli.before_begin();
    auto curr = fli.begin();

    while (curr != fli.end())
    {
        if (*curr == s1)
        {
            fli.insert_after(curr, s2);
            break;
        }

        ++prev;
        ++curr;
    }

    if (curr == fli.end()) // 没找到 s1，prev 此时指向最后一个元素
        fli.insert_after(prev, s2);

    for (const auto& c : fli)
        std::cout << c << ' ';
    std::cout << '\n';
}

void list_test (std::list<int>& li)
{
    auto it = li.begin();

    while (it != li.end())
    {
        if (*it % 2 != 0)
        {
            li.insert(it, *it); // 在当前奇数前插入副本
            ++it;               // 跳过当前原元素，处理下一个原元素
        }
        else
        {
            it = li.erase(it);  // 返回下一个有效位置
        }
    }

    for (int value : li)
        std::cout << value << ' ';
    std::cout << '\n';
}

int main ()
{
    // test1_deque ();
    // test2_list ();
    // list_to_deque ();
    std::forward_list<std::string> fli = {"Hello", "Linux,", "What", "To", "Do"};
    forward_list_test (fli, "Linux,", "Yes,");

    std::list<int> li = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list_test (li);
    return 0;
}