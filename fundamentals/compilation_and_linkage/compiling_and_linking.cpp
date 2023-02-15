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

//

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    double result = 10.0;
    //
    cout << "Hello World!" << endl;
    // g++ -o main.exe .\compiling_and_linking\compiling_and_linking.cpp

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//