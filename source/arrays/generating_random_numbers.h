/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>
#include <ctime>

#define Test3

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Generating random numbers
    */

    // Range between [0 ~ RAND_MAX]
    int random_num = rand(); //
    cout << "RAND_MAX : " << RAND_MAX << endl;

    for (size_t i{0}; i < 5; i++)
    {
        random_num = rand(); //
        cout << "number " << i << " : " << random_num << endl;
    }
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */

    // Range [0~10] : % with % operand controls the upper bound
    int random_num = rand() % 11; // Will be between [0~10]
   
    for (size_t i{0}; i < 5; i++)
    {
        random_num = rand() % 11; //
        cout << "number " << i << " : " << random_num << endl;
    }

    // Range [1~15]
    random_num = (rand() % 15) + 1;
    
    for (size_t i{0}; i < 5; i++)
    {
        random_num = (rand() % 15) + 1; //
        cout << "number " << i << " : " << random_num << endl;
    }
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes:
    */
    // Limitation: std::rand() give us the same sequence each time the program runs
    // This is related to the seed that std::rand() is using to generate its numbers

    time(0);        // Time since January 1st, 1970 atr 00:00:00 AM
    srand(time(0)); // Seed : it will generate random numbers across the time

    // Range [1~15]
    int random_num = (rand() % 15) + 1;
    
    for (size_t i{0}; i < 5; i++)
    {
        random_num = (rand() % 15) + 1; //
        cout << "number " << i << " : " << random_num << endl;
    }
}
#endif