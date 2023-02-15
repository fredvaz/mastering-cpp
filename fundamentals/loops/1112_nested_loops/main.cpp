/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <iomanip>

using namespace std;

void test1()
{
    /*
    Notes: Nested Loops
        Test1
    */

    const size_t ROWS{12};
    const size_t COLS{3};

    for (size_t row{0}; row < ROWS; row++)
    {
        for (size_t col{0}; col < COLS; col++)
        {
            cout << "( row " << setw(2) << row << ", col " << setw(2) << col << ")";
        }
        cout << endl;
    }
}

int main()
{
    /*
    General Notes: Nested Loops
        Test1
    */

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}