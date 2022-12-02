/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

double max(double *numbers, size_t count)
{
    cout << "doubles overload called" << endl;
    double maximum{0};

    for (size_t i{0}; i < count; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }
    return maximum;
}

int max(int *numbers, size_t count)
{
    cout << "ints overload called" << endl;
    int maximum{0};

    for (size_t i{0}; i < count; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }
    return maximum;
}
// The following funcstion are the samething as the one above, because int numbers[], which is the address for array index 0, is equal to pointer int *numbers 
// int max(int numbers[], size_t count)
// {
//     // Test
//     cout << "ints numbers[] overload called" << endl;
//     return 0;
// }

// Here we are just defining the size of the array set to 10 - It will generate a Compiler Error
// int max(int numbers[10], size_t count)
// {
//     // Test
//     cout << "ints numbers[10] overload called" << endl;
//     return 0;
// }

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    double doubles[]{10.0, 20.0, 12.3};
    int ints[]{1, 2, 5, 2, 8, 4};

    auto result = max(doubles, size(doubles));

    cout << "result: " << result << endl;

    auto result1 = max(ints, size(ints));

    cout << "result1: " << result1 << endl;
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