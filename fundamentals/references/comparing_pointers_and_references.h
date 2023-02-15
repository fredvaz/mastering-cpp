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
    Notes:
    */
    // Declare pointer and reference

    double double_value{12.34};
    double &ref_double_value{double_value}; // Reference to double_value
    double *p_double_value{&double_value};  // Pointer to double_value

    // Reading
    cout << "double_value : " << double_value << endl;
    cout << "ref_double_value : " << ref_double_value << endl;
    cout << "p_double_value : " << p_double_value << endl;
    cout << "*p_double_value : " << *p_double_value << endl;

    // Writting through pointer
    *p_double_value = 15.44;

    cout << endl;
    cout << "double_value : " << double_value << endl;
    cout << "ref_double_value : " << ref_double_value << endl;
    cout << "p_double_value : " << p_double_value << endl;
    cout << "*p_double_value : " << *p_double_value << endl;

    // Writting through reference
    ref_double_value = 18.44;

    cout << endl;
    cout << "double_value : " << double_value << endl;
    cout << "ref_double_value : " << ref_double_value << endl;
    cout << "p_double_value : " << p_double_value << endl;
    cout << "*p_double_value : " << *p_double_value << endl;

    double some_other_double{78.45};

    // Make the reference reference something else.
    ref_double_value = some_other_double;

    cout << "Making the reference reference something else..." << endl;
    cout << endl;
    cout << "double_value : " << double_value << endl;
    cout << "ref_double_value : " << ref_double_value << endl;
    cout << "p_double_value : " << p_double_value << endl;
    cout << "*p_double_value : " << *p_double_value << endl;

    // Make the pointer point to something else
    p_double_value = &some_other_double;
    cout << "Making the pointer point somewhere else..." << endl;
    cout << endl;
    cout << "double_value : " << double_value << endl;
    cout << "ref_double_value : " << ref_double_value << endl;
    cout << "&double_value : " << &double_value << endl;
    cout << "&ref_double_value : " << &ref_double_value << endl;
    cout << "p_double_value : " << p_double_value << endl;
    cout << "*p_double_value : " << *p_double_value << endl;

    *p_double_value = 555.5;

    cout << endl;
    cout << "double_value : " << double_value << endl;
    cout << "ref_double_value : " << ref_double_value << endl;
    cout << "&double_value : " << &double_value << endl;
    cout << "&ref_double_value : " << &ref_double_value << endl;
    cout << "p_double_value : " << p_double_value << endl;
    cout << "*p_double_value : " << *p_double_value << endl;
}
#endif