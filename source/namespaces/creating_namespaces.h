/*

The C++20 Masterclass:

General Notes:
    Namespaces provide a method for preventing name conflicts in large projects.
    Symbols declared inside a namespace block are placed in a named scope that prevents them
    from being mistaken for identically-named symbols in other scopes.
    Multiple namespace blocks with the same name are allowed. All declarations within those blocks
    are declared in the named scope.

    Namespaces allow to group entities like classes, objects and functions under a name. 
    This way the global scope can be divided in "sub-scopes", each one with its own name.

   [REF]:
    https://en.cppreference.com/w/cpp/language/namespace
    https://cplusplus.com/doc/tutorial/namespaces/
    https://cplusplus.com/doc/oldtutorial/namespaces/
*/

#define Test2

using namespace std;

const double adjustment{0.724};

namespace No_Adjust
{
    double add(double x, double y)
    {
        return x + y;
    }
}

namespace Adjust
{
    // This function was redefining the function above because has the same exactly signature
    double add(double x, double y)
    {
        return x + y - adjustment;
    }
}

namespace No_Adjust
{
    // functions declaration only
    double mult(double x, double y);
    double div(double x, double y);
}

namespace Adjust
{
    // functions declaration only
    double mult(double x, double y);
    double div(double x, double y);
}

#ifdef Test1
void test1()
{
    // To set which namespace to be use, we use the namespace name and :: operator
    double result = No_Adjust::add(2, 3);
    cout << "result : " << result << endl;
}
#endif

#ifdef Test2
void test2()
{
    double result = No_Adjust::div(2, 3);
    cout << "result : " << result << endl;
}
#endif


namespace No_Adjust
{
    // functions implementation
    double mult(double x, double y)
    {
        return x * y;
    }
    double div(double x, double y)
    {
        return x / y;
    }
}

namespace Adjust
{
    // functions implementation
    double mult(double x, double y)
    {
        return x * y - adjustment;
    }
    double div(double x, double y)
    {
        return x / y - adjustment;
    }
}