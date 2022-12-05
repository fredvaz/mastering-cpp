/*

The C++20 Masterclass: Coding Exercise 36

   [REF]:
*/

#define Test1

using namespace std;

int odd()
{
    static int odd{-1};
    odd += 2;
    return odd;
}

void print_odds(unsigned int count)
{
    for (size_t i{0}; i < count; i++)
    {
        std::cout << odd() << " ";
    }
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    print_odds(10);
}
#endif
