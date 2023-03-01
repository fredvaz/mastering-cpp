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
#include "libs3/shape.hpp"
#include "libs3/oval.hpp"
#include "libs3/circle.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Override
            * keyword overide allows to explicit orveride the derived Class method
            * protect us from problems if we make typos in setting up our polymorphic methods
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle2(11.2, "circle2");
    Oval oval2(31.3, 15.2, "Oval2");
    Circle circle3(12.2, "circle3");
    Oval oval3(53.3, 9.2, "Oval3");

    //* Raw pointers

    Shape *shapes3[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};

    for (Shape *shape_ptr : shapes3)
    {
        shape_ptr->draw(); //! For ovavl object Shape::draw() is called due to the upper case Typo draW() method
        //* Using the keyword override protects our program from this mistakes
        //* we are saying to the Compiler that is to overide the method in Shape class with the one
        //* from the derived Class, and it will generate a Compiller error if we make a typo in method declaration
        std::cout << std::endl; 
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
