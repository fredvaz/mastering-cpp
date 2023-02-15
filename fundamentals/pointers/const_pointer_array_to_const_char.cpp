/*

The C++20 Masterclass:

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

            EXAMPLE: 
*/

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    const char *const students[]{
        "Daniel Gray",
        "Tuna Philbe",
        "The Rock",
        "Kumar Singh",
        "Sam Ali",
        "Dave Mahoro"};

    //Print out the students
    std::cout << std::endl;
    std::cout << "Printing out the students : " << std::endl;
    for (const char *student : students)
    {
        std::cout << student << std::endl;
    }

    // *students[0] = 'K';

    //Can swap for new student though.
    const char *new_student{"Bob the Great"};
    //students[0] = new_student; // Compiler error

    //Print out the students
    std::cout << std::endl;
    std::cout << "Printing out the students : " << std::endl;
    for (const char *student : students)
    {
        std::cout << student << std::endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_N
#ifdef EXAMPLE_N
/*
    Notes:  #define EXAMPLE_N

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_N -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//