/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


void test1() 
{
    /*
    Notes: Range based for loop
        Test1
    */
  
   int bag_of_values [] {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};

   // The variable value will be assigned a value from the values array on each iteration 
   for (int value : bag_of_values)
   {
        // Variable value holds a copy of the current iteration in the whole bag
        cout << "value: " << value << endl;
   }

    /* Old way
    for(size_t i {0} ; i < 10 ; ++i){
        std::cout << "value : " << bag_of_values[i] << std::endl;
    }
    */

}

void test2() 
{
    /*
    Notes: Range based for loop
        Test2
    */
   
   // Specify the collection in place
   for (int value : {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10})
   {
        // Variable value holds a copy of the current iteration in the whole bag
        cout << "value: " << value << endl;
   }

}

int main()
{
    /*
    General Notes: Range based for loop
        Test1
    */
   
    cout << "\nTest 1:" << endl;
    test1();

    cout << "\nTest 2:" << endl;
    test2();

    cout << endl;
    return 0;
}