#ifndef POINT2_H
#define POINT2_H

//

#include <iostream>

class Point2
{

public:
    // Constructors
    Point2(double x, double y);
    Point2(double xy_coord);     // Point2 Constructor
    Point2();                    // Default constructor
    Point2(const Point2 &point); // Point2 Copy Constructor
    ~Point2();                   // Point2 Destructor
    double length() const;       // Function to calculate distance from the point(0,0)

    size_t get_point2_count() const
    {
        return m_point_count;
    }

    //* If we want to intialize our member variable as Point Class type
    void initialize_pointer(double x, double y)
    {
        p_m_point4 = new Point2(x, y);
    }

    void print_info() const
    {
        std::cout << "Point [ m_x: " << m_x << ", m_y: " << m_y << " ]" << std::endl;
        // note: to print the memory addresses just type reference operator &m_x, &m_y
    }

public:
    //* Member variables of self type
    // Point2 m_point1; //! Incomplete type compiler error
    // const Point2 m_point2; //! Incomplete type compiler error
    // static inline const Point2 m_point3{}; //! Incomplete type compiler error

    //* Correct way: set up a Pointer and intialize it as nullptr
    Point2 *p_m_point4;

    //* Another way: Initialize the member variables in a cpp file
    static const Point2 m_point4;
    static Point2 m_point5;

private:
    double m_x;
    double m_y;
    inline static size_t m_point_count{}; // C++17
};
#endif // POINT2_H