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

//#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

int main(int argc, char **argv)
{
    /*
    General Notes: char **argv <=> char *argv[]
    */
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;
    
    cout << "We have " << argc << " parameters in our program" << std::endl;

    for (size_t i{0}; i < argc; ++i)
    {
        cout << "parameter [" << i << "] :" << argv[i] << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END