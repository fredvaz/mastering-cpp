
//

#include "point3.hpp"
#include <iostream>
#include <cmath>

//

//* Initialize static member of Point3 class to 0
size_t Point3::m_point_count{}; 

Integer Point3::i6{6};
const Integer Point3::i7{7};

Point3::Point3(double x, double y)
    : p_i5(new Integer(5)), //* Now, we can intialize the memner with the Constructor, it will not be called endless
      m_x(x), m_y(y)
{
    std::cout << "Constructing Point3 [ m_x : " << m_x << ", m_y : " << m_y << "]" << std::endl;
    ++m_point_count;
}

Point3::Point3(double xy_coord) : Point3(xy_coord, xy_coord)
{
    std::cout << "Point3 single param constructor called" << std::endl;
}

Point3::Point3() : Point3(0.0, 0.0)
{
    std::cout << "Point3 default constructor called" << std::endl;
}

Point3::Point3(const Point3 &point) : m_x(point.m_x)
{
    // Copy constructor
    std::cout << "Copy constructor called" << std::endl;
    ++m_point_count; // Creating a copy object. So we increment
}

Point3::~Point3()
{
    // Destructor
    std::cout << "Destroying point object. ";
    // We destroy a point object , so we decrement
    --m_point_count;

    std::cout << " Current point count : " << m_point_count << std::endl;
}

double Point3::length() const
{
    // Function to calculate distance from the point(0,0)
    return sqrt(pow(m_x - 0.0, 2) + pow(m_y - 0.0, 2));
}