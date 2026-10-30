#pragma once

#include <iostream>

class Sales_item
{
public:
    int ISBN;
    int cnt;
    double price;

    void input (int ISBN, int cnt, double price);
    double total_price () const;
};

void Sales_item_test();