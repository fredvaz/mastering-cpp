/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Range based for loop with references
    */

    int scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Printing positions
    cout << endl;

    cout << "Scores : ";
    for (auto score : scores)
    {
        cout << " " << score;
    }
    cout << endl;

    // This way it will change the original scores variable and not the copy
    // inside the for loop
    for (auto &score : scores)
    {
        score = score * 10;
    }

    // Printing after change
    cout << endl;
    cout << "Scores : ";
    for (auto score : scores)
    {
        cout << " " << score;
    }
    cout << endl;
}
#endif