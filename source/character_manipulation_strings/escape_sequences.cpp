/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <string>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

//

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    /*
    for(size_t i{0} ; i  < 1000 ; ++i){
        std::cout << "Hello\n";
    }
    */

    /*
    std::cout << "He said \"Get out of here immediately!\"" << std::endl;
    */

    /*
    std::string todo_list{ "\tClean the house\n\tWalk the dog\n\tDo laundry\n\tPick groceries" };
    std::string windows_path{ "D:\\sandbox\\testProject\\hello.txt" };
    std::string linux_path{ "/home/username/files/hello.txt" };
    std::string hint{ " \"\\\\\" escapes a backslash character like \\." };
    std::cout << "todo_list : " << std::endl;
    std::cout << todo_list << std::endl;
    std::cout << "windows_path : " << windows_path << std::endl;
    std::cout << "linux_path : " << linux_path << std::endl;
    std::cout << "hint : " << hint << std::endl;
    */

    std::cout << "\a" << std::endl;

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