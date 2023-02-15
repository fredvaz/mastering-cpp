/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

/*
template <typename T, typename P>
decltype(auto) func_add( T a, P b){
    return a + b;
}
*/

auto func_add(auto a, auto b)
{
    return a + b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int a{7};
    double b{78.2};

    auto result = func_add(a, b);
    cout << "result : " << result << endl;
    cout << "sizeof(result) : " << sizeof(result) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END