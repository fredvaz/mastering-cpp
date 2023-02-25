/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.
        !Type conversion. Can only be done as member function of a Class

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

            *EXAMPLE: Custom type conversions
*/

//! Forward declaration of the class Number to able used in Point Class
// class Number; 

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

    //* Another way using a Point Constructor
    // Point(const Number &num);

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
//* Another way using a Point Constructor Note: has to be implemented a cpp file apart
// Point::Point(const Number &num)
//     : Point(static_cast<double>(num.get_wrapped_int()),
//             static_cast<double>(num.get_wrapped_int()))
// {
//     std::cout << "Using the Point constructor" << std::endl;
// }


//* Custom type conversions
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
    ~Number();
    Number(int value);

    //* Custom type conversions from "int" Number object to a double
    //! Type conversion. Can only be done as member function of a Class
    //! explicit keyword declares that we must declare a explict conversion on the call
    explicit operator double() const
    {
        return (static_cast<double>(m_wrapped_int));
    }

    //* Custom type conversions from "int" Number object to Point object
    explicit operator Point() const
    {   
        std::cout << "Custom conversion from Number to Point" << std::endl;
        // Point( member m_x, member m_y)
        return Point(static_cast<double>(m_wrapped_int), static_cast<double>(m_wrapped_int));
    }

    // getter
    int get_wrapped_int() const
    {
        return m_wrapped_int;
    }

private:
    int m_wrapped_int{0};
};

//* Custom type conversions
double sum(double a, double b)
{
    return a + b;
}

void use_point(const Point &p)
{
    std::cout << "Priting the point from use_point(): " << p << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Number num1(7);
    Number num2(10);
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    // std::cout << (num1 + Number(3)) << std::endl;

    //* Custom type conversions from "int" Number object to a double
    // double result = sum(num1, num2); // Implicit onversion
    double result = sum(static_cast<double>(num1), static_cast<double>(num2)); //! we must declare a explict conversion because the delcared it in the method

    std::cout << "result: " << result << std::endl;

    //* Custom type conversions from "int" Number object to Point object
    use_point(static_cast<Point>(num1));

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

// Stream insertion operation operator as free function NON memmber function of the Class
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "Point [ x: " << p.m_x << ", y: " << p.m_y << " ]";
    return os;
}

// Compound operators +=
Point &operator+=(Point &left, const Point &right)
{
    left.m_x += right.m_x;
    left.m_y += right.m_y;

    return left;
}

// Compound operators -=
Point &operator-=(Point &left, const Point &right)
{
    left.m_x -= right.m_x;
    left.m_y -= right.m_y;

    return left;
}

Number::Number(int value) : m_wrapped_int(value)
{
}

std::ostream &operator<<(std::ostream &out, const Number &number)
{
    out << "Number: [" << number.m_wrapped_int << "]";
    return out;
}

Number::~Number()
{
}

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