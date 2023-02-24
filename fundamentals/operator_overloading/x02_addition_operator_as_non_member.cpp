/*

The C++20 Masterclass: operator overloading -> addition operator

General Notes:
        Customizes the C++ operators for operands of user-defined types.

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Adding Operator as NON Member of a Class -> operator+(p1, p2)
*/
class Point
{
	// We must declare operator+ method as a friend function in order to have
	// direct access to its members variables m_x, m_y
	// this way we are not expose them as public to every object
	friend Point operator+(const Point &left, const Point &right);
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y)
	{
	}
	~Point() = default;

	void print_info()
	{
		std::cout << "Point [ x: " << m_x << ", y: " << m_y << "]" << std::endl;
	}

private:
	double length() const; // Function to calculate distance from the point(0,0)

private:
	double m_x{};
	double m_y{};
};

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// Adding a operator overloading method
// <return type> <operator keyword><symbol>(object parameter1, object parameter2)
Point operator+(const Point &left, const Point &right)
{
	return Point(left.m_x + right.m_x, left.m_y + right.m_y);
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Point p1(10, 20);
    Point p2(20, 30);

    Point p3(p1 + p2); // The compiler under the hood does operator+(p1, p2)
    Point similar_p3(operator+(p1, p2));

    Point p4(p2 + Point(5,5));

    p3.print_info();
    similar_p3.print_info();
    p4.print_info();

    // Another example that works
    (Point(20, 20) + Point(10, 10)).print_info();


    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END


// Adding a operator overloading method
// <return type> <operator keyword><symbol>(object parameter1, object parameter2)
// inline Point operator+(const Point &left, const Point &right)
// {
// 	return Point(left.m_x + right.m_x, left.m_y + right.m_y);
// }
// This is a free standing global function
// Note: the inline keyword here is just to use the function in header file
// in the cpp file implementation we don't need the inline declaration