/*

The C++20 Masterclass: Pass Multidimensional array as function parameter

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

// Pass Multidimensional array as function parameter 
double sum(const double array[][3], size_t size);
double sum_3d(const double array[][3][2], size_t size);

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    double weights[][3]{
        {
            10.0,
            20.0,
            30.0,
        },
        {40.0, 50.0, 60.0},
        {70.0, 80.0, 90.0},
        {100.0, 110.0, 120.0}};
    double weights_3d[][3][2]{
        {
            {10, 20},
            {30, 40},
            {50, 60},
        },
        {
            {70, 80},
            {90, 100},
            {110, 120},
        }};

    double result = sum(weights, size(weights));
    cout << "2d array sum : " << result << endl;

    result = sum_3d(weights_3d, size(weights_3d));
    cout << "3d array sum : " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

// Pass Multidimensional array as function parameter 
double sum(const double array[][3], size_t size)
{
    double sum{};
    for (size_t i{}; i < size; ++i) // Loop through rows
    {
        for (size_t j{}; j < 3; ++j) // Loop through elements in a row
        {
            sum += array[i][j]; // Array access notation
            //sum += *( *(array + i) +j);	// Pointer arithmetic notation.
            //Confusing . Prefer array noation
        }
    }
    return sum;
}

double sum_3d(const double array[][3][2], size_t size)
{

    double sum{};
    for (size_t i{}; i < size; ++i) // Loop through rows
    {
        for (size_t j{}; j < 3; ++j) // Loop through elements in a row
        {
            for (size_t k{}; k < 2; ++k)
            {
                sum += array[i][j][k];
                //sum += *(*(*(array + i) + j)+k);
            }
        }
    }
    return sum;
}