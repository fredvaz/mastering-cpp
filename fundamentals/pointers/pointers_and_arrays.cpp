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

    int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int *p_score{scores};

    //Print the address
    std::cout << "scores : " << scores << std::endl;   // Array
    std::cout << "p_score : " << p_score << std::endl; // Pointer
    std::cout << "&scores[0]  : " << &scores[0] << std::endl;

    //Print the content at that address
    std::cout << std::endl;
    std::cout << "Printing out data at array address : " << std::endl;
    std::cout << "*scores : " << *scores << std::endl;
    std::cout << "scores[0] : " << scores[0] << std::endl;
    std::cout << "*p_score : " << *p_score << std::endl;
    std::cout << "p_score[0] : " << p_score[0] << std::endl;

    //Differences
    int number{21};
    p_score = &number;

    //scores = &number; // The array name is a pointer, but a special pointer that kind of identifies
    // the entire array. You'll get the error  : incompatible types in assignment
    // of 'int*' to 'int[10]'

    std::cout << "p_score : " << p_score << std::endl; // Pointer

    //std::size() doesn't work for raw pointers
    std::cout << "size : " << std::size(scores) << std::endl;
    //std::cout << "size : " << std::size(p_score) << std::endl; // Compiler error.

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