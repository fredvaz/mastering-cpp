/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{
    int condition{1};

    int my_var{4};

    switch (int data{7}; condition) // The Variable data is going to be visible across all the cases
    {
        int x;
        //int x_test{9}; // Code here is never going to run because in a swithc case we're going to run the code that lives inside the cases below
    case 0:
    //{ // If used the curly braces here the variable it will be not visible for the others cases
        int y;
        //int y{5}; // Not possible to initialize variables shared between cases
        x = 6;
        x++;
        //z = 6; // Not possible to use the z variable before it's declaration point below in case 1.
        cout << "x: " << x << endl;
        cout << "Statement1" << endl;
        cout << "Statement2" << endl;
        break;
    //} main.cpp
    case 1:
        int z;
        my_var++;
        y = 5;
        cout << "y: " << y << endl;
        cout << "Statement3" << endl;
        cout << "Statement4" << endl;
        break;
    
    default:
        int u{5}; // It's possible to be initialized because is not initiated in any case 
        z = 10;
        cout << "Statement5" << endl;
        cout << "Statement6" << endl;
        break;
    }
    cout << "Moving on..." << endl;

}

int main()
{
    
    // Notes: Switch Scope
    // The main message here is that out switch is, one, a giant scope
    // and everything inside is going to be basically in the same scope
    // The one thing you have to be careful about it not to try to use a variable before it's declaration point
    
    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}