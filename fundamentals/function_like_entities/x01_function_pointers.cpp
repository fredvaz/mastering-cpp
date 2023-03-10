/*

The C++20 Masterclass Section 46: Function Like Entities

General Notes:


   [REF]:

*/
#include <iostream>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Function Pointers
*/

double add(double a, double b)
{
    return a + b;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // double (*f_ptr) (double, double)  = &add;
    // double(*f_ptr) (double,double) = add;

    // double(*f_ptr) (double,double) {&add};
    // double(*f_ptr) (double,double){add};

    // auto f_ptr = &add;
    // auto f_ptr = add;

    // auto *f_ptr = &add;
    // auto *f_ptr = add;

    // Things gone wroong
    double (*f_ptr)(double, double) = nullptr;

    std::cout << "add(10,30) : " << f_ptr(10, 30) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
