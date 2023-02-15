/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


void test1() 
{
    /*
    Notes: Range based for loop with initializer 
        It was added in C++ 20
    */
   
   for (double multiplier{4}; auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
   {
        cout << "result : " << (i*multiplier) << endl;
   }
   
   // Declaring the for loop with a initializer allows to create another variable with the same name
   double multiplier{64};

   cout << "multiplier : " << multiplier << endl;

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