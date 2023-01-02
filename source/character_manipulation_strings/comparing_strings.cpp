/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

	std::string hello_str{"Hello"};
    std::string bello_str{"Bello"};
    
    /*
	//Using the comparison operators
	std::cout << std::endl;
	std::cout << "Comparing with comparison operators : " << std::endl;
	
	std::cout << std::boolalpha;
    std::cout << hello_str << "==" <<  bello_str <<" : " << (hello_str == bello_str) << std::endl;//false
    std::cout << hello_str << "!=" <<  bello_str <<" : " << (hello_str != bello_str) << std::endl; //true
    std::cout << hello_str << ">" <<  bello_str <<" : " << (hello_str > bello_str) << std::endl; // true
    std::cout << hello_str << ">=" <<  bello_str <<" : " << (hello_str >= bello_str) << std::endl; // true
    std::cout << hello_str << "<" <<  bello_str <<" : " << (hello_str < bello_str) << std::endl; // false
    std::cout << hello_str << "<=" <<  bello_str <<" : " << (hello_str <= bello_str) << std::endl; // false
    */

	//Can even compare std::strings to C-strings
    /*
    const char * c_string1 {"Bello"};
    hello_str = "Hello";
    
    std::cout << "hello_str.size() : " << hello_str.size() << std::endl;
    std::cout << "std::strlen(c_string1) : " << std::strlen(c_string1) << std::endl;
    std::cout << hello_str << "==" <<  c_string1 <<" (C-String) : " << (hello_str == c_string1) << std::endl; //false
    std::cout << c_string1 << " (C-String) ==" <<  hello_str <<" : " << (c_string1 == hello_str) << std::endl;//false
	std::cout << c_string1 << " (C-String) >=" <<  hello_str <<" : " << (c_string1 >= hello_str) << std::endl;//false
	std::cout << c_string1 << " (C-String) <" <<  hello_str <<" : " << (c_string1 < hello_str) << std::endl; // true
	*/


	//Be careful about char arrays not terminated with null character
    hello_str = "hello";
	//const char hello_char_array[] {'h','e','l','l','o'}; //The compiler is going to read past the string
														   //until it sees a null character and consider that
														   //end of the string. Your comparisons may give 
														   //erronous results
	
	const char hello_char_array[] {'h','e','l','l','o','\0'};//It works right if you put the '\' yourself
	std::cout << hello_str << "== hello_char_array : "  << (hello_str == hello_char_array) << std::endl;

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    //

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

//

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//

// #define TEST_CASE_N
#ifdef TEST_CASE_N
/*
    Notes:  #define TEST_CASE_N

            Test Case: 
*/

//

int main()
{
    cout << "------------------------------ Test Case N -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//