/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Notes:
    // const: a variable you can initialize, but can't change afterwards
    
    // the const qualifier applies to the variable name you are uing to manipulate 
    // data in memory. It doens'tapply to the 0's and 1's in memory themselves
    // the protection is not at the memory level, it is at the C++ program/Compiler
    // level or the name  that you use to manipulate your variables 
    
    // guarantee that the variale will never change throughout the lifetime of your
    // program

    const int age {34};
    const float height {1.67f};

    //age = 55;              // Can't modify, generates a comp*iler error
    //height = 1.8f;

    int years {3 * age}; // we still cn use our constants in computations

    std::cout << "age: " << age << std::endl;


    return 0;
}