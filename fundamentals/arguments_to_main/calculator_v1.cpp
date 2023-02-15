/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

//#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Calculator v1
*/
int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    double first_number{5.0};
    double second_number{10.0};
    
    char c{'+'};

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