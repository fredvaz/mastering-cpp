/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>

int addNumber(int first_param, int second_param){

    int result = first_param + second_param;

    return result;
}

int main(){
    
    int first_number {3}; // Statement
    int second_number {7}; 

    std::cout << "First number: " << first_number << std::endl;
    std::cout << "Second number: " << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum: " << sum << std::endl; // 20

    sum = addNumber(25, 7);
    std::cout << "Sum: " << sum << std::endl; // 32

    std::cout << "Sum: " << addNumber(3, 40) << std::endl; // 43

    return 0;
}