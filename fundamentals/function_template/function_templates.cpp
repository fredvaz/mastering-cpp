/*

The C++20 Masterclass: Function Teamples

General Notes:
        A function template defines a family of functions. They are blue prints of functions for the Compiler
        not are really C++ code.

   [REF]: https://en.cppreference.com/w/cpp/language/function_template
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Function Teamples EXAMPLE_s
*/

/* 
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

string maximum(const string &a, const string &b)
{
    return (a > b) ? a : b;
}

long long int maximum(long long int a, long long int b)
{
    return (a > b) ? a : b
} 
*/

template <typename T> // T is a place holder for the passe type of a variable
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int x{5};
    int y{7};

    int result = maximum(x, y);

    cout << "result: " << result << endl;

    // Another EXAMPLE_
    double x2{5.5};
    double y2{7.5};

    double result2 = maximum(x2, y2);

    cout << "result2: " << result2 << endl;

    // Another EXAMPLE_
    string x3{"Hello"};
    string y3{"World!"};

    auto result3 = maximum(x3, y3);

    cout << "result3: " << result3 << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: We must assure that our data can be manipulated by our function template
*/

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    // int x{10};
    // int y{10};
    // Strings types does not support the mulplication operation, so neither the function template
    string x{"Hello"};
    string y{"World!"}; // Compiler error: no match for 'operator*' (operand types are '__cxx11::basic_string<char>' and '__cxx11::basic_string<char>')

    auto result = multiply(x, y);

    cout << "result: " << result << endl;

    // Another EXAMPLE_: deduced conflicting types for parameter 'T' ('double' and 'int')
    double x2{10.0};
    int y2{10};

    auto result2 = multiply(x2, y2);

    cout << "result2: " << result2 << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_3

            EXAMPLE: Function Templates with Pointers
*/

template <typename T> // T is a place holder for the passe type of a variable
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

    int x{5};
    int y{7};

    int *p_x{&x};
    int *p_y{&y};

    auto result = maximum(p_x, p_y); // Give us the wrong result, it will compare the memory addresses instead
                                     // of the type int variables. See in the Debugger 

    cout << "*result : " << *result << endl;
    cout << "result : " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_3 END

//

// #define EXAMPLE_4
#ifdef EXAMPLE_4
/*
    Notes:  #define EXAMPLE_4

            EXAMPLE: Coding Exercise 38

            Hunt them down!
            Your job is to write a function template that finds stuff in a collection. The function should
            be able to work regardless of the type that you store in the collection. The function should take
            three parameters : the collection as an array, the value to look for and the size of the array. 
            As an EXAMPLE_ below is a prototype for the int version of the function

            int hunt_down(const int& value, const int* collection, size_t size)
            The function should return an int. If the value we're looking for is found, you return the
            index where you found it. If you don't find the value, you should return -1 to mean that the
            value was no where to be found in the collection.
*/

template <typename T>
int hunt_down(const T& value, const T* collection, size_t size) // Note: const, pass with ref and pointer
{
	for (size_t i{ 0 }; i < size; i++) {
		if (collection[i] == value) {
			return i; // Found it; return the index.
		}
	}
	return -1; 
}

int main()
{
    cout << "------------------------------ EXAMPLE_4 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_4 END

//