
//

#include "point2.hpp"
#include <cmath>

//

 //* Another way: Initialize the member variables in a cpp file
const Point2 Point2::m_point4{6, 6};
Point2 Point2::m_point5{7, 7};

//! intialize it dynamically it will call the Point() constructor endless until the heap memory ends: segmentation fault
// Point2::Point2(double x, double y) : p_m_point4{new Point2()}, m_x{x}, m_y{y}
//* Correct way: set up a Pointer and intialize it as nullptr
Point2::Point2(double x, double y) : p_m_point4{nullptr}, m_x{x}, m_y{y}
{
    std::cout << "Point2 constructor called" << std::endl;
    ++m_point_count;
}

// Point2 Constructor
Point2::Point2(double xy_coord) : Point2(xy_coord, xy_coord)
{
}
// Default constructor
Point2::Point2() : Point2(0.0, 0.0)
{
}
// Point2 Copy Constructor
Point2::Point2(const Point2 &point2) : Point2{point2.m_x, point2.m_y}
{
}
// Point2 Destructor
Point2::~Point2()
{
    --m_point_count;
}
// Function to calculate distance from the point2(0,0)
double Point2::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

//
