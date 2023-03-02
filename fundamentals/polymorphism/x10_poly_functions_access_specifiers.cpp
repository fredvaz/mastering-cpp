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
#include "libs8/shape.hpp"
#include "libs8/ellipse.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Polymorphic functions and access specifiers
            * When a method is declared as private in a base class and as public in the derived class
            * When you call the virtual function through a base class pointer, the access specifier in the
            * base class determines whether the function is accessible, regardless of the access specifier
            * in the derived class
            * So if declared private in the base class teh method will no be virtual override
            * 
            * As a rule of thumb, except for the base class, mark all my other derived overrides as private
            * unless the specific problem requires otherwise
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Accessing stuff through the base class pointer

    std::shared_ptr<Shape> shape0 = std::make_shared<Ellipse>(1, 5, "ellipse0");
    shape0->draw(); //* Polymorphism
    // shape0->func(); //! Error :  func is private in Shape

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Direct objects: static binding
    Ellipse ellipse1(1, 6, "ellipse1");
    ellipse1.func(); // Works
    // ellipse1.draw(); //! Error : draw() is private in Ellipse.- Static binding

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Raw derived object assigned to raw base object
    //! Slicing will occur, Shape::draw will be called
    Shape shape3 = Ellipse(2, 3, "ellipse3");
    shape3.draw(); //! Shape::draw() called
    // shape3.func(); //! Error: func is private in shape

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
