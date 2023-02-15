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
    Notes: References
           It's a way you can set up alias for your variables and have other 
           variable names you can go through to modify that same variable
           in static way in your code for life, whenever the pointers can be life dynamic
    */

    int int_data {33};
    double double_data{55};

    // References : In C++ there is no syntax to change what a reference is referencing once
    // it's already declared and initialized
    int &ref_int_data{int_data};
    double &ref_double_data{double_data};

    // Print stuff out
    cout << "int_data : " << int_data << endl;
    cout << "&int_data : " << &int_data << endl;
    cout << "double_data : " << double_data << endl;
    cout << "&double_data : " << &double_data << endl;
    cout << "=======================" << endl;
    cout << "ref_int_data : " << ref_int_data << endl;
    cout << "&ref_int_data : " << &ref_int_data << endl;
    cout << "ref_double_data : " << ref_double_data << endl;
    cout << "&ref_double_data : " << &ref_double_data << endl;
    cout << "=======================" << endl;
    // So, waht is the main difference between a Reference and a Pointer?
    // References it can allow you to passa data arround much easily

    int_data = 111;
    double_data = 67.2;

    // Print stuff out
    cout << "int_data : " << int_data << endl;
    cout << "&int_data : " << &int_data << endl;
    cout << "double_data : " << double_data << endl;
    cout << "&double_data : " << &double_data << endl;
    cout << "=======================" << endl;
    cout << "ref_int_data : " << ref_int_data << endl;
    cout << "&ref_int_data : " << &ref_int_data << endl;
    cout << "ref_double_data : " << ref_double_data << endl;
    cout << "&ref_double_data : " << &ref_double_data << endl;
    // In this case the References it will pick up the data changed in the variables

    // And when we change the References the data will be changed also in the main variables
    // Because we changing the same data in-memory location
    ref_int_data = 1012;
    ref_double_data = 1000.45;

    // Print stuff out
    cout << "int_data : " << int_data << endl;
    cout << "&int_data : " << &int_data << endl;
    cout << "double_data : " << double_data << endl;
    cout << "&double_data : " << &double_data << endl;
    cout << "=======================" << endl;
    cout << "ref_int_data : " << ref_int_data << endl;
    cout << "&ref_int_data : " << &ref_int_data << endl;
    cout << "ref_double_data : " << ref_double_data << endl;
    cout << "&ref_double_data : " << &ref_double_data << endl;

}
#endif