/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <string>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    	//Compare (1)
    //int compare( const basic_string& str ) const noexcept;(1)
	//Compares this string to str.
    /*
	std::string str1{"Hello"};
    std::string str2{"World"};
	
    std::cout << "str1 : " << str1 << std::endl;
	std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str1.compare(str2) : " << str1.compare(str2) << std::endl; // negative
    std::cout << "str2.compare(str1) : " << str2.compare(str1) << std::endl; // positive
    */

	//Compare (2)
    //int compare( size_type pos1, size_type count1,const basic_string& str ) const; (2)
	//Compares a  substring  of this string(from pos1, going count1 positions) to str
    /*
	std::string str1 = "Hello";
    std::string str3{"Hello World"};
    std::cout << "Comparing 'World' to 'Hello' : " << str3.compare(6,5,str1) << std::endl;//1
    */

	//Compare (3)
    //int compare( const CharT* s ) const;(4)
	//Compares this string to the null-terminated character sequence beginning 
    //at the character pointed to by s.
    std::string str5{"Hello"};
    const char* message {"World"};
    std::cout << "Comparing Hello to World : " << str5.compare(message) << std::endl;//-1
    std::cout << "Comparing Hello to World : " << str5.compare("World") << std::endl; //-1

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//

// #define EXAMPLE_N
#ifdef EXAMPLE_N
/*
    Notes:  #define EXAMPLE_N

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_N -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//