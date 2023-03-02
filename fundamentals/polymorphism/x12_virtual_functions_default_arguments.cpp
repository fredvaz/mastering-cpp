/*

The C++20 Masterclass Section 41: Polymorphism

General Notes:
    One of the key features of class inheritance is that a pointer to a derived class is type-compatible
    with a pointer to its base class. Polymorphism is the art of taking advantage of this simple but
    powerful and versatile feature.

    *Polymorphism: a base pointer or reference managing derived class objects

    *Why we need polymorphism? To scale: for example, if we have 100 shapes in our program to draw
    *we will need to implement those 100 methods.

   [REF]:
    https://en.cppreference.com/book/intro/polymorphism
    https://cplusplus.com/doc/tutorial/polymorphism/

*/
#include <iostream>
#include <memory>
#include "libs10/base.hpp"
#include "libs10/derived.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Virtual functions with default arguments
            * The defaults argument in the base pointer class will override the ones the derived class
            *
            * The default arguments are static binding to its ouwn Class method
            *
            * Default arguments are handled at compile tome
            * Virtual functions are called at run time with polymorphism
            * if you use default arguments with virtual functions, you might get weird (erroneous)
            * results with polymorphism
            *
            * Not recommend to use default arguments when using polymorphism in the methods
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Base pointers: uses polymorphism

    Base *base_ptr1 = new Derived;
    double result = base_ptr1->add();
    std::cout << "Result (base ptr): " << result << std::endl; // 12

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Base references: uses Polymorphism

    Derived derived1;
    Base &base_ref1 = derived1;
    result = base_ref1.add();
    std::cout << "Result (base ref): " << result << std::endl; // 12

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Raw objects: base class called directly

    Base base3;
    result = base3.add();
    std::cout << "raw result: " << result << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Direct object: uses static binding

    Derived derived2;
    result = derived2.add();
    std::cout << "Result (Direct object): " << result << std::endl; // 22

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Raw objects - slicing: uses static binding

    Base base1 = derived2; //! Slicing
    result = base1.add();
    std::cout << "Result (Raw objects assignment) : " << result << std::endl; // 11

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
