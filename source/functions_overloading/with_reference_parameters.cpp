/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

// Implicit conversions with references
// double max(double a, double b)
// {
//     cout << "double max called" << endl;
//     return (a > b) ? a : b;
// }

// int &max(int &a, int &b) // Do again after the Functions Chapter
const int &max(const int &a, const int &b)
{
    cout << "int max called" << endl;
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    char a{6};
    char b{9};

    auto result = max(a, b); // It will work only with the const references
    cout << "result : " << result << endl;

    // Potential solution : Simple Cast
    // int temp_a{static_cast<int>(a)};
    // int temp_b{static_cast<int>(b)};

    // auto result1 = max(temp_a, temp_b);
    // cout << "result1 : " << result1 << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: 
*/

// Ambigous calls
void say_my_name(const string &name)
{
    cout << "Your name is (ref) : " << name << endl;
}

void say_my_name(string name)
{
    cout << "Your name is (non ref) : " << name << endl;
}

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    string name{"John"};

    say_my_name(name); // Compiler error: call of overloaded 'say_my_name(std::string&)' is ambiguous

    say_my_name("John"); // Compiler error: call of overloaded 'say_my_name(const char [5])' is ambiguous

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: Coding Exercise 34
*/

double add(double a, double b)
{
    return a + b;
}

string add(string &a, string &b)
{
    return a + b;
}

const char *add(char *a, const char *b)
{
    return strcat(a, b);
}

void stitch_them()
{
    char name[20]{"The sky"};
    auto result_str = add(name, " is blue");
    cout << "result_str : " << result_str;
}

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

    stitch_them();

    cout << "\n--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END
