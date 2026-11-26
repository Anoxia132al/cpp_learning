#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>


void Fill_n_test (std::list<int>& li)
{
    std::fill_n(li.begin(), li.size(), 0);
    for (int val : li)
        std::cout << val << " ";
    std::cout << '\n';
}

bool pre_test (const std::string& str)
{
    return str.size() >= 5;
}

void test_p_345 (std::vector<std::string>& vec)
{
    auto beg = vec.begin();
    auto part_end = std::partition(vec.begin(), vec.end(), pre_test);
    for (; beg != part_end; ++beg)
        std::cout << *beg << " ";
    std::cout << '\n';
}

void test_p_345_2p (std::vector<std::string>& vec)
{
    auto part_end = std::partition(vec.begin(), vec.end(), 
        [] (const std::string& str) { return str.size() >= 5; });

    for (auto beg = vec.begin(); beg != part_end; ++beg)
        std::cout << *beg << " ";
    std::cout << '\n';
}

void test_p_354_1 (const std::vector<std::string>& vec2)
{
    auto count = std::count_if(vec2.begin(), vec2.end(),
        [] (const std::string& str) { return str.size() >= 5; });
    std::cout << count << '\n';
}

void test_p_354_2 ()
{
    int temp = 6;
    auto f = [&temp] () ->bool { if(temp > 0) --temp; return temp == 0; };
    for (int i = 0; i < 8; ++i)
        std::cout << "times :" << i + 1 << " "
        << "return :" << f() << " " 
        << "temp =" << temp << '\n';
}

int main ()
{
    std::list<int> li = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int val : li)
        std::cout << val << " ";
    std::cout << '\n';
    Fill_n_test (li);

    std::vector<std::string> vec = {"Linux", "App", "Add", "Hello", "Still_What"};
    test_p_345_2p (vec);

    std::vector<std::string> vec2 = {"Linux", "App", "Add", "Hello", "Still_What"};
    test_p_354_1 (vec2);

    test_p_354_2 ();
    return 0;
}