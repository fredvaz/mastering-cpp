/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


const int Pen{20};
const int Marker{20};
const int Eraser{30};
const int Rectangle{40};
const int Circle{50};
const int Ellipse{60};


/*  */
void test1() 
{
    
    int tool{Rectangle};

    if (tool == Pen)
    {
        cout << "Active tool is pen" << endl;
    }
    else if (tool == Marker) 
    {
        cout << "Active tool is a Marker" << endl;
    }
    else if (tool == Eraser )
    {
        cout << "Active tool is a Eraser" << endl;
    }
    else if (tool == Rectangle)
    {
        cout << "Actrive tool is a Rectangle" << endl;
    }
    else if (tool == Circle)
    {
        cout << "Active tool is a Circle" << endl;
    }
    else if (tool == Ellipse)
    {
        cout << "Active tool is a Ellipse" << endl;
    }
    
    cout << "Moving on" << endl;
}


int main(){
    
    // Notes:
    // Testing for several different conditions 

    cout << "\nTest 1:" << endl;
    test1();


    return 0;
}