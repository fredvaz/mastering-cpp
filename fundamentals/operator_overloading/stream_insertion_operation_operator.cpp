/*

The C++20 Masterclass: operator overloading << stream insertion operation operator

General Notes:
        Customizes the C++ operators for operands of user-defined types.
        if you make your operator a member function, the first operand has to be an
        object of the class that you are doing the operator for.
        Refer to addition operator as member

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <cmath>

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Correct Way
*/

class Point
{
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    ~Point() = default;

    void print_info()
    {
        std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]";
    }

private:
    double length() const; // Function to calculate distance from the point(0,0)

private:
    double m_x{};
    double m_y{};
};

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// Stream insertion operation operator as free function NON memmber function of the Class
inline std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";

    return os;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    Point p1(3, 5);
    Point p2(5, 10);

    // p1.print_info();

    // Stream insertion operation operator : Correct Approach
    std::cout << p1 << std::endl;

    std::cout << p1 << " " << p2 << std::endl;


    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Wrong way to implement it
*/

class Point
{

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

    // Stream insertion operation operator as memmber function of the Classs
    std::ostream &operator<<(std::ostream &os)
    {
        os << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;

        return os;
    }

private:
    double length() const; // Function to calculate distance from the point(0,0)

private:
    double m_x{};
    double m_y{};
};

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(10, 20);

    // p1.print_info();

    // Stream insertion operation operator as memmber function of the Class
    // std::cout << p1 << std:endl;
    p1 << std::cout;
    p1.operator<<(std::cout); // the equivalent

    // But this is not the best approach, see EXAMPLE_2

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END