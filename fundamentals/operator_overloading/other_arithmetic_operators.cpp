/*

The C++20 Masterclass: operator overloading

General Notes:
        Customizes the C++ operators for operands of user-defined types.
        
        Not makes sens to overloading all the available operators in C++
        Overload the operator must makes sense for a particular Class

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <cmath>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend Point operator+(const Point &left, const Point &right);
    friend Point operator-(const Point &left, const Point &right);
	
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}
	~Point() = default;

	void print_info(){
		std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
	}

private: 
	double length() const;   // Function to calculate distance from the point(0,0)

private : 
	double m_x{}; 
	double m_y{}; 
};

double Point::length() const{
    return sqrt(pow(m_x - 0, 2) +  pow(m_y - 0, 2) * 1.0); 
}

inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";	
	return os;
}

// + operator overloading
Point operator+(const Point &left, const Point &right)
{
    return Point(left.m_x + right.m_x, left.m_y + right.m_y);
}

// - operator overloading
Point operator-(const Point &left, const Point &right)
{
    return Point(left.m_x - right.m_x, left.m_y - right.m_y);
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::cout << (Point(20, 20) - Point(10, 10)) << std::endl;
    std::cout << (Point(20, 20) + Point(10, 10)) << std::endl;

    Point p1(10,10);
    Point p2(20,20);
    Point p3{p1 + p2};
    Point p4{p2 - Point(5,5)};
    
    std::cout << "point1 : " <<  p1 << std::endl; 
    std::cout << "point3 : " << p3 << std::endl; 
    std::cout << "point4 : " << p4 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END