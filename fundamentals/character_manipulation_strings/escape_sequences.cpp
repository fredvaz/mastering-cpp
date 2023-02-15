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