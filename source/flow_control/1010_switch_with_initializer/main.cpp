/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;

const int Pen{10};
const int Marker{20};
const int Eraser{30};
const int Rectangle{40};
const int Circle{50};
const int Ellipse{60};

/*  */
void test1() 
{
    int tool {Eraser};

    switch (double strength{3.56}; tool)
    {
        case Pen : {
             cout << "Active tool is Pen. strength : " <<  strength << endl;
        }
        break;

        case Marker : {
             cout << "Active tool is Marker. strength : " <<  strength << endl;
        }
        break;


        case Eraser :
        case Rectangle : 
        case Circle : {
             cout << "Drawing Shapes. strength : " <<  strength << endl;
        }
        break;

        case Ellipse : {
             cout << "Active tool is Ellipse. strength : " <<  strength << endl;
        }
        break;
    
        default: {
            cout << "No match found. strength : " <<  strength << endl;
        }
        break;
    }

    cout << "Moving on" << std::endl;
    //strength++;

}


int main()
{
    
    // Notes: Switch with Initializer
    // 
    

    cout << "\nTest 1:" << endl;
    test1();

    cout << endl;
    return 0;
}