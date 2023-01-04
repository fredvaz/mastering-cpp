/*

The C++20 Masterclass:

General Notes:
    A class can include a special function called its constructor, which is automatically called whenever 
    a new object of this class is created, allowing the class to initialize member variables or allocate
    storage.
    This constructor function is declared just like a regular member function, but with a name that matches
    the class name and without any return type; not even void.

   [REF]: 
    https://cplusplus.com/doc/tutorial/classes/
    https://en.cppreference.com/w/cpp/language/constructor
*/

#define Test1

using namespace std;

#ifdef Test1

const double PI{3.1415926535897932384626433832795};

class Cylinder
{
    // The best policy is to make the member priovate in order to avoid others functions that will mess with
private:
    double base_radius{1};
    double height{1};

    // Class methods
public:
    // Default Constructor : if not any other Constructor with parameters and
    // if not declared the default Construtor the Compiler it will generate a empty Constructor
    // with the intial declared values of the member variables
    Cylinder()
    {
        base_radius = 2.0;
        height = 2.0;
    }

    // A Constructor that receives parameters
    Cylinder(double rad_param, double height_param)
    {
        base_radius = rad_param;
        height = height_param;
    }

    double volume()
    {
        return PI * base_radius * height;
    }
};

void test1()
{
    // Initializes the Object with the default Constructor/Value
    Cylinder cylinder1;
    cout << "volume : " << cylinder1.volume() << endl;

    // Initializes the Object with parameters
    Cylinder cylinder2(10, 4);
    cout << "volume : " << cylinder2.volume() << endl;
}
#endif

#ifdef Test2
/*
    Notes: Coding Exercise 46 : Box Constructors
        You are given the code for our Box class in the exercise.h file.
        Your job is to set up a constructor in such a way that we can create Box objects like below
        Box box(10.1,20.4,30.3);
        std::cout << "base area : " << box.base_area() << std::endl;
        std::cout << "volume : " << box.volume() << std::endl;
        The code should correctly compute the area and the volume and get them printed out like below
        base area : 206.04
        volume : 6243.01  
*/
class Box
{

public:
    //methods
    Box(double width_param, double length_param, double height_param)
    {
        m_width = width_param;
        m_length = length_param;
        m_height = height_param;
    }
    double base_area()
    {
        return m_width * m_length;
    }
    double volume()
    {
        return base_area() * m_height;
    }

    //member variables
private:
    double m_width{1};
    double m_length{1};
    double m_height{1};
};

void test2()
{
    Box box(10.1, 20.4, 30.3);
    cout << "base area : " << box.base_area() << endl;
    cout << "volume : " << box.volume() << endl;
}
#endif

#ifdef Test3
/*
    Notes: Coding Exercise 47 : Construct'em Points!
        You will set up a constructor for the Point class in the exercise.h file. After you do so, we should be able to create Point objects and use them like below
        Point p1(1.1,2.1);
        Point p2(3.2,5.2);
        std::cout << "distance from p1 to p2 : " << p1.distance_to(p2) << std::endl;
        The code should correctly compute the distance between the points and print
        distance from p1 to p2 : 3.74433
*/
#include <cmath>

class Point
{
public:
    //methods
    Point(double x_param, double y_param)
    {
        m_x = x_param;
        m_y = y_param;
    }
    double distance_to(Point target)
    {
        return sqrt(std::pow(target.m_x - m_x, 2) + pow(target.m_y - m_y, 2) * 1.0);
    }
    //member variables
private:
    double m_x{1};
    double m_y{1};
};

void test3()
{
    Point p1(1.1, 2.1);
    Point p2(3.2, 5.2);
    cout << "distance from p1 to p2 : " << p1.distance_to(p2) << endl;
}
#endif