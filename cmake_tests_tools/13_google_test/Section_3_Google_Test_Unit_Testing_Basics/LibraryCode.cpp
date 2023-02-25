#include "LibraryCode.hpp"

#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdexcept>

//

int sum(int a, int b)
{
    return a + b;
}

bool isPositive(int x)
{
    return x >= 0;
}

int countPositives(std::vector<int> const &inputVector)
{
    return std::count_if(inputVector.begin(), inputVector.end(), isPositive);
}

// Transforms lower case to Upper case: hello -> HELLO
void toUpper(char *inputString)
{
    for (size_t i = 0; i < strlen(inputString); i++)
    {
        inputString[i] = toupper(inputString[i]);
    }
}

double mySqrt(double input)
{
    if (input < 0)
    {
        std::cout << "Exception throw\n";
        throw std::runtime_error("Negative argument");
    }
    std::cout << "No Exception throw\n";
    return sqrt(input);
}