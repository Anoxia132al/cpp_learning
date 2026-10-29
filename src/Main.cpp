#include <iostream>
#include <string>  
//  #include <map>  // 映射容器, 用于存储键值对, 键是唯一的, 值可以重复
//  #include <fstream>  // 文件流, 用于读取和写入文件
using std::cout;
using std::endl;

#include "Sales_item.h"
#include "else_random.h"
#include "pointer_const.h"

int main () 
{
    //  左值：有名字，有地址的变量, 可以出现在赋值语句的左边
    //  右值：没有名字，没有地址的临时变量, 不能出现在赋值语句的左边
    int a = 10;  //  a 是左值, 10 是右值
    cout << a << endl;

    const int &b = 42;  //  常量引用, 绑定到字面值(右值) 42
    //  int &c = 10;  //  非常量引用, 绑定到字面值 10, 这是不合法的, 编译器会报错
    cout << b << endl;

    std::string s1, s2;
    std::cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;
    
    while (std::cin >> s1 && s1 != "quit") cout << s1 << endl;
    cout << "end input above" << endl;
    std::cin.ignore();  //  忽略输入 "缓冲区" 中的换行符, 否则 getline 会读取到换行符而返回结果
    while (getline(std::cin, s1)) cout << s1 << endl;  

    //  pointer();

    Sales_item item;
    item.input(1, 2, 3);
    cout << item.total_price();

    //  CntNum();
    //  std::cout << Sum2() << std::endl;
    return 0;
}