/*

The C++20 Masterclass: Returning Array element index by Pointer

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

            EXAMPLE: Returning Array element index by Pointer
*/

// Returning a Pointer pointing to the address of the Array 
// Note: has to be a const pointer since the address of the Array does not change
const double *find_max_address(const double scores[], size_t count)
{

    size_t max_index{};
    double max{};

    for (size_t i{0}; i < count; ++i)
    {
        if (scores[i] > max)
        {
            max = scores[i];
            max_index = i;
        }
    }
    return &scores[max_index];
}


int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    // double array[]{1.0, 2.0, 3.0, 45.0, 5.0, 6.0, 7.0, 8.0, 79.0, 10.0};
    double array[]{-3.0,-2.0,-5.0};

    const double *p_max = find_max_address(array, std::size(array));
    
    std::cout << "max : " << *p_max << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}


#endif // EXAMPLE_END

//