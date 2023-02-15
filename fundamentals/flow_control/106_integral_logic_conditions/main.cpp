/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{

   int condition {-1}; 

   // Simple cast to show the True/False boolean value on the Terminal
   bool bool_condition = condition;
   cout << boolalpha;

   if (condition)
   {
        cout << "We are a " << bool_condition << " in our variable" << endl; // Runs when different from 0 (negative/postive values)
   }else
   {
        cout << "We have " << bool_condition << " in our variable" << endl; // Runs when Zero
   }

}


int main() 
{
    
    // Notes: Integral Logic Conditions
    // To use Integers as Boolenas conditions
    // True: Any number different than 0, or expression evaluating to something other than 0
    // False: Any number equal to 0, or expression evaluating to 0
    // Thhe compiler allows X and some developers noticed this in the past started to use this clever trick

    cout << "\nTest 1:" << endl;
    test1();


    return 0;
}