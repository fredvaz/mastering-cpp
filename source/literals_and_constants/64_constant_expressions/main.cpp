/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Notes:
    // constant expressions: Checks at compile time

    constexpr int SOME_LIB_MAJOR_VERSION {1234};

    constexpr int eye_count {2};

    constexpr double PI {3.14};

    //eye_count = 4; // compiler error

    std::cout << "eye count: " << eye_count << std::endl;
    std::cout << "PI: " << PI << std::endl;

    // Checks at compile time 
    static_assert(SOME_LIB_MAJOR_VERSION == 123);
    
    
    return 0;
}