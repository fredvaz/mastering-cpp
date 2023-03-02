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
#include "libs6/shape.hpp"
#include "libs6/ellipse.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Inheritance and polymorphism with static members
            !note: the static members will be inherited by the Derived Classes, but the association
            !will be kept to the base class type
            !to deassociate to each type, we must create the static member variable for each derived class
            !rember: Static meber are detached from each created object and are attached to the Class Type
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Shape

    Shape shape1("shape1");
    std::cout << "shape count: " << Shape::m_count << std::endl; // 1

    Shape shape2("shape2");
    std::cout << "shape count: " << Shape::m_count << std::endl; // 2

    Shape shape3;
    std::cout << "shape count: " << Shape::m_count << std::endl; // 3

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Ellipse

    Ellipse ellipse1(10, 12, "ellipse1");
    std::cout << "shape count: " << Shape::m_count << std::endl; // 4
    //! If not declared a Static member variable m_count in the Ellipse class m_cout output will be 4
    std::cout << "ellipse count: " << Ellipse::m_count << std::endl; //! 4, and 1 if Ellipse class contains
                                                                     //! it is own static member variable

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Shape polymorphism

    Shape *shapes[]{&shape1, &ellipse1};

    for (auto &s : shapes)
    {
        std::cout << "count: " << s->get_count() << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
