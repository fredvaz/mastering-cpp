/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{
    int speed{10};

    bool go{false};

    if (go)
    {
        cout << "Speed: " << speed << endl;   
        if (speed > 5)
        {
            cout << "Slow down!" << endl;
        }
        else
        {
            cout << "All good!" << endl;
        }
    }else
    {   
        cout << "Speed: " << speed << endl;   
        cout << "Stop!" << endl;
    }

    cout << "Out of the if block, Speed: " << speed << endl;   
}
/*  */
void test2() 
{
    bool go{false};

    if (int speed{10}; go)
    {
        cout << "Speed: " << speed << endl;   
        if (speed > 5)
        {
            cout << "Slow down!" << endl;
        }
        else
        {
            cout << "All good!" << endl;
        }
    }else
    {   
        cout << "Speed: " << speed << endl;   
        cout << "Stop!" << endl;
    }

    // Speed is undefined out of the scope
    // cout << "Out of the if block, Speed: " << speed << endl; 
}

int main()
{
    
    // Notes: If with initializer
    // if (int speed{10}; go)

    cout << "\nTest 1:" << endl;
    test1();

    cout << "\nTest 2:" << endl;
    test2();

    cout << endl;
    return 0;
}