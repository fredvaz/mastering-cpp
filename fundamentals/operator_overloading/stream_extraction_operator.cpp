/*

The C++20 Masterclass: operator overloading >> stream extraction operator

General Notes:
        Customizes the C++ operators for operands of user-defined types.
        if you make your operator a member function, the first operand has to be an
        object of the class that you are doing the operator for.
        Refer to addition operator as member

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

    // stream extraction operator
	friend std::istream& operator>>(std::istream& is, Point& p);

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

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";	
	return os;
}

// stream extraction operator


int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(5, 10);
    point p2;

    // stream extraction operator
    std::cin >> p2;

    std::cout << "p2: " << p2 << std::end;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END