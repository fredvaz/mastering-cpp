/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


int a{35};
int b{20};

/*  */
void test1() 
{
    cout << "Using regular if" << endl;

    int max_value{0};

    if (a > b)
    {
        max_value = a;
    }else
    {
        max_value = b;
    }
    
    cout << "max: " << max_value << endl;

}

/*  */
void test2() 
{
    cout << "Ternary Operator" << endl;
    
    int max_value{0};

    max_value = (a > b) ? a : b;

    cout << "max: " << max_value << endl;

}

int main()
{
    
    // Notes: Ternary Operator
    // This is an alternative way to do Tests with the If statement
    // result = (condition) ? option1 : option2; 
    
    cout << "\nTest 1:" << endl;
    test1();

    cout << "\nTest 2:" << endl;
    test2();


    cout << endl;
    return 0;
}