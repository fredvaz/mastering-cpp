/*

The C++20 Masterclass:

General Notes:


   [REF]:
*/
// #include "point.h"
// #include "line.h"
// #include "cylinder.h"
#include "point.cpp"
#include "line.cpp"
#include "cylinder.cpp"

#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    Geom::Point p1(10, 20);
    Geom::Point p2(3.4, 6.1);
    p1.print_info();
    p2.print_info();

    cout << "---" << endl;

    Geom::Line l1(p1, p2);
    l1.print_info();

    cout << "---" << endl;

    Geom::Cylinder c1(1.4, 10);
    cout << "c1.volume : " << c1.volume() << endl;
}
#endif