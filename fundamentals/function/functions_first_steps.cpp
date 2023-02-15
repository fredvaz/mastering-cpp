/*

The C++20 Masterclass: Functions

General Notes:
        Functions are C++ entities that associate a sequence of statements (a function body) with a name
        and a list of zero or more function parameters.

        A function can terminate by returning or by throwing an exception.

        A function declaration may appear in any scope, but a function definition may only appear in
        namespace scope or, for member and friend functions, in class scope.

        Functions are not objects: there are no arrays of functions and functions cannot be passed by
        value or returned from other functions.

        Multiple functions in the same scope may have the same name, as long as their parameter lists
        and, for non-static member functions, cv/ref (since C++11)-qualifications are different.
        This is known as function overloading. Function declarations that differ only in the return
        type and the noexcept specification (since C++17) cannot be overloaded. 

        Function signature: function name + function parameters

   [REF]:
        https://en.cppreference.com/w/cpp/language/functions
   
*/
#include <iostream>

using namespace std;

//

//#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1


            EXAMPLE: functions declarations and calls
*/

// Function that takes a single parameter, and doesn't give back the result explicitly
void enter_bar(size_t age)
{ // Functions parameters
    if (age > 16)
    {
        cout << "You're " << age << " years old. Please proceed." << endl;
    }
    else
    {
        cout << "Sorry, you're too young for this. No offense! " << endl;
    }
    return; // No return, since it is a void function, we can ommit the return statement
}

// Function that takes multiple parameters and returns the result of the computation
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Function that doesnt' take parameters and returns nothing
void say_hello()
{
    cout << "Hello World!" << endl;
    return; // You could omit this return statement for functions returning void
}

// Function that takes no parameters and return something
int lucky_number()
{
    return 99;
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    // Calling enter_bar
    enter_bar(22); // Function arguments
    enter_bar(15);

    for (size_t i{1}; i < 20; ++i)
    {
        enter_bar(i);
    }

    cout << "--------------------------------------------------------------------------------" << endl;

    // Calling max
    int x{22};
    int y{44};

    int result = max(100, 20); // Arguments
    result = max(x, y);
    cout << "max: " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;

    // Calling say_hello
    say_hello();

    cout << "--------------------------------------------------------------------------------" << endl;

    // Calling lucy_number
    int result2{};

    result2 = lucky_number();
    cout << "result : " << result2 << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}
#endif // EXAMPLE_N END

//

//#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Parameters inside a function are copies 
*/

// Parameters passed this way are scoped localy in the function.
// Changes to them are not visible outside the function. What we
// have inside the function are actually COPIES of the arguments
// passed to the function.
double increment_multiply(double a, double b)
{

    cout << "Inside function , before increment : " << endl;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    double result = ((++a) * (++b));

    cout << "Inside function , after increment : " << endl;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    //Returning the result
    return result;
}

int main()
{

    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    double h{3.00};
    double i{4.00};

    cout << "Outside function , before increment : " << endl;
    cout << "h : " << h << endl;
    cout << "i : " << i << endl;

    double incr_mult_result = increment_multiply(h, i);

    cout << "Outside function , before increment : " << endl;
    cout << "h : " << h << endl;
    cout << "i : " << i << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//

//#define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_3

            EXAMPLE: Coding Exercise 25 

    Sum up the digits
    Your job is to write a C++ function that sums up all the digits in an integer. For EXAMPLE_ if we pass
    an unsigned integer 79 into the function, it should sum up the digits and return the result as 16.
    Your function should be able to handle any number of digits. Again if we pass in 62727289 we should
    get 43 returned from the function.

    The requirement is that the input parameter is of type unsigned int and the return type is also
    unsigned int. The function name has to be exactly digit_sum.

    Hint : You may use the % operator to extract digits and the integer division operator to grab
    the remaining integer after you extract a single digit. You will put all this machinery in a loop
    so that your code can theoretically handle any number of digits.
*/

unsigned int digit_sum(unsigned int num)
{
    unsigned int digit = 0;
    unsigned int inside_num = num;
    unsigned int sum{};

    while (inside_num > 0)
    {
        digit = inside_num % 10;
        sum += digit;
        inside_num = inside_num / 10;
    }

    return sum;
}

int main()
{

    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

    unsigned int digit_var = 79;

    unsigned int result = digit_sum(digit_var);

    cout << "result: " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END