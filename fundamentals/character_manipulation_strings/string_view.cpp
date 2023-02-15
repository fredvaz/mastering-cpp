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

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Showing the problem
*/

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    std::string string{"Hello"};
    std::string string1{string}; // Copy
    std::string string2{string}; // Copy

    std::cout << "address of string: " << &string << std::endl;
    std::cout << "address of string1: " << &string1 << std::endl;
    std::cout << "address of string2: " << &string2 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Using string_view
*/

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

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

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_3

            EXAMPLE: Constructing string_view's
*/

int main()
{
    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

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

#endif // EXAMPLE_3 END

//

// #define EXAMPLE_4
#ifdef EXAMPLE_4
/*
    Notes:  #define EXAMPLE_4

            EXAMPLE: Changes to the original string are reflected in the string_view
*/

int main()
{
    cout << "------------------------------ EXAMPLE_4 -------------------------------------" << endl;

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

#endif // EXAMPLE_4 END

//

// #define EXAMPLE_5
#ifdef EXAMPLE_5
/*
    Notes:  #define EXAMPLE_5

            EXAMPLE: Changing the view window : SHRINKING
*/

int main()
{
    cout << "------------------------------ EXAMPLE_5 -------------------------------------" << endl;

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

#endif // EXAMPLE_5 END

//

// #define EXAMPLE_6
#ifdef EXAMPLE_6
/*
    Notes:  #define EXAMPLE_6

            EXAMPLE: String_view shouldn't outlive whatever it is viewing
*/

int main()
{
    cout << "------------------------------ EXAMPLE_6 -------------------------------------" << endl;

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

#endif // EXAMPLE_6 END

//

// #define EXAMPLE_7
#ifdef EXAMPLE_7
/*
    Notes:  #define EXAMPLE_7

            EXAMPLE: data
*/

int main()
{
    cout << "------------------------------ EXAMPLE_7 -------------------------------------" << endl;

    std::string_view sv13{"Ticket"};
    std::cout << "sv13 : " << sv13 << std::endl;
    std::cout << "std::strlen(sv13.data()) : " << std::strlen(sv13.data()) << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_7 END

//

// #define EXAMPLE_8
#ifdef EXAMPLE_8
/*
    Notes:  #define EXAMPLE_8

            EXAMPLE: Don't use data() on a modified view (through remove_prefix or remove_suffix)
*/

int main()
{
    cout << "------------------------------ EXAMPLE_8 -------------------------------------" << endl;

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

#endif // EXAMPLE_8 END

//

// #define EXAMPLE_9
#ifdef EXAMPLE_9
/*
    Notes:  #define EXAMPLE_9

            EXAMPLE: Don't view non null terminated strings
*/

int main()
{
    cout << "------------------------------ EXAMPLE_9 -------------------------------------" << endl;

    char char_array3[]{'H', 'e', 'l', 'l', 'o'};
    std::string_view sv15{char_array3, std::size(char_array3)};

    std::cout << sv15 << " has " << std::strlen(sv15.data()) << " characters(s)" << std::endl;
    std::cout << "sv15.data is  : " << sv15.data() << std::endl;
    std::cout << "sv15 is : " << sv15 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_9 END

//

// #define EXAMPLE_10
#ifdef EXAMPLE_10
/*
    Notes:  #define EXAMPLE_10

            EXAMPLE: std::string behaviors
*/

int main()
{
    cout << "------------------------------ EXAMPLE_10 -------------------------------------" << endl;

    std::string_view sv16{"There is a huge forest in that area"};

    std::cout << "sv16 is " << sv16.length() << " characters long" << std::endl;
    std::cout << "The front character is : " << sv16.front() << std::endl;
    std::cout << "The back character is : " << sv16.back() << std::endl;
    std::cout << "Substring : " << sv16.substr(0, 22) << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_10 END

//