/*

The C++20 Masterclass: Using-declarations

General Notes:
        Introduces a name that is defined elsewhere into the declarative region
        where this using-declaration appears.

        Using-declarations can be used to introduce namespace members into other namespaces 
        and block scopes, or to introduce base class members into derived class definitions
        or to introduce enumerators into namespaces, block, and class scopes (since C++20).

   [REF]:
    https://en.cppreference.com/w/cpp/language/namespace
    https://cplusplus.com/doc/tutorial/namespaces/
*/
#include "namespaces_across_mutiple_files/point.cpp"
#include "namespaces_across_mutiple_files/line.cpp"
#include "namespaces_across_mutiple_files/cylinder.cpp"
#include "namespaces_across_mutiple_files/operations.cpp"

#define Test1

//using Geom::Point; // Brings in just the Point name form the namespace
// Makes the name directly usable in the global scope

using namespace Geom; // Brings in the entire namespace

double add(double a, double b)
{
    std::cout << "::add" << std::endl;
    return a + b + 0.555;
}
// BAD : Will conflict wiht the add function from the global namespace (above)
//using namespace Math;
//using Math::add;

#ifdef Test1
void test1()
{
    Point p1(10.1, 20.1);
    Point p2(20.1, 30.1);

    p1.print_info();
    p2.print_info();

    std::cout << "--------------------------------------------------------------" << std::endl;

    Line l1(p1, p2);
    l1.print_info();

    std::cout << "--------------------------------------------------------------" << std::endl;

    Cylinder c1(1.4, 10);
    std::cout << "c1.volume : " << c1.volume() << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;

    Math_Weighted::add(10, 20);

    std::cout << "--------------------------------------------------------------" << std::endl;

    // The compiler will call the function that lives in the global scope
    add(1, 1);
    // To explicitly declre that we want to use the function from the namespace Math
    Math::add(10, 10);

    using std::cout;
    using std::endl;
    //using namespace std; // NOT RECOMMENDED!

    cout << "Hello World!" << endl;

}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
}
#endif