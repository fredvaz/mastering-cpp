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
#include "libs/shape2.hpp"
#include "libs/oval2.hpp"
#include "libs/circle2.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Size of polymorphic objects and slicing
            !Note: the objects with Dynamic binding (polymorphism) will have a higher size
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Comparing object sizes: the objects with Polymorphism will have a higher size
    std::cout << "sizeof(Shape): " << sizeof(Shape) << std::endl;   // dynamic : 40
    std::cout << "sizeof(Oval): " << sizeof(Oval) << std::endl;     // dynamic : 56
    std::cout << "sizeof(Circle): " << sizeof(Circle) << std::endl; // dynamic : 56

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Slicing: when we do a assignement (=) it will only store object of which type is the variable
    Circle circle1(3.3, "Circle1");

    Shape shape = circle1;
    
    shape.draw(); //! Shape::draw() called, not a circle method called as maybe we expect

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
