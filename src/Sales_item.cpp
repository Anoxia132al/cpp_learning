#include "Sales_item.h"

void Sales_item::input(int ISBN, int cnt, double price)
{
    this->ISBN = ISBN;
    this->cnt = cnt;
    this->price = price;
}
double Sales_item::total_price() const
{
    return cnt * price;
}
