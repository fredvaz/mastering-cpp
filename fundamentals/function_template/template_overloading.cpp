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

            EXAMPLE: 
*/

// (3)Function template
template <typename T>
T maximum(T a, T b)
{
    cout << "Template overload called(T) " << endl;
    return (a > b) ? a : b;
}

// (1) A raw overload will take precedence over any template instance
// if const char* is passed to maximum
const char *maximum(const char *a, const char *b)
{
    cout << "Raw overload called" << endl;
    return (strcmp(a, b) > 0) ? a : b;
}

// (2) Overload through templates. Will take precedence over raw T
// if a pointer is passed to maximum
template <typename T>
T *maximum(T *a, T *b)
{
    cout << "Template overload called (T*) " << endl;
    return (*a > *b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    const char *g{"wild"};
    const char *h{"animal"};

    const char *result = maximum(g, h);
    cout << "result: " << result << endl;

    int a{810};
    int b{23};

    auto result2 = maximum(&a, &b);
    cout << "result: " << *result2 << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//