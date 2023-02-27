/*

The C++20 Masterclass Section 34: Static members and Const members

General Notes:
    Inside a class definition, the keyword static declares members that are not bound to class instances.
    Static members of a class are not associated with the objects of the class: they are independent variables
    with static or thread (since C++11) storage duration or regular functions.

    !e.g., they can allow to keep track how many objects for a class are created

   [REF]:
    https://en.cppreference.com/w/cpp/language/static

*/
#include <iostream>
#include "libs/integer.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: In class member initialization revisited
            Before C++11m in class member initialization was only possible for:
                - Static constants of integral types or
                - Static constants of enum type
*/

class Point5
{

public:
    Point5() = default; //! note: puts an empty body on the constructor and it's not going do any initialization
    Point5(double x, double y) : m_x{x}, m_y{y}
    {
    }
    ~Point5();

    void print_info()
    {
        std::cout << "x: " << m_x << " y: " << m_y << std::endl;
    }

private:
    //* No Initialization at all, it will put junk in our data
    // double m_x;
    // double m_y;

    //* Explicit assignment in Modern C++11
    //! note: pre C11++ it will fail
    // double m_x = 0.1;
    // double m_y = 0.1;

    //* Braced initializers
    //! note: empty {} initializes the varaibles with 0
    double m_x{};
    double m_y{};
    // double m_x{0.1};
    // double m_y{0.1};

    //* Default constructor to the object
    Integer i{};

};

Point5::~Point5()
{
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point5 p1; //* Call the default constructor

    p1.print_info();

    Integer i1;

    std::cout << "integer: " << i1.get_value() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
