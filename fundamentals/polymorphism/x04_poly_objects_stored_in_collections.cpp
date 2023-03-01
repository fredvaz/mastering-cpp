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
#include "libs2/shape.hpp"
#include "libs2/oval.hpp"
#include "libs2/circle.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Polymorphic objects stored in collections (array)
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

    //* If you store raw object data in an array set up to store base class objects
    //* the data is going to be sliced off!

    std::cout << "sizeof (circle1): " << sizeof(circle1) << std::endl;

    Shape shapes1[]{circle1, oval1, circle2, oval2, circle3, oval3};
    //! Copy! Not a Shape Pointer! To avoid the slicing we need to store the objects in Base pointer

    for (Shape &s : shapes1)
    {
        std::cout << "sizeof (object): " << sizeof(s) << std::endl; //! The size is lower than the original object
        s.draw();                                                   //! Shape::draw() called we a case of Slicing
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

// #define EXAMPLE_
#ifdef EXAMPLE_

    //! What if we store in references? Compiler error : references aren't left assignable
    const Shape &shapes2[]{circle1, oval1, circle2, oval2, circle3, oval3};

    //! References are "unique" for each assignment we do in our program (Refer to References Section)
    //! Otherhand, in Pointers we can change address memory that is is pointing to

#endif
    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Raw pointers: Correct way!

    Shape *shapes3[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};

    for (Shape *shape_ptr : shapes3)
    {
        std::cout << "Inside array, sizeof(*shape_ptr): " << sizeof(*shape_ptr) << std::endl;
        shape_ptr->draw();
        std::cout << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Smart pointers: Best Design!

    std::shared_ptr<Shape> shapes4[]{std::make_shared<Circle>(12.2, "Circle4"),
                                     std::make_shared<Oval>(10.0, 20.0, "Oval4")};
    for (auto &s : shapes4)
    {
        s->draw();
    }
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
