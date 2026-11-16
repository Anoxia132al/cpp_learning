#include "Sales_item.h"

void Sales_item::input (int ISBN, int cnt, double price)
{
    this->ISBN = ISBN;
    this->cnt = cnt;
    this->price = price;
}
double Sales_item::total_price () const
{
    return cnt * price;
}

void Sales_item_test ()
{
    Sales_item item;
    item.input(1, 2, 3);
    std::cout << item.total_price() << std::endl;
}

//  ==================================================

//  构造函数

Sales_data::Sales_data () = default;    //  请求编译器生成默认构造函数

//  冒号后面的部分叫 成员初始化列表 ，用于在构造对象时直接初始化成员
//  初始化列表的实际初始化顺序由成员在类中的声明顺序决定，不是冒号后书写的顺序

//  : bookNo(s) 表示用参数 s 初始化成员 bookNo
//  它不是函数体里的普通赋值：成员初始化发生在构造函数体执行之前
//  特别是 const 成员、引用成员必须通过初始化列表初始化
Sales_data::Sales_data (const std::string &s) : bookNo (s) {}   

Sales_data::Sales_data (const std::string &s, unsigned n, double p) :
        bookNo (s), units_sold (n), revenue (p*n) {}

Sales_data::Sales_data (std::istream &is) 
{
    read (is, *this);
}

void litt_ts ()
{
    Sales_data tp = Sales_data (std::cin);
    std::cout << tp.bookNo << " " << tp.units_sold << " " << tp.revenue << '\n';
}


std::string Sales_data::isbn () const { return this->bookNo; }

Sales_data& Sales_data::combine (const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price () const
{
    // if (units_sold)
    // {
    //     return revenue / units_sold;
    // }
    // else  return 0;
    return units_sold ? revenue / units_sold : 0;
}

//  类的非成员函数
Sales_data add (const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream& print (std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " || " << item.avg_price() << std::endl;
    return os;
}

std::istream& read (std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

void Sales_data_test ()
{
    Sales_data bk1, bk2, bk3;

    std::cout << "input bookNo, units_sold and price : " << std::endl;
    read (std::cin, bk1);
    read (std::cin, bk2);
    read (std::cin, bk3);

    std::cout << "output bookNo, units_sold, price and revenue : " << std::endl;
    print (std::cout, bk1);
    print (std::cout, bk2);
    print (std::cout, bk3);

    std::cout << "========================================" << std::endl;

    Sales_data fin_all = add (add (bk1, bk2),bk3);
    
    std::cout << "all sold : " << fin_all.units_sold << std::endl;
    std::cout << "all revenue : " << fin_all.revenue << std::endl;
    std::cout << "avg_price : " << fin_all.avg_price() << std::endl;
}

void Sales_data_test2 ()
{
    Sales_data total {}; // units_sold 和 revenue 会初始化为 0
    Sales_data item {};

    std::cout << "Input records: ISBN units_sold price\n";

    while (read(std::cin, item))
    {
        print(std::cout, item);

        total.units_sold += item.units_sold;
        total.revenue += item.revenue;
    }

    // EOF 是正常结束；其他输入错误则报告
    if (std::cin.bad() || (!std::cin.eof() && std::cin.fail()))
    {
        std::cerr << "Input error.\n";
        return;
    }

    std::cout << "Total units: " << total.units_sold << '\n'
              << "Total revenue: " << total.revenue << '\n'
              << "Weighted average price: " << total.avg_price() << '\n';
}