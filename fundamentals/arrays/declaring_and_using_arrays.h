/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test5

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:
    */

    // Declare an array of ints
    int scores[10]; // Junk data

    // Read data
    cout << "scores [0] : " << scores[0] << endl;
    cout << "scores [1] : " << scores[1] << endl;

    // Read with a loop
    for (size_t i{0}; i < 10; i++)
    {
        cout << "scores [" << i << "] : " << scores[i] << endl;
    }

    // Write data into an array
    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;

    // Write data int a loop
    for (size_t i{0}; i < 10; i++)
    {
        scores[i] = i * 10;
    }

    // Print the data out
    for (size_t i{0}; i < 10; i++)
    {
        cout << "scores [" << i << "] : " << scores[i] << endl;
    }
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */

    // Declare and intialize at the same time
    double salaries[5]{12.7, 7.5, 13.2, 8.1, 9.3};

    for (size_t i{0}; i < 5; i++)
    {
        cout << "salary[" << i << "] : " << salaries[i] << endl;
    }

    // If you don't initialize all the elements, those you leave out
    // are initialized to 0
    
    int families[5] {12, 7, 5};
	
	for(size_t i{0}; i < 5; ++i){
		cout << "families[" << i << "] : " << families[i] << endl;
	}

}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes:
    */

    // Omit the size of the array at declaration
    int class_sizes[]{10, 12, 15, 11, 18, 17};

    // Will print this with a range based for loop
    for (auto value : class_sizes)
    {
        cout << "value : " << value << endl;
    }
}
#endif

#ifdef Test4
void test4()
{
    /*
    Notes:
    */

   const int birds[]{10 ,12, 15, 11, 18, 17, 23, 56};
   birds[2] = 8; // The compiler generates a error because the value is declared as constant. 
                 // Therefore cannot be changed
}
#endif

#ifdef Test5
void test5()
{
   /*
   Notes:
   */

   // Sum up scores array, store result in sum
   int scores[]{2, 5, 8, 2, 5, 6, 9};
   int sum{0};

   for (int element : scores)
   {
        sum += element;
   }
   cout << "Score sum : " << sum << endl;
}
#endif