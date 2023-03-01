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
#include "libs4/shape.hpp"
#include "libs4/oval.hpp"
#include "libs4/circle.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: x06 Overloading, overriding and function hiding
            * Case where we have a overload of the method draw() in the Base Class
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle1(7.2, "circle1");

    oval1.draw();
    oval1.draw(44); //! The oval object will not "inherite" this method
                    //! error: no matching function for call to ‘Circle::draw(int)
                    //! If we comment out the methods in oval and circle it will work
    circle1.draw();
    circle1.draw(54);

    //* When creatred the same overload as in the Base Class for all down stream derived classes
    //* We will be able to call the overloads as above

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: x06 Overloading, overriding and function hiding
            * Case where we have a ONLY overload of the method draw() in the derived Class Oval
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    Shape *shape_ptr = new Circle(10, "Circle1");
    shape_ptr->draw(45, "Red"); //! So, the method draw() will not have available at Shape Class level
    //! since it was not declared there, but declared at Oval level

    //* Refer to next example x07 Polymorphism at different levels

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    !Note:  #define EXAMPLE_3

            *EXAMPLE: Quiz 76
            The overload with a std::string_view parameter is being eclipsed by
            the no param override in Two. But we're trying to go through a base pointer to call the method.
            The compiler will try its best and use polymorphism as a last resort. It will find a candidate
            at the One level and use that to print the best it can. The One::print(std::string_view) method
            only knows how to print the m_1 member and the color. Hence the output here.
*/

class One
{

public:
    One(int one) : m_1(one)
    {
    }
    virtual void print() const
    {
        std::cout << "data [one:" << m_1
                  << "]";
    }
    virtual void print(std::string_view color) const
    {
        std::cout << "data [one:" << m_1
                  << " color:" << color
                  << "]" << std::endl;
    }

protected:
    int m_1{};
};

class Two : public One
{

public:
    Two(int one, int two) : One(one), m_2(two)
    {
    }

    void print() const override
    {
        std::cout << "data [one:" << m_1
                  << " two:" << m_2
                  << "]" << std::endl;
    }

protected:
    int m_2{};
};

class Three : public Two
{

public:
    Three(int one, int two, int three) : Two(one, two), m_3(three)
    {
    }

    void print() const override
    {
        std::cout << "data [one:" << m_1
                  << " two:" << m_2
                  << " three:" << m_3
                  << "]" << std::endl;
    }

protected:
    int m_3{};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    Three three(100, 200, 300);
    One *base{};
    base = &three;
    base->print("blue");

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_3 END

//
