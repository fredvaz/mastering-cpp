#ifndef POINT_H
#define POINT_H

//

#include <iostream>

class Point4
{

public:
    // Constructors
    Point4(double x, double y);
    Point4(double xy_coord);    // Point4 Constructor
    Point4();                   // Default constructor
    Point4(const Point4 &point); // Point4 Copy Constructor
    ~Point4();                  // Point4 Destructor

    double length() const;

    //* Static member functions
    //! note: cannot be const, the static member function does not have acess to the member variables
    //! so, neither the member function can be blocked from change the members 
    static size_t get_point_count() // const
    {
        return m_point_count;
    }

    //* To get access from the static member function we must pass a Point object as reference
    static void print_info(const Point4 &p)
    {
        // std::cout << "Point: [ m_x: " << m_x << ", m_y: " << m_y << " ]" << std::endl; //! Compiler error
        std::cout << "Point: [ m_x: " << p.m_x << ", m_y: " << p.m_y << " ]" << std::endl;
        // std::cout << m_test << std::endl; //! Compiler error
    }

    double m_test;

private:
    double m_x;
    double m_y;
    //* Satic data member
    inline static size_t m_point_count{}; //! note: the inline keyword allows to initialize from the class declaration
};

#endif // POINT_H