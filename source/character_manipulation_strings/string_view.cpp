/*

The C++20 Masterclass: String View

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <string_view>
#include <cstring>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Showing the problem
*/

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    std::string string{"Hello"};
    std::string string1{string}; // Copy
    std::string string2{string}; // Copy

    std::cout << "address of string: " << &string << std::endl;
    std::cout << "address of string1: " << &string1 << std::endl;
    std::cout << "address of string2: " << &string2 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Using string_view
*/

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    std::string_view sv{"Hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"};
    std::string_view sv1{sv};  // View viewing the hello literal
    std::string_view sv2{sv1}; // Another view viewing hello

    std::cout << "Size of string_view: " << sizeof(std::string_view) << std::endl;
    std::cout << "size of sv1 : " << sizeof(sv1) << std::endl;

    std::cout << "sv: " << sv << std::endl;
    std::cout << "sv1: " << sv1 << std::endl;
    std::cout << "sv2: " << sv2 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_2 END

//

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: Constructing string_view's
*/

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

    std::string string3{"Regular std::string"};
    const char *c_string{"Regular C-String"};
    const char char_array[]{"Char array"};  // Null terminated
    char char_array2[]{'H', 'u', 'g', 'e'}; // Non null terminated char array
    std::string_view sv3{"String litteral"};
    std::string_view sv4{string3};
    std::string_view sv5{c_string};
    std::string_view sv6{char_array};
    std::string_view sv7{sv3};
    std::string_view sv8{char_array2, std::size(char_array2)}; // Non null terminated char array
                                                               // Need to pass in size info
    std::cout << "sv3 : " << sv3 << std::endl;
    std::cout << "sv4 : " << sv4 << std::endl;
    std::cout << "sv5 : " << sv5 << std::endl;
    std::cout << "sv6 : " << sv6 << std::endl;
    std::cout << "sv7 (constructed from other string_view) : " << sv7 << std::endl;
    std::cout << "Non null terminated string with std::string_view : " << sv8 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_3 END

//

// #define TEST_CASE_4
#ifdef TEST_CASE_4
/*
    Notes:  #define TEST_CASE_4

            Test Case: Changes to the original string are reflected in the string_view
*/

int main()
{
    cout << "------------------------------ Test Case 4 -------------------------------------" << endl;

    char word[]{"Dog"};
    std::string_view sv9{word};

    std::cout << "word : " << sv9 << std::endl;

    std::cout << "Changing data... " << std::endl;
    // Change the data
    word[2] = 't';

    std::cout << "word : " << sv9 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_4 END

//

// #define TEST_CASE_5
#ifdef TEST_CASE_5
/*
    Notes:  #define TEST_CASE_5

            Test Case: Changing the view window : SHRINKING
*/

int main()
{
    cout << "------------------------------ Test Case 5 -------------------------------------" << endl;

    const char *c_string1{"The animals have left the region"};
    std::string_view sv10{c_string1};

    std::cout << "sv10 : " << sv10 << std::endl;

    sv10.remove_prefix(4); // Removes "The"

    // Prints : animals have left the region
    std::cout << "View with removed prefix(4) : " << sv10 << std::endl;

    sv10.remove_suffix(10); // Removes "the region"

    // Prints : animals have left
    std::cout << "View with removed suffix(10) : " << sv10 << std::endl;

    // Changing the view doesn't change the viewed string :
    std::cout << "Original sv10 viewed string : " << c_string1 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_5 END

//

// #define TEST_CASE_6
#ifdef TEST_CASE_6
/*
    Notes:  #define TEST_CASE_6

            Test Case: String_view shouldn't outlive whatever it is viewing
*/

int main()
{
    cout << "------------------------------ Test Case 6 -------------------------------------" << endl;

    std::string_view sv11;
    {
        std::string string4{"Hello there"};
        sv11 = string4;
        std::cout << "INSIDE --- sv11 is viewing : " << sv11 << std::endl;

        // string4 goes out of scope here.
    }
    std::cout << "OUTSIDE --- sv1 is viewing : " << sv11 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_6 END

//

// #define TEST_CASE_7
#ifdef TEST_CASE_7
/*
    Notes:  #define TEST_CASE_7

            Test Case: data
*/

int main()
{
    cout << "------------------------------ Test Case 7 -------------------------------------" << endl;

    std::string_view sv13{"Ticket"};
    std::cout << "sv13 : " << sv13 << std::endl;
    std::cout << "std::strlen(sv13.data()) : " << std::strlen(sv13.data()) << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_7 END

//

// #define TEST_CASE_8
#ifdef TEST_CASE_8
/*
    Notes:  #define TEST_CASE_8

            Test Case: Don't use data() on a modified view (through remove_prefix or remove_suffix)
*/

int main()
{
    cout << "------------------------------ Test Case 8 -------------------------------------" << endl;

    std::string_view sv14{"Ticket"};
    sv14.remove_prefix(2);
    sv14.remove_suffix(2);

    // Length info is lost when you modify the view
    std::cout << sv14 << " has " << std::strlen(sv14.data()) << " characters(s)" << std::endl;
    std::cout << "sv14.data() is " << sv14.data() << std::endl;
    std::cout << "sv14 is " << sv14 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_8 END

//

// #define TEST_CASE_9
#ifdef TEST_CASE_9
/*
    Notes:  #define TEST_CASE_9

            Test Case: Don't view non null terminated strings
*/

int main()
{
    cout << "------------------------------ Test Case 9 -------------------------------------" << endl;

    char char_array3[]{'H', 'e', 'l', 'l', 'o'};
    std::string_view sv15{char_array3, std::size(char_array3)};

    std::cout << sv15 << " has " << std::strlen(sv15.data()) << " characters(s)" << std::endl;
    std::cout << "sv15.data is  : " << sv15.data() << std::endl;
    std::cout << "sv15 is : " << sv15 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_9 END

//

// #define TEST_CASE_10
#ifdef TEST_CASE_10
/*
    Notes:  #define TEST_CASE_10

            Test Case: std::string behaviors
*/

int main()
{
    cout << "------------------------------ Test Case 10 -------------------------------------" << endl;

    std::string_view sv16{"There is a huge forest in that area"};

    std::cout << "sv16 is " << sv16.length() << " characters long" << std::endl;
    std::cout << "The front character is : " << sv16.front() << std::endl;
    std::cout << "The back character is : " << sv16.back() << std::endl;
    std::cout << "Substring : " << sv16.substr(0, 22) << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_10 END

//