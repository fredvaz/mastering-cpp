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
    size_t i{0};

    while (i < COUNT)
    {
        cout << i << " : I love C++!" << endl;

        i++;
    }
    cout << "Loop Done!" << endl;

}

int main()
{
    /*
    General Notes: While Loop
        Test1
    */
    
    
    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}