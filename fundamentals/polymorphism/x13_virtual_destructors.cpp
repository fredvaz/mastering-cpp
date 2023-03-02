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
#include "libs11/animal.hpp"
#include "libs11/feline.hpp"
#include "libs11/dog.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Virtual Destructors
            * We declare the destructors virtual when allocatig memory dynamically on the heap
            * If not, only the destructor for the Base pointer type will be called
            * because the compiler is going to use static binding to decide whic destructor to call
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* allocatig memory dynamically on the heap
    Animal *p_animal = new Dog;

    //! With non-virtual destructors: Animal destructor called
    //* with virtual destructor:
    //* Dog destructor called
    //* Feline destructor called
    // *Animal destructor called

    delete p_animal;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
