#include "string_cin.h"

void string_cin()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;

    while (std::cin >> s1 && s1 != "quit")
        cout << s1 << endl;
        cout << "end input above" << endl;

    //  std::cin.ignore();  //  忽略输入 "缓冲区" 中的换行符, 否则 getline 会读取到换行符而返回结果
    //  默认只忽略一个字符
    //  std::cin.ignore(100, '\n');  //  忽略输入 "缓冲区" 中的前 100 个字符, 直到遇到换行符为止
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //  忽略输入 "缓冲区" 中的所有字符, 直到遇到换行符为止
    while (getline(std::cin, s1))  if (!s1.empty())  //  s1.empty() 判断字符串是否为空, 为空返回 true, 否则返回 false
        { 
            cout << s1 << endl;
            cout << "s1->size = " << s1.size() << endl;
            break;
        }
}