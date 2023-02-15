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

    //Find(1)
    //std::string::find()
    //size_type find( const basic_string& str, size_type pos = 0 ) const
    //Finds the starting index where the str substring is found in
    //the string where we call the method.
    /*
    std::string string1{"Water was poured in the heater"};
    std::string search_for{"ter"};
    
    size_t found_pos = string1.find(search_for);
    std::cout << "find('ter') : index [" << found_pos << "]" << std::endl;// index : 2
	
    //find red
    search_for = "red";
    found_pos = string1.find(search_for);
    std::cout << "find('red') : index [" << found_pos << "]" << std::endl;// 13
    //Find something that isn't there
    search_for = "chicken";
    found_pos = string1.find(search_for);
    std::cout << "find('chicken') : index ["<< found_pos << "]" << std::endl;//huge number
    //std::string::npos
    std::cout << "npos : " << std::string::npos << std::endl;
    size_t large = -1;
    std::cout << "large : " << large << std::endl;
    */

    //Using std::string::npos to check if search was successfull or failed
    /*
    std::string string1{"Water was poured in the heater"};
    std::string search_for{"red"};
    
    size_t found_pos = string1. find(search_for);
    if(found_pos == std::string::npos){
        std::cout << "Could not find the string 'red' : " << std::endl;
    }else{
        std::cout << "'red' found starting at position : " << found_pos << std::endl;
    }
	
	
	//Search for chicken and check result against std::string::npos
    search_for = "chicken";
    found_pos = string1.find(search_for);
    
    if(found_pos == std::string::npos){
        std::cout << "Could not find the string 'chicken'. " << std::endl;
    }else{
        std::cout << "'chicken' found starting at position : " << found_pos << std::endl;
    }
    */

    //Find(2)
    //Can specify the position where we want the search to start
    //using the second parameter of the method
    /*
    std::string string1{"Water was poured in the heater"};
    std::string search_for{"ter"};
    size_t found_pos = string1.find(search_for); 
    std::cout << "ter found at position : " << found_pos << std::endl;
    
    found_pos = string1.find(search_for,0);
    std::cout << "ter found at position : " << found_pos << std::endl;
    
    found_pos = string1.find(search_for,10);
    std::cout << "ter found at position : " << found_pos << std::endl;
    */

    //Find(3)
    //size_type find( const CharT* s, size_type pos = 0 ) const;
    //Finds the first substring equal to the character string pointed to by s
    //pos : the position where we start searching in the std::string

    std::string string2 = "beer is packaged by her in beer cans around here.";
    const char *c_string2{"her"};

    size_t found_pos = string2.find(c_string2, 2);
    if (found_pos != std::string::npos)
    {
        std::cout << c_string2 << " found at position : " << found_pos << std::endl;
    }
    else
    {
        std::cout << "Could not find the string :  " << (c_string2) << std::endl;
    }

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