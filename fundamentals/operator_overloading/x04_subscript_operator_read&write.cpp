/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.

        The subscript operator is a binary operator
        !The operator MUST be set up as a member function of a Class

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <cmath>
#include <cassert>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note:  #define EXAMPLE_1

            *EXAMPLE: subscript operator [] read and write
*/

class Point
{
public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    ~Point() = default;

    //* Adding a subscript operator [] overloading method to read and write
    //* return a & reference 
    double &operator[](size_t index);
    //! note: the method cannot be const because, now we want the method to change the variables member

    void print_info()
    {
        std::cout << "Point [ x: " << m_x << ", y: " << m_y << "]" << std::endl;
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

//* Adding a subscript operator [] overloading method
//* <return type> <operator keyword><symbol>(object parameter1)
double& Point::operator[](size_t index)
{
    assert((index == 0) || (index == 1)); //! If the condtion not true, crashes the program at runtime
    return (index == 0) ? m_x : m_y; // returns the member variable as True reference / it's memory address
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(5, 5);

    // Reading using the subscript
    std::cout << "p1.x: " << p1[0] << std::endl; // x coordinate
    std::cout << "p1.y: " << p1[1] << std::endl; // y coordinate

    //* Writing data using subscript operator
    p1[0] = 10.5;
    p1[1] = 10.5;
    // p1[10] = 10.5; //! Assertion `(index == 0) || (index == 1)' failed.Aborted (core dumped)

    //* Reading using the subscript
    std::cout << "p1.x: " << p1[0] << std::endl; // x coordinate
    std::cout << "p1.y: " << p1[1] << std::endl; // y coordinate

    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END
