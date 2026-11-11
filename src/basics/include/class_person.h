#pragma once

#include <iostream>

class Person
{
public :
    std::string name, address;

    std::string back_print () const;
};

void run_per_test ();