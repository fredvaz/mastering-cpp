/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>

int main()
{

    // Notes:
    // A boolean is the size of 1 byte / 8 bits
    // A byte can store 256 different values
    // Using it just to cover two states (true/false) is wasteful, especially for
    // devices width hard memory constrains (like embedded devices)
    // There are techinques to pack even more data into a byte. We'll learn
    // more about these in a few upcomming chapters

    bool red_light{true};
    bool green_light{false};

    if (red_light == true)
    {
        std::cout << "Stop!" << std::endl;
    }
    else
    {
        std::cout << "Gp through!" << std::endl;
    }

    if (green_light)
    {
        std::cout << "The light is green!" << std::endl;
    }
    else
    {
        std::cout << "The light is NOT green!" << std::endl;
    }

    // sizeof()
    std::cout << "sizeof(bool) : " << sizeof(bool) << std::endl;

    // Printing out a bool
    // 1 -->> true
    // 0 -->> false
    std::cout << std::endl;
    std::cout << "red_light : " << red_light << std::endl;
    std::cout << "green_light : " << green_light << std::endl;

    // Forces the output format true/false
    std::cout << std::boolalpha;
    std::cout << "red_light : " << red_light << std::endl;
    std::cout << "green_light : " << green_light << std::endl;


    return 0;
}