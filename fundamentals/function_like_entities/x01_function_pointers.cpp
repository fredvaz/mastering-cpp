/*

The C++20 Masterclass Section 46: Function Like Entities

General Notes:
        * Things that can work as functions in C++
        * Taking input
        * Doing something in the function body
        * Returning values
        Callback functions are heavily used in event based programming like Graphcal User Interfaces
        but that's out of scope for this course


   [REF]:

*/
#include <iostream>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Function Pointers
            * A function is just a block of code that lives somewhere in the memory map of our C++ program.
            * We can grab the address of the function and store it in a function pointer.


*/

double add(double a, double b)
{
    return a + b;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Different ways of setting a function Pointer

    double (*f_ptr)(double, double) = &add;
    // double (*f_ptr)(double, double) = add;

    // double(*f_ptr) (double,double) {&add};
    // double(*f_ptr) (double,double){add};

    // auto f_ptr = &add;
    // auto f_ptr = add;

    // auto *f_ptr = &add;
    // auto *f_ptr = add;

    //! This will generate a Segmentation fault
    // double (*f_ptr)(double, double) = nullptr;

    std::cout << "add(10,30): " << f_ptr(10, 30) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
