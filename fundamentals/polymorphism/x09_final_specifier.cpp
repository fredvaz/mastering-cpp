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
#include "libs7/animal.hpp"
#include "libs7/feline.hpp"
#include "libs7/dog.hpp"
#include "libs7/cat.hpp"
#include "libs7/bird.hpp"
#include "libs7/pigeon.hpp"
#include "libs7/crow.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Final Specifier
            * Restrict how uou override methods in derived classes
            * Restrict how you can derive from a base class
            * So, if we don't want our derived classes to override our virtual method
            * Or, if we don't want to other users inherit our class
            * Generates a Compiler error
*/

//* Intersting fact #1
// #define EXAMPLE_
#ifdef EXAMPLE_
class Plane final
#else
class Plane
#endif
{
    Plane() = default;
};

//! This will trigger a compiler error
class FigherJet : public Plane
{
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Final and Overridew are not keywords
            * They are indentifiers introduced in C++11, they can be used as variables names etc
            * Altough is not recommend to use them as names, just not increase the code reading complixity
            https://en.cppreference.com/w/cpp/language/final
            https://en.cppreference.com/w/cpp/language/override
*/

double final{45};
std::string override{"Hello World!"};

class override
{
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//