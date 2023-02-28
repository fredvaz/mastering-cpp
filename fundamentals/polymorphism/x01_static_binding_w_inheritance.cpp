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
#include "libs/shape.hpp"
#include "libs/oval.hpp"
#include "libs/circle.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Static binding (Default case) with inheritance
            !The compiler just looks at the pointer type to decide which method version to call
            !For example, it see a base pointer Shape* and calls Shape::draw()
*/

void draw_circle(const Circle &circle)
{
    circle.draw();
}

void draw_oval(const Oval &oval)
{
    oval.draw();
}
//! More functions as you deal with more shape types. 30 ? 70? 100? It's messy.

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Shape shape1("Shape1");
    Oval oval1(2.0, 3.5, "Oval1");
    Circle circle1(3.3, "Circle1");

    //* Call method by default for each Object
    shape1.draw();
    oval1.draw();
    circle1.draw();

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Base pointers
    Shape *shape_ptr = &shape1;
    shape_ptr->draw(); //* Calls the Shape method draw()

    shape_ptr = &oval1; //* Pointing to oval1 object

    shape_ptr->draw(); //! Calls the the Shape method draw() again, we would desire to call the oval1 method draw()

    shape_ptr = &circle1;
    shape_ptr->draw(); //! same beahviour for the circle1 object

    //! So, the problem here, is that Oval and Circle metohd draw() will be never called in this way

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Base references: Same beahviour as Base Pointers
    Shape &shape_ref = shape1;

    shape_ref.draw();

    shape_ref = oval1;
    shape_ref.draw();

    shape_ref = circle1;
    shape_ref.draw();

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* So, why we need polymorphism?

    draw_circle(circle1);
    draw_oval(oval1);
    //! More functions as you deal with more shape types. 30 ? 70? 100? It's messy.

    //* Another case: If you need to store these Shapes in collections

    Circle circle_collection[]{circle1, Circle(10.0, "Circle2"), Circle(20.0, "Circle3")};
    Oval oval_collection[]{oval1, Oval(22.3, 51.1, "Oval2")};
    //! More arrays as you have more shape types, 100? Messy right

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Quiz 73 - Shows better that the method called is from the first base Class
            * we can see that prints onle the members m1, but that differs to each Object type 
*/

class One
{

public:
    One(int one) : m_1(one)
    {
    }
    void print() const
    {
        std::cout << "data [one: " << m_1
                  << "]\n";
    }

protected:
    int m_1{};
};

//

class Two : public One
{

public:
    Two(int one, int two) : One(one), m_2(two)
    {
    }

    void print() const
    {
        std::cout << "data [one: " << m_1
                  << " two: " << m_2
                  << "]\n";
    }

protected:
    int m_2{};
};

//

class Three : public Two
{

public:
    Three(int one, int two, int three) : Two(one, two), m_3(three)
    {
    }

    void print() const
    {
        std::cout << "data [one: " << m_1
                  << " two: " << m_2
                  << " three: " << m_3 << "]\n";
    }

protected:
    int m_3{};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    One one(1);
    Two two(10, 20);
    Three three(100, 200, 300);

    one.print();

    two.print();

    three.print();

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    // One *base1 = &one;
    One &base1 = one;
    base1.print();

    // One *base2 = &two;
    One &base2 = two;
    base2.print();

    // One *base3 = &three;
    One &base3 = three;
    base3.print();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//