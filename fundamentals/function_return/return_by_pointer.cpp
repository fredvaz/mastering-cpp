/*

The C++20 Masterclass:

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

int *max_return_pointer(int *a, int *b)
{
    if (*a > *b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int x{56};
    int y{45};
    int *p_max = max_return_pointer(&x, &y);
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;

    ++(*p_max);
    std::cout << "-----" << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: 
*/

int *sum(int *a, int *b)
{
    int result = *a + *b;
    return &result; // Pointer to local variable returned, the program it will crash
                    // Compiler warning: address of local variable 'result' returned
}

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    int x{56};
    int y{45};
    int *p_sum = sum(&x, &y);
    std::cout << *p_sum << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_3

            EXAMPLE: 
*/

int *max_input_by_value(int a, int b)
{
    if (a > b)
    {
        return &a; // Pointer to local variable returned, the program it will crash
    }
    else
    {
        return &b; // Pointer to local variable returned, the program it will crash
    }
}

int main()
{
    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

    int x{56};
    int y{45};
    int *p_sum = max_input_by_value(x, y);
    std::cout << *p_sum << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//