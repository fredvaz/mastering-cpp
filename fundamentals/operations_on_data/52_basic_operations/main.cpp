/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Notes:
    // We still can use the { } to inialize the variables with opoerations inside

    int number1 {31};
    int number2 {10};

    // Addition
    int sum {number1 + number2};
    int other_sum = number1 + number2;

    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "Other sum is: " << other_sum << std::endl;

    // Addition
    int diff {number1 - number2};
    int other_diff = number1 - number2;

    std::cout << "The diff is: " << diff << std::endl;
    std::cout << "Other diff is: " << other_diff << std::endl;

    // Multiplication
    int product {number1 * number2};
    int other_product = number1 * number2;

    std::cout << "The product is: " << product << std::endl;
    std::cout << "Other product is: " << other_product << std::endl;

    // Integer Division -> give us the integer part
    // 31/10 = 3 -> 10 fits 3 times in 30
    int quotient {number1 / number2};
    int other_quotient = number1 / number2;

    std::cout << "The quotient is: " << quotient << std::endl;
    std::cout << "Other quotient is: " << other_quotient << std::endl;

    // Modulus Operation -> give us the fractional part / remainder of the division
    // 31/10 = 3 -> 10 fits 3 times in 30
    int modulus {number1 % number2};
    int other_modulus = number1 % number2;

    std::cout << "The modulus is: " << modulus << std::endl;
    std::cout << "Other modulus is: " << other_modulus << std::endl;


    return 0;
}