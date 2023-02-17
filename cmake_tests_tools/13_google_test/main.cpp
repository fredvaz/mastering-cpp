#include <iostream>
#include "LibraryCode.hpp"

int main(int argc, char **argv)
{
    int s = sum(2, 3);

    std::cout << "Actual application" << std::endl;
    std::cout << "sum = " << s << std::endl;

    return 0;
}