
//

#include "point4.hpp"
#include <iostream>
#include <cmath>

//

Point4::Point4(double x, double y)
    : m_x(x), m_y(y)
{
    std::cout << "Constructing Point [ m_x: " << m_x << ", m_y: " << m_y << " ]" << std::endl;
    ++m_point_count;
}

Point4::Point4(double xy_coord) : Point4(xy_coord, xy_coord)
{
    std::cout << "Point4 single param constructor called" << std::endl;
}

Point4::Point4() : Point4(0.0, 0.0)
{
    std::cout << "Point4 default constructor called" << std::endl;
}

Point4::Point4(const Point4 &point) : Point4(point.m_x, point.m_x)
{
    // Copy constructor
    std::cout << "Copy constructor called" << std::endl;
    ++m_point_count; // Creating a copy object. So we increment
}

Point4::~Point4()
{
    // Destructor
    std::cout << "Destroying point object. ";
    // We destroy a point object , so we decrement
    --m_point_count;

    std::cout << " Current point count : " << m_point_count << std::endl;
}

double Point4::length() const
{
    // Function to calculate distance from the point(0,0)
    return sqrt(pow(m_x - 0.0, 2) + pow(m_y - 0.0, 2));
}