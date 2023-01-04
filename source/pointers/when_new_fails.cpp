/*

The C++20 Masterclass:

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

            Test Case: 
*/

//

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

        /*
    //int * data = new int[10000000000000000]; // 
    for(size_t i{0} ; i < 10000000 ; ++i){
        int * data = new int[100000000];
    }
    */

   //exception
   /*
    for(size_t i{0} ; i < 100 ; ++i){
        try{
            int * data = new int[1000000000];
        }catch(std::exception& ex){
            std::cout << "  Something went wrong : " << ex.what() << std::endl;
        }
    }
    */


   //std::nothrow
    for(size_t i{0} ; i < 100 ; ++i){
   
        int * data = new(std::nothrow) int[1000000000];

        if(data!=nullptr){
            std::cout << "Data allocated" << std::endl;
        }else{
            std::cout << "Data allocation failed" << std::endl;
        }
       
    }


    std::cout << "Program ending well" << std::endl;

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

#endif // TEST_CASE_2 END

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