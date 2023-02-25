/*

The C++20 Masterclass Section 39: Comparison/Logical Operators and C++20 Thre Way Comparision Infrastructure

General Notes:
        *Customizes the C++ operators for operands of user-defined types.


   [REF]:
    https://en.cppreference.com/w/cpp/language/operators
    https://en.cppreference.com/w/cpp/language/operator_comparison

*/
#include <iostream>
#include <cmath>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE:
*/

class Point
{
    friend std::ostream &operator<<(std::ostream &out, const Point &p);
    friend bool operator>(const Point &left, const Point &right);
    friend bool operator>=(const Point &left, const Point &right);
    friend bool operator==(const Point &left, const Point &right);
    friend bool operator!=(const Point &left, const Point &right);
    friend bool operator<(const Point &left, const Point &right);
    friend bool operator<=(const Point &left, const Point &right);

public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    ~Point() = default;
    // Operators
    /*
    bool operator> (const Point& other) const;
    bool operator< (const Point& other) const;
    bool operator>=(const Point& other) const;
    bool operator<=(const Point& other) const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    */

private:
    double length() const; // Function to calculate distance from the point(0,0)
private:
    double m_x{};
    double m_y{};
};

inline std::ostream &operator<<(std::ostream &out, const Point &p)
{
    out << "Point [ x : " << p.m_x << ", y : " << p.m_y << " length : " << p.length() << "]";
    return out;
}

inline bool operator>(const Point &left, const Point &right)
{
    return (left.length() > right.length());
}

inline bool operator>=(const Point &left, const Point &right)
{
    return (left.length() >= right.length());
}

inline bool operator==(const Point &left, const Point &right)
{
    return (left.length() == right.length());
}

inline bool operator!=(const Point &left, const Point &right)
{
    return (left.length() != right.length());
}

inline bool operator<(const Point &left, const Point &right)
{
    return (left.length() < right.length());
}

inline bool operator<=(const Point &left, const Point &right)
{
    return (left.length() <= right.length());
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point point1(10.0, 10.0);
    Point point2(20.0, 20.0);

    std::cout << "point1 : " << point1 << std::endl;
    std::cout << "point2 : " << point2 << std::endl;

    std::cout << "point1 > point2 : " << std::boolalpha << (point1 > point2) << std::endl;
    std::cout << "point1 < point2 : " << (point1 < point2) << std::endl;
    std::cout << "point1 >= point2 : " << (point1 >= point2) << std::endl;
    std::cout << "point1 <= point2 : " << (point1 <= point2) << std::endl;
    std::cout << "point1 == point2 : " << (point1 == point2) << std::endl;
    std::cout << "point1 != point2 : " << (point1 != point2) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

/*
bool Point:: operator>(const Point& other)const{
    return (this->length() > other.length());
}
bool Point::operator< (const Point& other) const{
    return (this->length() < other.length());
}
bool Point::operator>=(const Point& other) const{
    return (this->length() >= other.length());
}
bool Point::operator<=(const Point& other) const{
    return (this->length() <= other.length());
}
bool Point::operator==(const Point& other) const{
    return (this->length() == other.length());
}
bool Point::operator!=(const Point& other) const{
    return (this->length() != other.length());
}
*/
