/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>

using namespace std;

void test1()
{
    /*
    Notes: Infinite Loops
        The Test condition is not set or is set to True forever

        They sometimes occur by error an may cause your program to do crazy things
        Sometimes they are just part of your design especially when you don't now hoe many time your loop will execute
        when that's determined by the user for example
    */

    for (size_t i{0};; i++)
    {
        cout << i << ": Just looping around!" << endl;
    }

    // Example with a While Loop
    while (true)
    {
        cout << "Just looping around!" << endl;
    }

    // Example wiht a Do While Loop
    do
    {
        cout << "Just looping around!" << endl;
    } while (true);
}

int main()
{
    /*
    General Notes: Infinite Loops
        Loops that run indefinitly and never stop
    */

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}