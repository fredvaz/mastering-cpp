/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Compile time error e.g. satement whiteout end with ; 
    std::cout << "Hello World!" << std::endl

    // Run time error: warning: division by zero
    int value = 7/0;
    std::cout << "Value: " << value << std::endl;

    return 0;
}