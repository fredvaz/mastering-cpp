/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test4

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Multi Dimensional Arrays (aka Matrix)
    */

    // 2D Array - 3 x 4 : 12 ints
    const size_t lns = 3;
    const size_t cols = 4;

    int packages[lns][cols]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Read data from a 2D Array
    for (size_t i = 0; i < lns; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << packages[i][j] << " ";
        }
        cout << endl;
    }
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Use std::size to query the size of array dimensions
    */

    // 2D Array - Auto x 4
    const size_t cols = 4;

    int packages[][cols]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    // Read data from a 2D Array
    for (size_t i{0}; i < size(packages); i++)
    {
        for (size_t j{0}; j < size(packages[i]); j++)
        {
            cout << packages[i][j] << " ";
        }
        cout << endl;
    }
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes:
    */

    // 3D arrays are defined in the same way. We just use three sets of indexes
    //  3 lights per room, 5 rooms per house 7 houses per block

    // For 3d and really any multi dimensional array , you have to specify
    // the number of elements in []'s , only the left most is not mandatory.
    // Omitting the 5 or the 3 or both will cause a compile error.
    int house_block[][5][3]{
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}},
        {{16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30}},
        {{31, 32, 33}, {34, 35, 36}, {37, 38, 39}, {40, 41, 42}, {43, 44, 45}},
        {{46, 47, 48}, {49, 50, 51}, {52, 53, 54}, {55, 56, 57}, {58, 59, 60}},
        {{61, 62, 63}, {64, 65, 66}, {67, 68, 69}, {70, 71, 72}, {73, 74, 75}},
        {{76, 77, 78}, {79, 80, 81}, {82, 83, 84}, {85, 86, 87}, {88, 89, 90}},
        {{91, 92, 93}, {94, 95, 96}, {97, 98, 99}, {100, 101, 102}, {103, 104, 105}}};

    // Read data from a 2D Array
    for (size_t i{0}; i < size(house_block); i++)
    {
        for (size_t j{0}; j < size(house_block[i]); j++)
        {
            for (size_t k{0}; k < size(house_block[i][j]); k++)
            {
                cout << house_block[i][j][k] << " ";
            }
        }
        cout << endl;
    }
}
#endif

#ifdef Test4
void test4()
{
    /*
    Notes:
    */

    // If you put less elements than the amount specified in the declaration, the compiler
    // will automaticaly fill out those left out with 0 or '\0' is the array is of char.
    //  Change the array to int house_block [] [5] [4], and because all inner arrays have 3,
    //  elements, the fourth will be autofilled with 0.
    //  Also remove some other elements, I chose the {4,5,6} array but you can add others
    //  when recording to make this a bit fun. The left out indexes will be auto filled with
    //  zeros
    int house_block[][5][4]{
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}},
        {{16, 17, 18}, {19, 20, 21}, {22, 23, 24}, {25, 26, 27}, {28, 29, 30}},
        {{31, 32, 33}, {34, 35, 36}, {37, 38, 39}, {40, 41, 42}, {43, 44, 45}},
        {{46, 47, 48}, {49, 50, 51}, {52, 53, 54}, {55, 56, 57}, {58, 59, 60}},
        {{61, 62, 63}, {64, 65, 66}, {67, 68, 69}, {70, 71, 72}, {73, 74, 75}},
        {{76, 77, 78}, {79, 80, 81}, {82, 83, 84}, {85, 86, 87}, {88, 89, 90}},
        {{91, 92, 93}, {94, 95, 96}, {97, 98, 99}, {100, 101, 102}, {103, 104, 105}}};

    // Modify data
    house_block[0][2][1] = 1021;

    // Read data from a 2D Array
    for (size_t i{0}; i < size(house_block); i++)
    {
        for (size_t j{0}; j < size(house_block[i]); j++)
        {
            for (size_t k{0}; k < size(house_block[i][j]); k++)
            {
                cout << house_block[i][j][k] << " ";
            }
        }
        cout << endl;
    }
}
#endif
