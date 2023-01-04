/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

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

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: 
*/

//

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_2 END

//

// #define TEST_CASE_N
#ifdef TEST_CASE_N
/*
    Notes:  #define TEST_CASE_N

            Test Case: 
*/

//

int main()
{
    cout << "------------------------------ Test Case N -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//