/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


int number1 {75};
int number2 {60};

bool result = (number1 < number2); // Expression 


bool red {false};
bool green {true};
bool yellow {false};
bool police_stop {true};


/*  Free standing if statement   */
void test1() 
{
    
    if (result == true)
    {
        cout << number1 << " is less than " << number2 << endl;
    }

    if (!(result == true))
    {
        cout << number1 << " is NOT less than " << number2 << endl;
    }

}

/*  Using else statement    */
void test2() 
{


    if (result == true)
    {
       cout << number1 << " is less than " << number2 << endl;
    }
    else
    {
        cout << number1 << " is NOT less than " << number2 << endl;
    }

}

/*  Use expressions as condtion directly    */
void test3()
{

    
    if (number1 < number2)
    {
        cout << number1 << " is less than " << number2 << endl;
    }
    else
    {
        cout << number1 << " is NOT less than " << number2 << endl;
    }

}

/*  Nesting if statements   */
void test4()
{
    /*
     *      If green : go
     *      If red, yellow : stop
     *      If green and police_stop : stop
     * 
    */

     if (red)
     {
         cout << "STOP!" << endl;
     }
     if (yellow)
     {
         cout << "Slow down!" << endl;
     }
	 if (green)
     {
		 cout << "GO!" << endl;
	 }

}

/*  Nesting if statements   */
void test5()
{
    /*
     *      If green : go
     *      If red, yellow : stop
     *      If green and police_stop : stop
     * 
    */
    cout << "Police officer stops" << endl;

	if(green){
        if(police_stop){
            cout << "STOP!" << endl;
        }
        else
        {
            cout << "GO!" << endl;
        }
     }

}

/*  Nesting if statements   */
void test6()
{
    /*
     *      If green : go
     *      If red, yellow : stop
     *      If green and police_stop : stop
     * 
    */
    cout << "Police officer stops" << endl;

    if (green && !police_stop)
    {
        cout << "GO!" << endl;
    }
    else
    {
        cout << "STOP!" << endl;
    }

}


int main()
{
    
    // Notes:
    
    //cout << boolalpha << "\nResult: " << result << endl;

    cout << "\nTest 1:" << endl;
    test1();

    cout << "\nTest 2:" << endl;
    test2();

    cout << "\nTest 3:" << endl;
    test3();

    cout << "\nTest 4:" << endl;
    test4();

    cout << "\nTest 5:" << endl;
    test5();

    cout << "\nTest 6:" << endl;
    test6();

      
    return 0;
}