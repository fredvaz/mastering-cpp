/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <cmath>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Unary Prefix Increment Operator As Member
*/

class Point
{
    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    // Compound operators +=/-=
    friend Point &operator+=(Point &left, const Point &right);
    friend Point &operator-=(Point &left, const Point &right);

public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    ~Point() = default;

    //* Unary Prefix Increment Operator As Member
    void operator++()
    {
        ++m_x;
        ++m_y;
    }

    void print_info()
    {
        std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
    }

private:
    double length() const;

private:
    double m_x{};
    double m_y{};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(5, 5);
    
    std::cout << "p1: " << p1 << std::endl;

    //* Unary Prefix Increment Operator As Member
    ++p1; 
    p1.operator++(); //! Compiler udnder the hood does p1.operator++()
    //* Note: Unary operattor becaus it is taking only one operand

    std::cout << "p1: " << p1 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// Stream insertion operation operator as free function NON memmber function of the Class
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "Point [ x: " << p.m_x << ", y: " << p.m_y << " ]";
    return os;
}

#endif // EXAMPLE_1 END

//