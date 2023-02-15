/*

The C++20 Masterclass: Non type template parameters

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

            EXAMPLE: Non type template parameters
*/

template <int threshold, typename T>
bool is_valid(T collection[], size_t size)
{
    T sum{}; // 0
    for (size_t i{0}; i < size; ++i)
    {
        sum += collection[i];
    }
    return (sum > threshold) ? true : false;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    double temperatures[]{10.0, 20.0, 30.0, 40.0, 50.0, 100.0};

    auto result = is_valid<500, double>(temperatures, size(temperatures));
    cout << boolalpha;
    cout << "result: " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Version making a little more sense for the task
*/

// Version making a little more sense for the task
template <typename T>
bool is_valid(T collection[], int threshold, size_t size)
{
    T sum{};
    for (size_t i{0}; i < size; ++i)
    {
        sum += collection[i];
    }
    return (sum > threshold) ? true : false;
}

//Support for C++20 NTTP is still not fully supported
//Function below doesn't compile on gcc10 but does on gcc11 with wandbox
//Wandbox : https://wandbox.org/permlink/FqJzUV00c5MC2ie2
/*
template <typename T, double coeff>
T process (T a, T b){
    return a*b-coeff;
}
*/

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    double temperatures[]{10.0, 20.0, 30.0, 40.0, 50.0, 100.0};

    auto result = is_valid<double>(temperatures, 200, size(temperatures));
    cout << boolalpha;
    cout << "result: " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_2 END

//