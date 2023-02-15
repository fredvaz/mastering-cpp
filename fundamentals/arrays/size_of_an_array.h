/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/
#include <iostream>

#define Test2

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Size of an Array at runtime
           std::size() introduced in C++17
           Before C++17 the array size was get with sizeof()
           Or simple we can use a range based for loop (auto values : var)
    */

    int scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int count{size(scores)}; // std::size() in C++17

    for (size_t i{0}; i < count; i++)
    {
        cout << "scores[" << i << "] : " << scores[i] << endl;
    }
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Before C++17
    */

    int scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int count{sizeof(scores)/sizeof(scores[0])};

    cout << "sizeof(scores) : " << sizeof(scores) << endl;
    cout << "sizeof(scores([0] : " << sizeof(scores[0]) << endl;
    cout << "count : " << count << endl; 

    for (size_t i{0}; i < count; i++)
    {
        cout << "scores[" << i << "] : " << scores[i] << endl;
    }

}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: Before C++17
    */

    int scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (auto values : scores)
    {
        cout << "value : " << values << endl;
    }

}
#endif