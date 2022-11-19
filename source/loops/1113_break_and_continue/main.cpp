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
    const size_t COUNT{10};

    for (size_t i{0}; i < COUNT; i++)
    {

        if (i == 4)
            continue; // Jumps out one iteration of the loop

        if (i == 8)
            break; // Breaks out of the loop

        cout << "i : " << i << endl;
    }
    cout << "Loop Done!" << endl;
}

int main()
{
    /*
    General Notes:
        Test1
    */

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}