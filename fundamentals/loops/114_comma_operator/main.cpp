/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


void test1() 
{
    /*
    Notes:
        Two or more expressions into a single expression 
        Where the value of the opration is tte value of it right operand 
        This Comma Operator is used also in the For Loop Multiple Declarations
    */

    int increment{5};
    int number1{10};
    int number2{20};
    int number3{25};

    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);

    cout << "number 1: " << number1 << endl;
    cout << "number 2: " << number2 << endl;
    cout << "number 3: " << number3 << endl;
    cout << "result: " << result << endl;

}

int main()
{
    // General Notes: Comma Operator
    // Tow or more expressions into a single expression 
    // Where the value of the opration is tte value of it right operand 
    // This Comma Operator is used also in the For Loop Multiple Declarations
    

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}