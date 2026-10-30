#include "pointer_const.h"

void pointer ()
{

    int a{10};
    int b{23};
    const int &r1 = a;
    cout << r1 << endl;

    const int *p = &a;  //  指向常量的指针
    cout << *p << endl;

    int *const ptr = &a;  //  常量指针
    cout << *ptr << endl;

    //!  *p = 32;  //  指向常量的指针不能改变指向的地址的值
    p = &b;
    cout << *p << endl;

    //!  ptr = &b;  //  常量指针不能改变指向的地址
    *ptr = 32;
    cout << *ptr << endl;
}

void cst ()
{
    //  左值：有名字，有地址的变量, 可以出现在赋值语句的左边
    //  右值：没有名字，没有地址的临时变量, 不能出现在赋值语句的左边
    int a = 10;  //  a 是左值, 10 是右值
    cout << a << endl;

    const int &b = 42;  //  常量引用, 绑定到字面值(右值) 42
    //  int &c = 10;  //  非常量引用, 绑定到字面值 10, 这是不合法的, 编译器会报错
    cout << b << endl;
}