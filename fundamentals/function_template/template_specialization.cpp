/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <cstring>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Template specialization
*/

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

template <> // Template specialization
const char *maximum<const char *>(const char *a, const char *b)
{
    return (strcmp(a, b) > 0) ? a : b; 
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    string e{"hello"};
    string f{"world"};

    auto max_int = maximum(a, b);    // int type deduced
    auto max_double = maximum(c, d); // double type deduced
    auto max_str = maximum(e, f);    // string type deduced

    cout << "max_int: " << max_int << endl;
    cout << "max_double: " << max_double << endl;
    cout << "max_str: " << max_str << endl;

    const char *g{"wild"};
    const char *h{"animal"};

    // This won't do what you would expect : BEWARE! It will compare the memory address
    const char *result = maximum(g, h);

    cout << "max(const char*): " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//