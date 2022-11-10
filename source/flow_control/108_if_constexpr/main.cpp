/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{
    constexpr bool condition {false};

    if constexpr(condition)
    {
        cout << "Condition is True" << endl;
    }else
    {
        cout << "Condition is False" << endl;
    } 

}

int main()
{
    
    // Notes: If constexpr
    // In modern C++, introduced in C++17 and it allows us to do conditional programming at compile time
    // Compile Time programming is a really huge topic, it can save users time because you can do the computations at compile time 
    // and save the users from doing those computations themselves
   
    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}