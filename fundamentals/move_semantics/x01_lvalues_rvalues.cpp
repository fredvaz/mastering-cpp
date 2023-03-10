/*

The C++20 Masterclass Section 45: Move Semantics (C++11)

General Notes:
    A set of features that were introduced in C++11 tom it easy to use temporary variables in C++
    and avoid unnecessary copies

    So, basically the Pointer to the final data will Pointer to the Pointer of temporary data instead
    of creating a copyig the temporary data to a new memory location for the final data

   [REF]:

*/
#include <iostream>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Lvalues and Rvalues
            * - Lavlues are things you can grab and address for and use at a later time
            * - Rvalues are transient or temporary in nature, they only exist for a short time and are quickly
            * destroyed by the system when no longer needed.
            * Rvalues are meant to live for a short time in memory. By the time you try to use their addresses
            * chances are the actual rvalue has been clean up from memory and you will be using pointers to nowhere
            * A perfect recipe for all sorts of crashes and undedined behavior.
*/

double add(double a, double b)
{
    return a + b;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    int x{5};  //* x, y and z are all lvalues, they have a memory address we
    int y{10}; //* can retrieve and use later on
    int z{20}; //* as long as the variables are in scope.

    int *ptr = &x;

    z = (x + y); //* The result of (x+y) is stored in memory for a short ime (transiently)
                 //* before it's assigned (copied) to z. After the assignment, the memory is discarded
                 //* (reclaimed by the system). (x+y) is (or evaluates to) an rvalue.
    std::cout << "z : " << z << std::endl;
    // std::cout << "&(x+y) : " << (&(x+y)) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    double result = add(10.1, 20.2); //* The result of add(10.1,20.2), is stored in some memory
                                     //* location for a sh ort time, before it's assigned to result, and after it's copied
                                     //* into result, the memory is reclaimed by the system.
                                     //* add(10.1,20.2) is (evaluates to) an rvalue

    // std::cout << "address of add(10.1,20.2) : " << &(add(10.1,20.2)) << std::endl; // Error
    std::cout << "result is: " << result << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Grab the addresses for later use

    // int * ptr1 = &(x + y); //! Compiler error. The error clearly says what's wrong here
    // int * ptr2 = &add(10.1,20.2); //! Compiler error. Can only take address of an lvalue,
    //  add(10.1 , 20.2) evaluates to an rvalue.
    // int* ptr3 = &45; //! Compiler error.
    int *ptr4 = &x; // OK. x is an lvalue, so we can grab its address

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
