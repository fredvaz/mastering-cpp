#ifndef POINT_H
#define POINT_H

//

#include <iostream>

#include "integer.hpp"

class Point3
{

public:
    // Constructors
    Point3(double x, double y);

    Point3(double xy_coord);     // Point3 Constructor
    Point3();                    // Default constructor
    Point3(const Point3 &point); // Point3 Copy Constructor
    ~Point3();                   // Point3 Destructor

    double length() const;

    size_t get_point_count() const
    {
        return m_point_count;
    }

    //* Member variables of other types (Object) does not have any constrains
    //* as in the last example
    Integer i1{1};
    const Integer i2{2};
    static inline Integer i3{3};
    static inline const Integer i4{4};

    Integer *p_i5{nullptr};
    static Integer i6;
    static const Integer i7;

private:
    double m_x;
    double m_y;
    static size_t m_point_count;
};

#endif // POINT_H

//
