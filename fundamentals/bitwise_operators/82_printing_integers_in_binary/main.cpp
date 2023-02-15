/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <bitset>       // To prin data in binary

int main(){
    
    // Notes:
    //
    
    unsigned short int data {15};

    std::cout << "data (dec): " << std::showbase << std::dec << data << std::endl;
    std::cout << "data (oct): " << std::showbase << std::oct << data << std::endl;
    std::cout << "data (hex): " << std::showbase << std::hex << data << std::endl;
    std::cout << "data (bin): " << std::bitset<16>(data) << std::endl;

    return 0;
}