/*

The C++20 Masterclass Section 45: Move Semantics (C++11)

General Notes:
    A set of features that were introduced in C++11 tom it easy to use temporary variables in C++
    and avoid unnecessary copies

    So, basically the Pointer to the final data will Pointer to the Pointer of temporary data instead
    of creating a copyig the temporary data to a new memory location for the final data

   [REF]:

*/
#include <iostream>
#include "libs/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Moving temporaries around
*/

void populate_box(BoxContainer<int> &box, int modifier)
{
    for (size_t i{0}; i < 20; ++i)
    {
        box.add((i + 1) * modifier);
    }
}

BoxContainer<int> make_box(int modifier)
{
    BoxContainer<int> local_int_box(20);
    populate_box(local_int_box, modifier);
    return local_int_box;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    BoxContainer<int> box_array[2];

    for (size_t i{0}; i < 2; ++i)
    {
        box_array[i] = make_box(i + 1); //* Copy assignment operator called at each iteration
                                        //* We're copying data from the temporary and
                                        //* throwing the temporary away (with data)
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
