/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>

using namespace std;

void test1()
{
    /*
    Notes:
        Test1
    */

    const size_t COUNT{5};

    cout << "Incrementing for loop : " << endl;
    for (size_t i{}; i < COUNT; ++i)
    {
        cout << "i  : " << i << endl;
    }

    cout << endl;
    cout << "Decrementing for loop : " << endl;

    for (size_t i{COUNT}; i > 0; --i)
    {
        cout << "i : " << i << endl;
    }
}

void test2()
{
    /*
    Notes: Underflow and infinite loop
        The increment value it will go to negative values, bur the size_t i var is a unsigned int
        Therefore it will generate a underflow and the i var it will changed to a huge number

        The program will run indefinitely. The reason is that when the loop hits 0 and we --i in hope to get a -1
        and stop the loop, the value in our unsigned char will underflow and be the max value we can store in a char,
        namely 255. It will be >=0 and the loop will have no reason to stop! It will keep running indefinitely printing 
        values between 0 and 255.
    */

    const size_t COUNT{5};

    // Infinite loop
    // Decrementing do while
    cout << endl;
    cout << "Decrementing do while" << endl;
    unsigned int i = COUNT;

    do
    {
        cout << "i : " << i << endl;
        --i;
    } while (i >= 0);
}

int main()
{
    /*
    General Notes: Decrementing Loops
        Test1
    */

    cout << "\nTest 1:" << endl;
    //test1();

    cout << "\nTest 2:" << endl;
    test2();

    cout << endl;
    return 0;
}