/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <cstring>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
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
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

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

#endif // TEST_CASE_1 END

//