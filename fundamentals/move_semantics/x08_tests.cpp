/*

The C++20 Masterclass Section :

General Notes:


   [REF]:

*/
#include <iostream>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE:
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    double celsius;

    std::cout << "Please enter a degree value in Celsius:" << std::endl;
    std::cin >> celsius;

    double fahrenheit = (9.0 / 5) * celsius + 32;

    std::cout << celsius << " is " << fahrenheit << " Fahrenheit" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            * EXAMPLE:
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    double length, width, height;

    std::cout << "Welcome to box calculator. Please enter type in length, width and height information:" << std::endl;
    std::cout << "length: ";
    std::cin >> length;
    std::cout << "width: ";
    std::cin >> width;
    std::cout << "height: ";
    std::cin >> height;

    double base_area = width * length;
    double volume = base_area * height;

    std::cout << "The base area is: " << base_area << std::endl;
    std::cout << "The volume is: " << volume << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//