#pragma once

#include <iostream>
#include <string>

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
private :
    std::string bookNo;
    unsigned units_sold = 0;  //  某本书的销量
    double revenue = 0.0;  //  这本书的总收入

    friend Sales_data add (const Sales_data&, const Sales_data&);
    friend std::ostream& print (std::ostream&, const Sales_data&);
    friend std::istream& read (std::istream&, Sales_data&);

    friend void Sales_data_test ();
    friend void Sales_data_test2 ();
    friend void litt_ts ();

public :
    //  构造函数
    Sales_data ();    
    Sales_data (const std::string&);   
    Sales_data (const std::string&, unsigned, double);
    Sales_data (std::istream&);

    std::string isbn () const;
    Sales_data& combine (const Sales_data&);
    double avg_price () const;
};

Sales_data add (const Sales_data&, const Sales_data&);
std::ostream& print (std::ostream&, const Sales_data&);
std::istream& read (std::istream&, Sales_data&);

void Sales_data_test ();
void Sales_data_test2 ();
void litt_ts ();