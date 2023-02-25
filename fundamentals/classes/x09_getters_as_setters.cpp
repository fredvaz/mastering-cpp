/*

The C++20 Masterclass: Getters that work as Getters

General Notes:


   [REF]:

*/
#include <iostream>
#include "libs/dog.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Getters that work as Getters
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // Using Non-const Object
    Dog dog1("Fluffy", "Shepherd", 2);

    dog1.print_info();
    std::cout << "dog name 1: " << dog1.name() << std::endl; // Getter

    //* Modify the object name using the Getter as a Setter
    dog1.name() = "Rex";
    dog1.print_info();

    // Using Const Object
    const Dog dog2("Max", "Shepherd", 2);

    dog2.print_info();
    std::cout << "dog name 2: " << dog2.name() << std::endl; // Getter const overload will be called

    // dog1.name() = "Rex"; // Compiler error: The object is Const therefore is not allowed to modify it

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
