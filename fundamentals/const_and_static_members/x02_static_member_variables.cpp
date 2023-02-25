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
#include <cmath>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Static members variables
*/

class Point
{

public:
    Point(double x, double y);
    Point();                   // Default constructor
    Point(double xy_coord);    // Point Constructor
    Point(const Point &point); // Point Copy Constructor
    ~Point();                  // Point Destructor

    double length() const;

    size_t get_point_count() const
    {
        return m_point_count;
    }

    void print_info() const
    {
        std::cout << "Point  [ &m_x: " << &m_x << ", &m_y: " << &m_y << " ]" << std::endl;
    }

private:
    double m_x;
    double m_y;
    // public:
    //* Static members variable
    static size_t m_point_count;
};

//* Initialize static member var in the Global scope
//! ISO C++ forbids in-class initialization of a non-const static member / in a header file
//! tehre is import to initialize it in a the definition cpp file
size_t Point::m_point_count{0};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // Print the point count in our program
    // std::cout << "Point count: " << Point::m_point_count << std::endl; //! IF declared public member

    Point p1(5, 5);
    Point p2(8, 8);

    p1.print_info(); // We see that each variables live a different memory address for each Object
    p2.print_info();

    std::cout << "Point count: " << p1.get_point_count() << std::endl; // 2 Point objects

    Point points[]{Point(1,1), Point(2,2), Point(3,3)};

    std::cout << "Point count: " << p1.get_point_count() << std::endl; // 5 Point objects


    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

Point::Point(double x, double y) : m_x{x}, m_y{y}
{
    std::cout << "Point constructor called" << std::endl;

    //* Static members variable
    ++m_point_count;
}

// Point Destructor
Point::~Point()
{
    //* Static members variable
    --m_point_count;
}

// Default constructor
Point::Point() : Point(0.0, 0.0)
{
}

// Point Constructor
Point::Point(double xy_coord) : Point(xy_coord, xy_coord)
{
}

// Point Copy Constructor
Point::Point(const Point &point) : Point{point.m_x, point.m_y}
{
}

// Function to calculate distance from the point(0,0)
double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

#endif // EXAMPLE_1 END

//