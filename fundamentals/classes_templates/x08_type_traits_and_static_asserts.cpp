/*

The C++20 Masterclass Section 44: Class Templates

General Notes:
        A class template defines a family of classes.

        A class template by itself is not a type, or an object, or any other entity. No code is generated
        from a source file that contains only template definitions. In order for any code to appear
        a template must be instantiated: the template arguments must be provided so that the compiler
        can generate an actual class (or function, from a function template).

   [REF]:
    https://en.cppreference.com/w/cpp/language/class_template

*/
#include <iostream>
#include <type_traits>
#include "libs/libs7/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Class templates with type traits and static asserts
*/

template <typename T>
class Point
{   
    //* Static asserts
    static_assert(std::is_arithmetic_v<T>,
                  "Coordinates of Point can only be numbers.");

public:
    Point() = default;
    Point(T x, T y)
        : m_x(x), m_y(y)
    {
    }
    //* Note: friend function in Class template can be declared here, but must in the public section to be accessible
    friend std::ostream &operator<<(std::ostream &out, const Point<T> operand)
    {
        out << "Point [ x: " << operand.m_x
            << ", y: " << operand.m_y << "]";
        return out;
    }

private:
    T m_x;
    T m_y;
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point<int> point_int(10, 20);
    std::cout << "point_int: " << point_int << std::endl;

    Point<double> point_double(11.1, 12.2);
    std::cout << "point_double: " << point_double << std::endl;

    //! error: static assertion failed: Coordinates of Point can only be numbers
    // Point<std::string> point_string("Hello", "World");
    // std::cout << "point_string: " << point_string << std::endl;

    BoxContainer<Point<int>> point_box;
    point_box.add(point_int);
    point_box.add(Point<int>(40, 50));

    std::cout << "point_box: " << point_box << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
