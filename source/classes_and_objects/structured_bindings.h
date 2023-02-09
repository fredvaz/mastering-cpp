/*

The C++20 Masterclass: Structured Bindings

General Notes:
        Allows to get the member variables of a Class like in MATLAB functions
        only works with public members

   [REF]:
   
*/
#include <iostream>

using namespace std;

class Point
{
public:
    double x;
    double y;
};

void print_point(const Point p)
{
    std::cout << "Point [ x: " << p.x << ", y: " << p.y << "]" << std::endl;
}

#ifdef Test1
void test1()
{
    /*
    Notes:  #define Test1

            Test Case: 
    */
    cout << "--------------------------------------------------------------------------------" << endl;

    Point point1;

    point1.x = 3;
    point1.y = 5;

    print_point(point1);

    // Structured binding
    auto [a, b] = point1;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    point1.x = 30;
    point1.y = 50;

    print_point(point1);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;


    // Lambda Expression: captures all (=) variables inside the body
    auto func = [=]()
    {
        std::cout << "a (captured) : " << a << std::endl;
        std::cout << "b (captured) : " << b << std::endl;
    };
    func();

    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif