/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Notes:
    // A char is the size of 1 byte / 8 bits
    // 1 byte : 256 possible values -> each matched to some character
    // ASCII Table
    // It is possible to assign a valid ASCII code to a char variable, and the 
    // corresponding character will be stored in. You can choose to interpret
    // that either as a character or a regular integral value

    char value = 65; // ASCII character code for 'A'
    std::cout << "value : " << value << std::endl; // print the char 'A'
    // Take the valye and interpret that as an interger
    std::cout << "value(int) : " << static_cast<int>(value) << std::endl;

    char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};
    char character6 = 'w';
    
    std::cout << character1 << std::endl;
    std::cout << character2 << std::endl;
    std::cout << character3 << std::endl;
    std::cout << character4 << std::endl;
    std::cout << character5 << std::endl;

    //One byte in memory : 2^8 = 256 different values (0 ~ 255)
    std::cout << std::endl;


    return 0;
}