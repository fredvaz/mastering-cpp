/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <bitset>

int main(){
    
    // Notes:
    // if data is lost as a result of you shifting bit left (<<) or right (>>)
    // you can't get the data back just doing the reverse operation.
    // you've just lost the data permanently

    // Bit shifting is only supported for integral types like int, char

    // Shifting right divides by 2^n
    // Shifting left multiplies by 2^n
    // This rule breaks if you throw off 1's either to right ir the left

    unsigned short int value {0xff0u};

    std::cout << "Size of short int " << sizeof(short int) << std::endl; // 16 bits
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;

    //auto val = (value >> 1); // The compiler is doing a implicit cast to a int
    
    // Shift left by one bit 
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;

    // Shift left by one bit 
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;

    // Shift left by one bit 
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;

    // Shift left by one bit 
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;

    // Shift left by one bit 
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;


    // Shift right by one bit --------------------------
    value = static_cast<unsigned short int>(value >> 1);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;


    // Shift right by multiple bits --------------------
    // Shift right by four bits / divided by 2^4 = 16 
    value = static_cast<unsigned short int>(value >> 4);
    std::cout << "value: " << std::bitset<16>(value) << ", dec: " << value << std::endl;


    // We must use the ( ) in order to the compiler not be cofused with the operator >>
    std::cout << "value: " << (value >> 1) << std::endl;
    

    return 0;
}