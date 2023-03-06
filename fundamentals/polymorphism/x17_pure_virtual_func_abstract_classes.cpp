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
#include "libs14/shape.hpp"
#include "libs14/circle.hpp"
#include "libs14/rectangle.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Pure virtual functions and abstract classes
            * Tells to the compiler that the methods are not meant to be implemented in the base class
            * - The class is going to become an abstract class if at least one pure virtual function
            * - You cannot create objects of any abstract class, you will get a compiler error
            * - Derived classes from an abstract class must explicity override all the pure virtual
            * functions from the abstract parent class, if they don't themselves become abstract
            * - Pure virutal functions don't have an implementation in the abstract class. They are meant
            * to be implemented by the by the inherting downstream classes
            * - You can't call the pure virtual functions from the constructor of the abstract class
            * - The constructor of the abstract class is used by the deriving class to build up the base
            * part of the object
            https://en.cppreference.com/w/cpp/language/abstract_class
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // Shape * shape_ptr = new Shape; //! error: we are not allowed to create Shape objects
    //! because Shape is a abstract Class, due to the pure virtual function declaration

    const Shape *shape_rect = new Rectangle(10, 10, "rect1");
    double surface = shape_rect->surface();

    std::cout << "dynamic type of shape_rect: " << typeid(*shape_rect).name() << std::endl;
    std::cout << "The surface of shape rect is: " << surface << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    const Shape *shape_circle = new Circle(10, "circle1");
    surface = shape_circle->surface();

    std::cout << "dynamic type of shape_circle: " << typeid(*shape_circle).name() << std::endl;
    std::cout << "The surface of the circle is: " << surface << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
