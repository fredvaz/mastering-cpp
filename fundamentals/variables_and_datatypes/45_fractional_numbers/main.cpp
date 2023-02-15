/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <iomanip>      // Librarie for the setprecision()


int main(){
    
    // Notes: 
    // Fractional Numbers -> Floating Point Types
    // Float precision = 7, integer + fractional part e.g., 1.234567
    // Double precision = 15

    // n(floating point) -> infinity(+/-)
    // 0.0/0.0 -> NaN

    // {1.2345667f} Remember the suffices when initializing floating point variables- otherwise the default will be double
    // Double works well in many situations, so you will se it used a lot

    // Declare and initialize the variables
    float number1 {1.12345678901234567890f};        // Precision : 7
    double number2 {1.12345678901234567890};        // Precision : 15
    long double number3  {1.12345678901234567890L};
    
    // Print out the sizes
    std::cout << "sizeof float : " << sizeof(float) << std::endl;             // 4 bytes
    std::cout << "sizeof double : " << sizeof(double) << std::endl;           // 8 bytes
    std::cout << "sizeof long double : " << sizeof(long double) << std::endl; // 16 bytes

    // Precision 
    std::cout << std::setprecision(20);                  // Control the precision from std::cout.
    std::cout << "number1 is: " << number1 << std::endl; // 7 digits
    std::cout << "number2 is: " << number2 << std::endl; // 15'ish digits
    std::cout << "number3 is: " << number3 << std::endl; // 15+ digits

    // Float problems : The precision is usually too limited
    // for a lot of applications
    //float number4 {192400023.0f};       // Error : narrowing conversion
    //double number4 {192400023.0f};      // The suffix will set as a float
    //double number4 {192400023.0};
    float number4 = 192400023.0f;         // Numbers 23 are not stored;

    std::cout << "number4 : " << number4 << std::endl;


    // Scientific notation
    // that is handy if you have really huge numbers or small numbers to represent

    std::cout << "-------------------------" << std::endl;
    
    double number5 {192400023};
    double number6 {1.92400023e8};
    double number7 {1.924e8};           // Can ommit the lower 00023
                                        // for simplicity if our application allows that.
    double number8 {0.00000000003498};
    double number9 {3.498e-11};         // multiply with 10 exp(-11)
    
    std::cout << "number5 is : " << number5 << std::endl;
    std::cout << "number6 is : " << number6 << std::endl;
    std::cout << "number7 is : " << number7 << std::endl;
    std::cout << "number8 is : " << number8 << std::endl;
    std::cout << "number9 is : " << number9 << std::endl;


    std::cout << "------------ Infinity and NaN -------------" << std::endl;

    // Infinity and Nan  
    double number10 { -5.6 };
    double number11 {};  // Initialized to 0
    double number12 {};  // Initialized to 0

    // Infinity
    double result { number10 / number11 };
        
    std::cout << number10 << "/" << number11 << "  yields " << result << std::endl;
    std::cout << result << " + " << number10 << " yields " << result + number10 << std::endl;
    
    // NaN
    result = number11 / number12;
        
    std::cout << number11 << "/" << number12 << " = " << result << std::endl;


    return 0;
}