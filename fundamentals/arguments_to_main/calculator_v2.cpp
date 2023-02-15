/*

The C++20 Masterclass:

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

            EXAMPLE: Calculator v2
*/
int main(int argc, char **argv)
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    // Check the number of parameters
    if (argc != 4)
    {
        cerr << "Program can only be called with 3 arguments like: " << endl;
        cerr << "Program name a + b" << endl;
        cerr << "You called with : ";

        for (size_t i{0}; i < argc; i++)
        {
            cout << " " << argv[i];
        }
        cout << endl;
        return 0;
    }

    // Grab the operands
    double first_number{atof(argv[1])};
    double second_number{atof(argv[3])};

    if ((first_number == 0.0) || (second_number == 0.0))
    {
        cout << "Please, use valid numbers (different from zero) for first and second parameter" << endl;
    }

    // Grab the operation
    const char *operation{argv[2]};
    char c;

    if ((strlen(operation) == 1) &&
        ((operation[0] == '+') ||
         (operation[0] == '-') ||
         (operation[0] == 'x') ||
         (operation[0] == '/')))
    {
        c = operation[0];
    }
    else
    {
        cerr << operation << " is not a valid operation." << endl;
        return 0;
    }

    // Do the operation
    switch (c)
    {
    case '+':
        cout << first_number << " + " << second_number << " = "
             << first_number + second_number << endl;
        break;

    case '-':
        cout << first_number << " - " << second_number << "="
             << first_number - second_number << endl;
        break;

    case 'x':
        cout << first_number << " * " << second_number << " = "
             << first_number * second_number << endl;
        break;

    case '/':
        cout << first_number << " / " << second_number << " = "
             << first_number / second_number << endl;
        break;
    }


    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END