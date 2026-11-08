#include "lk_expression.h"

void run_lk_expression()
{
    //  const_cast 的使用示例
    char str[] = "hello";  
    const char* pc = str;  //  equal to: const char* pc = &str[0]
    char* p = const_cast<char*>(pc);

    for (auto i = 0; i != sizeof(str) / sizeof(*str); ++i)
        p[i] = toupper(p[i]);  //  通过 p 修改了 str 的内容, 这是合法的, 因为 str 是一个字符数组, 不是字符串字面值
    std::cout << str << " ";
    
    std::string s = "world";
    const std::string* ps = &s;  //  ps 指向一个 const std::string 对象
    std::string* p2 = const_cast<std::string*>(ps);

    for (auto &c : *p2)
        c = toupper(c);
    std::cout << s << std::endl;

    std::cout << "==============================" << std::endl;

    std::string s2[] = {"hello", "linux"};
    const std::string* ps2 = s2;
    std::string* p3 = const_cast<std::string*>(ps2);

    for (auto i = 0; i != sizeof(s2) / sizeof(*s2); ++i)
    {
        for (auto &c : *p3)
            c = toupper(c);
        for (auto c : *p3)
            std::cout << c;
        std::cout << " ";
        ++p3;
    }
/*
    const char* cp = "World";
    char* p2 = const_cast<char*>(cp);
    *p2 = 'w';  //  这是不合法的, 因为 cp 指向的是一个字符串字面值, 字符串字面值是常量, 不能被修改
    std::cout << cp << std::endl;
*/
}
