/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <cmath>
#include <string>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Type Conversions Recap
*/

// class Point; // Forward declaration

class Number
{
    friend std::ostream &operator<<(std::ostream &out, const Number &number);
    // Arithmetic operators
    friend Number operator+(const Number &left_operand, const Number &right_operand);
    friend Number operator-(const Number &left_operand, const Number &right_operand);
    friend Number operator*(const Number &left_operand, const Number &right_operand);
    friend Number operator/(const Number &left_operand, const Number &right_operand);
    friend Number operator%(const Number &left_operand, const Number &right_operand);

public:
    Number() = default;
    Number(int value);
    ~Number();

    //* Type conversion operator from Number to Point
    operator Point() const;
    // {
    //     std::cout << "Using type conversion from Number to Point" << std::endl;
    //     return Point(static_cast<double>(m_wrapped_int),
    //                  static_cast<double>(m_wrapped_int));
    // }

    // getter
    int get_wrapped_int() const;

private:
    int m_wrapped_int{0};
};

int Number::get_wrapped_int() const
{
    return m_wrapped_int;
}

//* Type conversion operator from Number to Point
Number::operator Point() const
{
    std::cout << "Using type conversion from Number to Point" << std::endl;
    return Point(static_cast<double>(m_wrapped_int),
                 static_cast<double>(m_wrapped_int));
}

class Point
{
    // Stream insertion operation operator as free function NON memmber function of the Class
    friend std::ostream &operator<<(std::ostream &os, const Point &p);

public:
    Point() = default;
    Point(double x, double y);
    // Copy Constructor
    Point(const Point &p);
    //* Constructor from Number
    // Point(const Number &n);
    ~Point() = default;

    // Custom Copy Assignment Operator
    Point &operator=(const Point &right_operand)
    {
        std::cout << "Custom Copy Assignment operator called" << std::endl;
        if (this != &right_operand)
        {
            m_x = right_operand.m_x;
            m_y - right_operand.m_y;
        }
        return *this;
    }

    //* Copy Assignment for Number Class
    // void operator=(const Number &n);

private:
    double m_x{};
    double m_y{};
};

// Point::Point(const Number &n)
// {
//     std::cout << "Point Constructor from Number called..." << std::endl;
//     m_x = m_y = n.get_wrapped_int();
// }

// void Point::operator=(const Number &n)
// {
//     std::cout << "Point Copy assignment operator from Number called..." << std::endl;
//     m_x = m_y = n.get_wrapped_int();
// }

void do_something_with_point(const Point &p)
{
    std::cout << "point : " << p << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(7, 7);
    Number n1(22);

    //* Copy Assignment for Number Class
    p1 = n1;
    // The Compiler has two choices:
    // 1. Copy assiggment operator called
    // 2. Constructor taking in a Number
    // Typoe conversion operator: Number -> Point

    // do_something_with_point(n1);
    // 1. Constructor
    // 2. Type conversion operator

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

Point::Point(double x, double y) : m_x(x), m_y(y)
{
}

// Copy Constructor
Point::Point(const Point &p)
{
    std::cout << "Copy Constructor called to copy " << p << std::endl;
    if (this != &p)
    {
        m_x = p.m_x;
        m_y - p.m_y;
    }
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "Point [ x: " << p.m_x << ", y: " << p.m_y << " ]";
    return os;
}

//

Number::Number(int value) : m_wrapped_int(value)
{
}

Number::~Number()
{
}

std::ostream &operator<<(std::ostream &out, const Number &number)
{
    out << "Number: [" << number.m_wrapped_int << "]";
    return out;
}

// Operators done as non member functions to take advantage of
// implicit conversions
Number operator+(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);
}
Number operator-(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);
}
Number operator*(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);
}
Number operator/(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);
}
Number operator%(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);
}

#endif // EXAMPLE_1 END

//
