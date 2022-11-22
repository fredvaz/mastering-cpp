/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Attempting to access data outside the bounds of our array
    */
    int numbers[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // Read beyond bounds : Will read garbage or crash your program
    cout << "numbers[12] : " << numbers[12] << endl;

    // Write beyond bounds. The compiler allows it. But you don't own
    // the memory at index 12, so other programs may modify it and your
    // program may read bogus data at a later time. Or you can even
    // corrupt data used by other parts of your ptogram

    numbers[129] = 1000;
    cout << "numbers[129] : " << numbers[129] << endl;

    cout << "Program ending...." << endl;

}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
}
#endif