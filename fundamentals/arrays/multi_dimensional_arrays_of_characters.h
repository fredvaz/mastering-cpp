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
    Notes: Multi Dimensional Arrays of Characters 
    */

	const size_t name_length{15};
	
    // Declaring a 2D array
    char members [][name_length] {
        {'J','o','h','n'},
        {'S','a','m','u','e','l',},
        {'R','a','s','h','i','d'},
        {'R','o','d','r','i','g','e','z'}
    };

    // Printing out like this is unsafe : may go over and print
    // outside your valid memory block
    // until a terminating null character is encountered.
    cout << "Unsafe printing of members : " << endl;
    for (size_t i{0}; i < size(members); ++i)
    {
        cout << members[i] << endl;
    }
    // Can loop around manually printing out each character
    cout << endl;
    cout << "Printing out character by character manually : " << endl;
    for (size_t i{0} ; i < size(members) ; ++i){
        
        for (size_t j{0} ; j < size(members[i]) ; ++j){
            
            cout << members[i][j] ;
        }
        cout << endl;
    }
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
    // Better : Using C-string litterals
    // Compared to initialization with charactes with in '', this
    //  is even easier to type. The entire string is a single entity
    // you can manage easily.

    const size_t name_length{15};

    // Using C-string litterals
    char members[][name_length]{
        "John",
        "Samuel",
        "Rashid",
        "Rodriguez"};

    // Printing out members1
    cout << "Printing out members1 (C-string literals) : " << endl;
    for (size_t i{0}; i < size(members); ++i)
    {
        cout << members[i] << endl;
    }
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes:
    */
    // Updating our prediction declaration in the fortune teller game
    char predictions[][90]{
        "a lot of kinds running in the backyard!",
        "a lot of empty beer bootles on your work table.",
        "you Partying too much with kids wearing weird clothes.",
        "you running away from something really scary",
        "clouds gathering in the sky and an army standing ready for war",
        "dogs running around in a deserted empty city",
        "a lot of cars stuck in a terrible traffic jam",
        "you sitting in the dark typing lots of lines of code on your dirty computer",
        "you yelling at your boss. And oh no! You get fired!",
        "you laughing your lungs out. I've never seen this before.",
        "Uhm , I don't see anything!"

    };

    cout << endl;
}
#endif