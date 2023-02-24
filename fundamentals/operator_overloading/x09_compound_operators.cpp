/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.

        !Not makes sense to overloading all the available operators in C++
        !Overload the operator must makes sense for a particular Class

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

            *EXAMPLE: Compound operators +=/-=
*/

class Point
{
    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    //* Compound operators +=/-=
    friend Point &operator+=(Point &left, const Point &right);
    friend Point &operator-=(Point &left, const Point &right);

    //* Reuse of +/- operator overloading using the compound operator +=/-=
    friend Point operator+(const Point &left, const Point &right);
    friend Point operator-(const Point &left, const Point &right);

public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    ~Point() = default;

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

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// Stream insertion operation operator as free function NON memmber function of the Class
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";
    return os;
}

//* Compound operators +=
Point &operator+=(Point &left, const Point &right)
{
    left.m_x += right.m_x;
    left.m_y += right.m_y;

    return left;
}

//* Compound operators -=
Point &operator-=(Point &left, const Point &right)
{
    left.m_x -= right.m_x;
    left.m_y -= right.m_y;

    return left;
}

//* Reuse of + operator overloading using the compound operator +=
Point operator+(const Point &left, const Point &right)
{
    Point p(left);
    return p += right;
}

//* Reuse of - operator overloading using the compound operator -=
Point operator-(const Point &left, const Point &right)
{
    Point p(left);
    return p -= right;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(5, 5);
    Point p2(10, 10);
    Point p3(15, 15);

    p1 += p2; //* Compound operators +=
    p2 -= p3; //* Compound operators -=

    std::cout << "point1: " << p1 << std::endl;
    std::cout << "point2: " << p2 << std::endl;
   
    //* Reuse of +/- operator overloading using the compound operator +=/-=
    std::cout << "p1 + p2: " << (p1 + p2) << std::endl;
    std::cout << "p2 - p3: " << (p2 - p3) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END