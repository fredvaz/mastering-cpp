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

            *EXAMPLE: Prefix-Postfix Decrement Operator (Exercise)
*/

class Point
{
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    // Compound operators +=/-=
    friend Point &operator+=(Point &left, const Point &right);
    friend Point &operator-=(Point &left, const Point &right);

    //* Unary Prefix Decrement Operator As Non-Member
    friend void operator--(Point &operand);

    //* Unary Postfix Decrement Operator as non-member function
    friend Point operator--(Point &operand, int);

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

//* Unary Prefix Increment Operator As Non-Member
void operator--(Point &operand)
{
    --operand.m_x;
    --operand.m_y;
}

//* Unary Postfix Decrement Operator as non-member function
Point operator--(Point &operand, int)
{
    Point local_point(operand);
    --(operand);
    return local_point;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(5, 5);

    std::cout << "p1: " << p1 << std::endl;

    //* Prefix Decrement Operator (Exercise)
    --p1;
    std::cout << "p1: " << p1 << std::endl; //! << --p1 << does not work

    //* Postfix Decrement Operator (Exercise)
    std::cout << "p1: " << p1-- << std::endl;
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