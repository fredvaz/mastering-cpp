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
    //The bad way to do things
    std::string todo_list {"\tClean the house\n\tWalk the dog\n\tDo laundry\n\tpick groceries"};
    std::string windows_path {"D:\\sandbox\\testProject\\hello.txt"};
	std::string linux_path {"/home/username/files/hello.txt"};
    std::string hint {" \"\\\\\" escapes a backslash character like \\."};
	
	std::cout << "todo_list : " << std::endl;
	std::cout << todo_list << std::endl;
	std::cout << "windows_path : " << windows_path << std::endl;
	std::cout << "linux_path : " << linux_path << std::endl;
	std::cout << "hint : " << hint << std::endl;
    */

   /*
   //Use raw string literals
   std::string to_do_list {R"(  Clean the house
   Walk the dog
   Do laundry
   Pick groceries)"};
   std::cout << "to_do_list : " << std::endl;
   std::cout << to_do_list << std::endl;
   */

  /*
  //Raw string literals with assignments
  std::string to_do_list =   R"(
	Clean the house
	Walk the dog
	Do Laundry
	Pick groceries
    )";
   std::cout << "to_do_list : " << std::endl;
   std::cout << to_do_list << std::endl;
   */

  /*
  //Raw string literals with assignments
  const char* c_string {  R"(
	Clean the house
	Walk the dog
	Do Laundry
	Pick groceries
    )"} ;
   std::cout << "to_do_list : " << std::endl;
   std::cout << c_string << std::endl;
   */

    /*
    //Fixing other escaped strings
    std::string windows_path1 {R"(D:\sandbox\testProject\hello.txt)"};
	std::string linux_path1 {R"(/home/username/files/hello.txt)"};
    std::string hint1 {R"("\\" escapes a backslash character like \.)"};	
	
	std::cout << "windows_path1 : " << windows_path1 << std::endl;
	std::cout << "linux_path1 : " << linux_path1 << std::endl;
	std::cout << "hint1 : " << hint1 << std::endl;
    */

   //Problematic raw string literals
   std::string sentence {R"--(The message was "(Stay out of this!)")--"};

   std::cout << "sentence : " << sentence << std::endl;

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