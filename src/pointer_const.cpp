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