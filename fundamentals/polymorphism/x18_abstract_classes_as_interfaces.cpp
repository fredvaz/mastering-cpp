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
#include "libs15/stream_insertable.hpp"
#include "libs15/animal.hpp"
#include "libs15/feline.hpp"
#include "libs15/dog.hpp"
#include "libs15/cat.hpp"
#include "libs15/bird.hpp"
#include "libs15/pigeon.hpp"
#include "libs15/crow.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Abstract Classes as Interfaces
            * - An abstract class with only pure virtual functions and no member variable can be
            * used to model waht is called an interface in Object Oriented Programming
            * - An interface is a specification of something that will be fully implemented in a
            * derived class, but the specification itself resides in the abstract class
*/

class Point : public StreamInsertable
{
public:
    Point() = default;
    Point(double x, double y)
        : m_x(x), m_y(y)
    {
    }

    //* Method implementation of the specification in the abstract class
    virtual void stream_insert(std::ostream &out) const override
    {
        out << "Point [x: " << m_x << ", y: " << m_y << "]";
        //* Also, we can use here the operator<< overloadind since is inherited from the base class
    }

private:
    double m_x;
    double m_y;
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(10, 20);
    std::cout << "p1: " << p1 << std::endl;
    // operator<<(std::cout,p1);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* The Abstrat Class as Interface StreamInsertable allows us to print each animal

    std::unique_ptr<Animal> animal0 = std::make_unique<Dog>("stripes", "dog1"); //* Polymorphism
    std::cout << *animal0 << std::endl;

    std::unique_ptr<Animal> animal1 = std::make_unique<Bird>("white", "bird1"); //* Polymorphism
    std::cout << *animal1 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Can even put animals in an array and print them polymorphically.

    std::shared_ptr<Animal> animals[]{
        std::make_shared<Dog>("stripes", "dog2"),
        std::make_shared<Cat>("black stripes", "cat2"),
        std::make_shared<Crow>("black wings", "crow2"),
        std::make_shared<Pigeon>("white wings", "pigeon2")};

    std::cout << "Printing out animals array: " << std::endl;

    for (const auto &a : animals)
    {
        std::cout << *a << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
