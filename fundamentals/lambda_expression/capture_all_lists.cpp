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

            EXAMPLE: Capture all parameters inside the lambda function by value using the = operator
*/

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int c{42};

    auto func = [=]()
    {
        std::cout << "Inner value : " << c << std::endl;
        // Note: values captured by value can't be modified in the body of the lambda function by default.
    };

    for (size_t i{0}; i < 5; i++)
    {
        std::cout << "Outer value : " << c << std::endl;
        func();
        c++;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Capturing all parameters by reference using the & operator
*/

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    int c{42};
    int d{5};

    auto func = [&]()
    {
        std::cout << "Inner value (c) : " << c << std::endl;
        std::cout << "Inner value (d) : " << d << std::endl;
    };

    for (size_t i{0}; i < 5; i++)
    {
        std::cout << "Outer value (c) : " << c << std::endl;
        func();
        c++;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END