#include "string_vector.h"

void string_cin ()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;

    while (std::cin >> s1 && s1 != "quit")  { cout << s1 << endl; }
        cout << "end input above" << endl;

    //  std::cin.ignore();  //  忽略输入 "缓冲区" 中的换行符, 否则 getline 会读取到换行符而返回结果
    //  默认只忽略一个字符
    //  std::cin.ignore(100, '\n');  //  忽略输入 "缓冲区" 中的前 100 个字符, 直到遇到换行符为止
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //  忽略输入 "缓冲区" 中的所有字符, 直到遇到换行符为止
    while (getline(std::cin, s1))  if (!s1.empty())  //  s1.empty() 判断字符串是否为空, 为空返回 true, 否则返回 false
        { 
            cout << s1 << endl;
            cout << "s1->size = " << s1.size();
            break;
        }
}

void process_string ()
{
    std::string str = "Hello, three, 2, one!";
    for (auto c : str)  { cout << c; }  cout << endl;
    for (auto &c : str)  c = toupper(c);  //  将字符串中的每个字符转换为大写字母
    cout << str << endl;

    std::string str2 = "0123456789ABCDEF", result;
    int n;
    while (std::cin >> n && n != -1)  if ((std::string::size_type)n < str2.size())  { result += str2[n]; }
    cout << result;
}

void pos_vector ()
{
    vector<std::string> str_vec {"Hello", "World", "C++", "Vector"};

    for (const auto &v : str_vec) { std::cout << v << " "; }  
    std::cout << std::endl;
    
    std::string str;
    vector<std::string> str_vec2;

    while (std::cin >> str)  { str_vec2.push_back(str); }
    for (const auto &v : str_vec2) { std::cout << v << " "; }
} 

void ts_iterator ()
{
    vector<std::string> str_vec {"Hello", "World", "C++", "Vector"};
    auto it = str_vec.cbegin();  //  cbegin() 返回一个指向容器开头的常量迭代器, 不能修改容器中的元素

    while (it != str_vec.cend())  { cout << *it++ << " "; }  //  cend() 返回一个指向容器末尾的常量迭代器, 不能修改容器中的元素
    cout << endl;
    for (auto it = str_vec.cbegin(); it != str_vec.cend(); ++it)  { cout << *it << " "; }
    cout << endl;

    vector<unsigned> scores (11, 0);
    unsigned grade;
    auto beg = scores.begin();
    while (std::cin >> grade) { if (grade <= 100)  ++*(beg + grade / 10); }
    for (auto it = scores.cbegin(); it != scores.cend(); ++it)  { cout << *it << " "; }
}