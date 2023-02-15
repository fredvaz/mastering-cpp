/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


bool car() {
    cout << "car function running" << endl;
    return false;
}

bool house() {
    cout << "house function running" << endl;
    return true;
}
bool job() {
    cout << "job function running" << endl;
    return false;
}
bool spouse() {
    cout << "spouse function running" << endl;
    return false;
}

/*  */
void test1() 
{
    bool a{ true };
	bool b{ true };
	bool c{ true };
	bool d{ false };
	bool p{ false };
	bool q{ false };
	bool r{ false };
	bool m{ true };
	
	// AND : If one of the operands is 0, the result is 0
	cout << endl;
	cout << "AND short circuit" << endl;

	bool result = a && b && c && d;

	cout << "result : " << boolalpha << result << endl;
	cout << endl;

    // OR : If one of the operands is 1, the result is 1.
	cout << "OR short circuit" << endl;

	result = p || q || r || m;

	cout << "result : " << boolalpha << result << endl;

}

/*  */
void test2() 
{
    // If car() True and house() False, the compiler will stop here and jumo the the else statement 
    if (car() && house() && job() && spouse())
    {
        cout << "I am happy! :D" << endl;
    }else
    {
        cout << "I am sad! :(" << endl;
    }

}

/*  */
void test3() 
{
    // If car() True and house() False, the compiler will stop here and jumo the the else statement 
    if (car() || house() || job() || spouse())
    {
        cout << "I am happy! :D" << endl;
    }else
    {
        cout << "I am sad! :(" << endl;
    }

}

int main() 
{
    
    // Notes:
    // Short Circuits Evaluations 
    // AND : If one of the operands is 0, the result is 0
    // OR : If one of the operands is 1, the result is 1
    // Why care? Computing some of the operands in the expression can be expensive. 
    // If short circuits is possible, such expensive computations can be avoid


    cout << "\nTest 1:" << endl;
    test1();

    cout << "\nTest 2:" << endl;
    test2();

    cout << "\nTest 3:" << endl;
    test3();


    return 0;
}