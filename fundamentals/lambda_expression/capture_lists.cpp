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

            EXAMPLE: Capture lists
*/

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    double a{10};
    double b{20};

    auto func = [a, b]()
    {
        cout << "a + b : " << a + b << endl;
    };
    func();

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Capturing by value : what we have in the lambda function is a copy
*/

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    double c{42};

    auto func = [c]()
    {
        cout << "Inner value : " << c << " | &inner : " << &c << endl;
    };
    func();

    for (size_t i{0}; i < 5; i++)
    {
        cout << "Outer value : " << c << " | &outer : " << &c << endl;
        func();
        c++;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_3

            EXAMPLE: Capturing by reference : working on the original outside value
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

    double c{42};

    // Adding a & to pass the variable by reference
    auto func = [&c]()
    {
        cout << "Inner value : " << c << " | &inner : " << &c << endl;
    };
    func();

    for (size_t i{0}; i < 5; i++)
    {
        cout << "Outer value : " << c << " | &outer : " << &c << endl;
        func();
        c++;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END