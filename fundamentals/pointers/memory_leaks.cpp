/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

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
    int *p_number {new int{67}}; // Points to some address, let's call that address1
    
    //Should delete and reset here 
    
    int number{55}; // stack variable
    
    p_number = &number; // Now p_number points to address2 , but address1 is still in use by 
                        // our program. But our program has lost access to that memory location.
						//Memory has been leaked.
    */

    //Double allocation
    /*
    int *p_number1 {new int{55}};
    
	//Use the pointer
    
	//Should delete and reset here.
	
    p_number1 = new int{44}; // memory with int{55} leaked.
    delete p_number1;
    p_number1 = nullptr;
    */

    //Nested scopes with dynamically allocated memory
    {
        int *p_number2{new int{57}};

        //Use the dynamic memory
    }
    //Memory with int{57} leaked.

    std::cout << "Program ending well" << std::endl;

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

#endif // EXAMPLE_2 END

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