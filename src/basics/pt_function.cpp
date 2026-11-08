#include "pt_function.h"

void slp_in_function ()
{
    int val;

    while (std::cin >> val)
    {
        int ed = 1;
        while (val != 1)
        {
            ed *= val--;
        }
        std::cout << ed << std::endl;
    }
}
