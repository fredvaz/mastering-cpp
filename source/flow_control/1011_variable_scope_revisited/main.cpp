/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{
    bool green {false};

    if (green)
    {
        int car_count{23};
        cout << "Light is green " << car_count << "on the move!" << endl;
    }else
    {   
        // Generates a Compiler Error! The variable is not in the scope!
        car_count++;        
        cout << "Light is not green. All should Stop!" << endl;
    }
}


int main()
{
    
    // Notes: Variable Scope Revisited  

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}