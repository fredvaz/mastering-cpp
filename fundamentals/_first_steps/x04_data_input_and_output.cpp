/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <string>


int main(){
    
    // Printing data 
    /* 
    std::cout << "Hello C++20" << std::endl;

    int age{21};
    std::cout << "Age: " << age << std::endl;

    std::cerr << "Error message : Something is wrong" << std::endl;
    std::clog << "Log message : Something happened" << std::endl; */

    /* 
    int age_;
    std::string name;

    std::cout << "Please type your name and age: " << std::endl;
    //std::cin >> name;
    //std::cin >> age_;
    std::cin >> name >> age_;

    std::cout << "Hello " << name << " you are " << age_ << " years old!" << std::endl;
    */
    // Data with spaces
    std::string full_name;
    int age_3;

    std::cout << "Please type your name and age: " << std::endl;

    // Gets the line with spaces in the console/terminal
    std::getline(std::cin, full_name);

    std::cin >> age_3;

    std::cout << "Hello " << full_name << " you are " << age_3 << " years old!" << std::endl;

    return 0;
}