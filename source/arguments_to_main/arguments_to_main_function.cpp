/*

The C++20 Masterclass: Arguments/parameters to the main() function

General Notes:

   [REF]:
   
*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//

//#define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

int main(int argc, char **argv)
{
    /*
    General Notes: char **argv <=> char *argv[]
    */
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;
    
    cout << "We have " << argc << " parameters in our program" << std::endl;

    for (size_t i{0}; i < argc; ++i)
    {
        cout << "parameter [" << i << "] :" << argv[i] << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END