/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test3

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Array of Characters
           One cool ting is we can print them to the console directly whithout a for loop
    */

    char message[]{'H', 'e', 'l', 'l', 'o'};

    // Print out the array thtough looping
    cout << "message : ";

    for (auto c : message)
    {
        cout << c;
    }
    cout << endl;

    // Change characters in our array
    message[1] = 'a'; 

    // Print out the array through a for loop
    cout << "message : "; 
    for (auto c : message)
    {
        cout << c;
    }
    cout << endl;

}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
    char message[]{'H', 'e', 'l', 'l', 'o'};
    // But this way we will get some garbage because we don't have the null terminal '\0', it's called as C-String
    cout << "message : "<< message << endl;

    // C-String, because it comes from the C languange
    char message1[]{'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "message : "<< message1 << endl;
    cout << "sizeof(message1) : " << sizeof(message1) << endl;

    // The other way is to initialize the array size
    char message2[6]{'H', 'e', 'l', 'l', 'o'};
    cout << "message : "<< message2 << endl;
    cout << "sizeof(message2) : " << sizeof(message2) << endl;
    
    char message3[]{'H','e','l','l','o'}; // This is not a c string ,
										  //as there is not null character
    cout << "message3 : " << message3 << endl;
    cout << "sizeof(message3) : " << sizeof(message3) << endl;

}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes:
    */

    // String literal
    char message4[]{"Hello"};
    cout << "message4 : " << message4 << endl;
    cout << "sizeof(message4) : " << sizeof(message4) << endl;

    // Can't safely print out arrays other than those of characters
    int numbers[]{1, 2, 3, 4, 5};
    cout << "numbers :  " << numbers << endl; // It will give us the first postion of the array in the memory address

}
#endif