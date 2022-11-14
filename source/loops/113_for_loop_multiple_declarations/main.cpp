/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{
    // For Loop : Multiple Declarations : The catch is all the variables must all the same type
    for (size_t i{0}, x{5}, y{22}; y > 15; i++, x += 5, y -= 1)
    {
        cout << "i: " << i << " x: " << x << " y: " << y << endl; 
        cout << "sizeof(i): " << sizeof(i) << endl;
        cout << "sizeof(x): " << sizeof(x) << endl;
        cout << "sizeof(y): " << sizeof(y) << endl;
        cout << "------------------------" << endl; 
    }
    
}


int main()
{
    
    // Notes:
    // For Loop : Multiple Declarations

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}