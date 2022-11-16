/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


void test1() 
{
    /*
    Notes: Do While Loop
        The special thing about a do while loop is that it is goinhg to run first and then do the test condition 
    */

   size_t i{0};
   size_t COUNT{10};

   do
   {
        cout << i << ": I Love C++!" << endl;
        i++;
        
   } while (i < COUNT);
   

}

int main()
{
    /*
    General Notes: Do While Loop
        Runs the body then checks the condition
    */
    
    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}