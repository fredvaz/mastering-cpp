/*

The C++20 Masterclass: Implicit Conversions with Pointers

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Implicit Conversions with Pointers
*/

void print_sum(int *param1, int *param2)
{
    cout << "sum : " << (*param1 + *param2) << endl;
}

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int a{3};
    int b{12};

    double c{4.5};
    double d{5.5};

    print_sum(&a, &b);
    // print_sum(&c, &d); // Compiler error: cannot convert 'double*' to 'int*'
                          // it is related to size of each variable type in the memory address
                       

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END