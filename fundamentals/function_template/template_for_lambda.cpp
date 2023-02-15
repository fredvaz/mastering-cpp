/*

The C++20 Masterclass: Named Template Parameters for Lambdas

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    auto func = []<typename T, typename P>(T a, P b)
    {
        return a + b;
    };

    char a{'c'};
    int b{63};

    auto result = func(a, b);
    cout << "result: " << result << endl;
    cout << "sizeof(result): " << sizeof(result) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END