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
#include "libs/libs2/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Non-type template parameters
            * The constrain is that they are very limited before C++20 (GCC and Clang does not support well)
            * - Could only be of int like type int, size_t, basically types you could use to model sizes
            * and ranges
            * - A diffetent instance is generated each time the non-type template parameters values are different
            * Note: C++20 has relaxed the requirements for a type to be usable as a non-type. It is now possible
            * to use floating types as non-type and even some class types. This feature is still shaku across
            * compilers so you can consider it non existent for now
*/

template <typename T, T threashold> //* threashold is a Non type template
class Point
{
public:
    Point(T x, T y);
    ~Point() = default;

private:
    T m_x;
    T m_y;
};

template <typename T, T threashold>
Point<T, threashold>::Point(T x, T y)
    : m_x(x), m_y(y)
{
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    BoxContainer<int, 5> int_box1;  //* One instance
    BoxContainer<int, 10> int_box2; //* Another instance

    int_box1.add(1);
    int_box1.add(2);
    int_box1.add(3);
    int_box1.add(4);
    int_box1.add(5);
    int_box1.add(6);

    std::cout << "int_box1: " << int_box1 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    Point<int, 44> point1(10, 20); // Works
    // Point<double,33.1> point2(11.22,22.33); //! Compiler error : double not a valid
    //  non type template parameter : only integral types
    // that can represent sizes or ranges allowed.

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
