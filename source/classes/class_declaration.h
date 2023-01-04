/*

The C++20 Masterclass: Classes

General Notes: 
    Classes are an expanded concept of data structures: like data structures, they can contain data members,
    but they can also contain functions as members.
    An object is an instantiation of a class. In terms of variables, a class would be the type, and an object
    would be the variable.

   [REF]: 
    https://cplusplus.com/doc/tutorial/classes/
    https://en.cppreference.com/w/cpp/language/classes
*/

#define Test1

using namespace std;

#ifdef Test1

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
    // public members are accessible from anywhere where the object is visible
    // By default are declared as private members : private members of a class are accessible
    // only from within other members of the same class (or from their "friends").
    // Therefore, in the main function we cannot acces them or changed the values
    // Class members
public: // private by default
    double base_radius{1};
    double height{1};

    // Class methods
public:
    double volume()
    {
        return PI * base_radius * height;
    }
};

void test1()
{
    // Declaration of an Object
    Cylinder cylinder1;
    cout << "volume : " << cylinder1.volume() << endl;
    cout << "base_radius : " << cylinder1.base_radius << endl;
    cout << "height : " << cylinder1.height << endl;

    // Change the member variables of the Object
    cylinder1.base_radius = 10;
    cylinder1.height = 3;

    cout << "volume : " << cylinder1.volume() << endl;
}
#endif

#ifdef Test2
/*
    Notes: Coding Exercise 45
*/
#include <cmath>

class Point
{
public:
    double m_x{1};
    double m_y{1};

public:
    double distance_to(Point p2);
};

// When no declaring the methods/member functions whithin Class scope we shoudl use the Class name and scope operator
Point::double distance_to(Point p2)
{
    return sqrt(pow(p2.m_x - m_x, 2) + pow(p2.m_y - m_y, 2));
}

void test2()
{
    Point p1;
    Point p2;

    p2.m_x = 2;
    p2.m_y = 2;

    cout << "distance from p1 to p2 : " << p1.distance_to(p2) << endl;
}
#endif