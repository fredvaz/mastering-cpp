/*

The C++20 Masterclass: Default Global Namespaces

General Notes:

   [REF]: No
*/

#define Test1

using namespace std;

// This function is living in the Default Global Scope
double add(double a, double b)
{
    return a + b;
}

namespace My_Thing
{
    // This function is living the My_Thing scope
    double add(double a, double b)
    {
        return a + b - 1;
    }

#ifdef Test1
    void do_something()
    {
        // To call a function from the Global Scope we use :: operator with the function name
        double result = ::add(5, 6);
        cout << "result : " << result << endl;
    }
#endif

#ifdef Test2
    void do_something()
    {
        // In this case the function will called be from the closest scope, so, the namescope where it lives
        double result = add(5, 6);
        cout << "result : " << result << endl;
    }
#endif
}

#ifdef Test1
void test1()
{
    My_Thing::do_something();
}
#endif

#ifdef Test2
void test2()
{
    My_Thing::do_something();
}
#endif