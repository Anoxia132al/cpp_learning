#pragma once

#include <iostream>

class Sales_item
{
public :
    int ISBN;
    int cnt;
    double price;

    void input (int, int, double);
    double total_price () const;
};

void Sales_item_test ();

//  ==============================================

class Sales_data
{
public :
    std::string bookNo;
    unsigned units_sold;  //  某本书的销量
    double revenue;  //  这本书的总收入

    std::string isbn () const;
    Sales_data& combine (const Sales_data&);
    double avg_price () const;
};

Sales_data add (const Sales_data&, const Sales_data&);
std::ostream& print (std::ostream&, const Sales_data&);
std::istream& read (std::istream&, Sales_data);

void Sales_data_test ();