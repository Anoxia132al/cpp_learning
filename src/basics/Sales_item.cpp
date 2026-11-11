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

//  ====================================================

std::string Sales_data::isbn () const { return this->bookNo; }

Sales_data& Sales_data::combine (const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price () const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else  return 0;
}

Sales_data add (const Sales_data&, const Sales_data&)
{

}

std::ostream& print (std::ostream&, const Sales_data&)
{

}

std::istream& read (std::istream&, Sales_data)
{

}

void Sales_data_test ()
{
    Sales_data bk1 = { "b1", 2, 10.0 };
    Sales_data bk2 = { "b2", 3, 30.0 };
    Sales_data bk3 = { "b3", 4, 50.0 };

    std::cout << "all sold : " << (bk1.combine (bk2.combine(bk3))).units_sold << std::endl;
    std::cout << "all revenue : " << bk1.revenue << std::endl;

    std::cout << "avg_price : " << bk1.avg_price() << std::endl;
}
