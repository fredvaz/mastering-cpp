/*

The C++20 Masterclass: Class across mutilple files

General Notes:
        Just to use the directives #include and the pre-processor #ifndef
        The use of the Header files is recommended to the Class definitions, which the part
        of interest to use by others developers. The methods implementation is not so import
        when we only want to use the output of a Class Object from other developer as a Black Box

   [REF]: No
*/
#include <iostream>
#include "libs/cylinder.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE:
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Cylinder cylinder1(100, 10);

    std::cout << "volume : " << cylinder1.volume() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
