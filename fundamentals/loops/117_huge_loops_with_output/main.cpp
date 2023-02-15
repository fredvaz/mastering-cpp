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

   size_t COUNT{1000};

   for (size_t i{0}; i < COUNT; i++)
   {
        cout << "i: " << i << endl; // Spends a bunch of runtime in computations
   }
   cout << "Done!" << endl;

}

int main()
{
    /*
    General Notes: 
        Only to make the point that cout consumes a lot of time that can delay our design intent of the function/software
    */
    

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}