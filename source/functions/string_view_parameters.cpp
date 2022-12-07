/*

The C++20 Masterclass: String view parameters

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: string view parameters
*/

// void say_my_name(string_view &name) // Compiler error:  cannot bind non-const lvalue reference of type 'std::string_view&'
// void say_my_name(const string &name)
void say_my_name(string_view name) // Where possible, always use the std::string_view for string input in functions
                                   // and const references for other types
{
    cout << "Hello your name is : " << name << endl;
}

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    string some_name{"John"};
    say_my_name("John"); // Here, we are passing a const char* array
    say_my_name(some_name);
    // say_my_name(std::string_view("Samuel"));

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Implict conversions from std::string_view to std::string
*/

void say_my_name(const std::string &name);
void process_name(std::string_view name_sv);

int main()
{

    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    process_name("Daniel");

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

void say_my_name(const std::string &name)
{
    std::cout << "Your name is " << name << std::endl;
}

void process_name(std::string_view name_sv)
{

    say_my_name(name_sv); // Compiler error . Implicit conversion
                          // from std::string_view
                          // to std::string is not  allowed.

    //Fix : Be explicit about the conversion
    //say_my_name(std::string(name_sv));
}

#endif // TEST_CASE_N END

//
