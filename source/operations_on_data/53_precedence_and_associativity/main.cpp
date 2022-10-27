/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Notes:
    // a + b * c - d/e - f + g
    // Priorities: Multiplication -> Division -> Addition and Subtraction

    // Precedence: which operation to do first
    // Associativity: which direction or which order

    // It is better to make the intent in your code as clear as possible by clearly
    // using the ( ) to inficate which operations you want done first 

    int a {6};
    int b {3};
    int c {8};
    int d {9};
    int e {3};
    int f {2};
    int g {5};
        
    int result = a + b * c -d/e -f + g; //  6 +  24  -   3 - 2 + 5
        std::cout << "result : " << result << std::endl;

    result = a/b*c +d - e + f;  //   16 + 9 - 3 + 2
    std::cout << "result : " << result << std::endl;

    result = (a + b) * c -d/e -f + g; // 72-3-2+5
    std::cout << "result () : " << result << std::endl;


    return 0;
}