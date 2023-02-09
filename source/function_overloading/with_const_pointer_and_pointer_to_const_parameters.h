/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

int max(int *a, int *b)
{
    cout << "max with int* called" << endl;
    return (*a > *b) ? *a : *b;
}

// This is a valid oveload of the above function
int max(const int *a, const int *b)
{
    cout << "max with const int* called" << endl;
    return (*a > *b) ? *a : *b;
}

// int min(const int *a, const int *b)
// {
//     return (*a < *b) ? *a : *b;
// }

// This is a invalid overload of the above function
// The compiler will evaluate that these two functions are the same thing
int min(const int *const a, const int *const b)
{
    cout << "&a : " << &a << endl;
    cout << "&b : " << &b << endl;
    return (*a < *b) ? *a : *b;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    int a{10};
    int b{12};

    const int c{30};
    const int d{15};

    // auto result = max(&a , &b);
    auto result = max(&c, &c);

    const int *p_c{&c};
    const int *p_d{&d};

    cout << "&p_c : " << &p_c << endl;
    cout << "&p_d : " << &p_d << endl;

    auto result1 = min(p_c, p_d);
}
#endif