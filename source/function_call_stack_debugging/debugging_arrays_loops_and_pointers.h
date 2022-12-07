/*

The C++20 Masterclass: Debugging Arrays Loops and Pointers

General Notes from cplusplus.com:


   [REF]:
*/

using namespace std;

double sum (double array[], size_t count){

	double sum{};
    for(size_t i{} ; i < count ; ++i){
        sum += array[i];
    }
    return sum;
	
}

// Continue in the main function