/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <string>


using namespace std;


const int Pen{10};
const int Marker{20};
const int Eraser{30};
const int Rectangle{40};
const int Circle{50};
const int Ellipse{60};


void test1() 
{
    
    int tool{Marker};

    switch (tool)  // The switch case condition can only be a Integral type and enums: int, long, unsigned short etc.
    {
    case Pen:
        cout << "Active tool is pen" << endl;
        break;
    
    case Marker:
        cout << "Active tool is a Marker" << endl;
        break;
    
    case Eraser:
        cout << "Active tool is a Eraser" << endl;
        break;

    case Rectangle:
        cout << "Active tool is a Rectangle" << endl;
        break;

    case Circle:
         cout << "Active tool is a Circle" << endl;
         break;

    case Ellipse:
        cout << "Active tool is a Ellipse" << endl;
        break;

    default:
        cout << "No match found" << endl;
        break;
    }
 
    cout << "Moving on" << endl;
}

void test2() 
{
    
    int tool{Marker};

    switch (tool)  // The switch case condition can only be a Integral type and enums: int, long, unsigned short etc.
    {
    case Pen:
        cout << "Active tool is pen" << endl;
        break;
    
    case Marker:
        cout << "Active tool is a Marker" << endl;
        //break; // If we do not include the break it will not stop and will execute the next case
    
    case Eraser:
        cout << "Active tool is a Eraser" << endl;
        //break;

    case Rectangle:
        cout << "Active tool is a Rectangle" << endl;
        //break;

    case Circle:
         cout << "Active tool is a Circle" << endl;
         //break;

    case Ellipse:
        cout << "Active tool is a Ellipse" << endl;
        //break;

    default:
        cout << "No match found" << endl;
        //break;
    }
 
    cout << "Moving on" << endl;
}

void test3() 
{
    
    int tool{Eraser};

    switch (tool)  // The switch case condition can only be a Integral type and enums: int, long, unsigned short etc.
    {
    case Pen:
        cout << "Active tool is pen" << endl;
        break;
    
    case Marker:
        cout << "Active tool is a Marker" << endl;
        break;

    // Grouping Switch Cases    
    case Eraser:
    case Rectangle:
    case Circle:
         cout << "Drawing Sahpes" << endl;
         break;

    case Ellipse:
        cout << "Active tool is a Ellipse" << endl;
        break;

    default:
        cout << "No match found" << endl;
        break;
    }
 
    cout << "Moving on" << endl;
}

/* void test4() 
{

    string name {"John"};

    switch (name) // Compiler error: string is not allowed a type for the condition
    {  
    default:
        break;
    }

} */

int main(){
    
    // Notes:
    // Alternative of the else if statement Testing for several different conditions
    // The break statement after each case is very important. It stops processing
    // switch block when a successful case has been found. If the break statement
    // is not there, all the case following the current case will be executed. 

    cout << "Test 1:" << endl;
    test1();

    cout << "Test 2:" << endl;
    test2();

    cout << "Test 3:" << endl;
    test3();


    return 0;
}