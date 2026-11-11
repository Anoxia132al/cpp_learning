#include "class_person.h"

std::string Person::back_print () const
{
    return name + " , " + address;
}

void run_per_test ()
{
    Person a1 = { "li", "beijing"};
    std::cout << a1.back_print () << std::endl;
}