#include <iostream>
#include <gtest/gtest.h>
#include <vector>

// My Library
#include "LibraryCode.hpp"

//

// Unit Test Example Lecture 7
TEST(TestSuiteSample, TestSample)
{
    int s = sum(2, 4);

    ASSERT_EQ(6, s);
}

// Lecture 19 Example 1
TEST(TestcountPositives, BasicTest)
{
    // Arrange - First Step of a Unit Test
    std::vector<int> inputVector{1, -2, 3, -4, 5, -6, -7};

    // Act - Second Step of a Unit Test
    int count = countPositives(inputVector);

    // Assert - Third Step of a Unit Test
    ASSERT_EQ(3, count);
}

// Lecture 19 Example 2
TEST(TestcountPositives, EmptyVectorTest)
{
    // Arrange - First Step of a Unit Test
    std::vector<int> inputVector{};

    // Act - Second Step of a Unit Test
    int count = countPositives(inputVector);

    // Assert - Third Step of a Unit Test
    ASSERT_EQ(0, count);
}

// Lecture 19 Example 3
TEST(TestcountPositives, AllNegativesTest)
{
    // Arrange - First Step of a Unit Test
    std::vector<int> inputVector{-1, -2, -3};

    // Act - Second Step of a Unit Test
    int count = countPositives(inputVector);

    // Assert - Third Step of a Unit Test - Assertions
    // ASSERT_EQ(20, count);
    // ASSERT_GE(20, count);
    EXPECT_EQ(20, count);
    // ASSERT_ is fatal the Test Fails and stops
    // EXPECT_ is Non-fatal the Test Fails but the tests continues

    std::cout << "After the assertion" << std::endl;
}

// Lecture 22: Assertions on Strings - Wrong way to do it
TEST(ToUpperTest, BasicTest)
{
    // Arrange - First Step of a Unit Test
    char inputString[] = "Hello World";

    // Act - Second Step of a Unit Test
    toUpper(inputString);

    // Check if the strings are equal
    std::cout << "After toUpper: " << inputString << std::endl;

    if (0 == strcmp(inputString, "HELLO WORLD")) // inputString == "Hello World"
    {
        std::cout << "Check: Equal strings\n";
    }
    else
    {
        std::cout << "Check: Not Equal strings\n";
    }

    // Assert - Third Step of a Unit Test - Assertions
    ASSERT_EQ("HELLO WORLD", inputString);
    // The ASSERTION will give us a FAILED test because the _EQ uses the == operator, like above example
    // and in the CLI we will see that the strings are two different pointers with different memnory addresses
    // ASSERT_EQ will compare the two pointers memory addresses and no the value of the strings
    // The ASSERT_EQ will do a pointer comparison and will not check the contents of the string. You should use ASSERT_STREQ
}

// Lecture 24: Assertions on Strings - Correct way to do it - using ASSERT_STREQ
TEST(ToUpperTest, SecondTest)
{
    // Arrange - First Step of a Unit Test
    char inputString[] = "Hello World";

    // Act - Second Step of a Unit Test
    toUpper(inputString);

    // Assert - Third Step of a Unit Test - Assertions
    // ASSERT_STREQ("HELLO WORLD", inputString);
    // ASSERT_STRCASEEQ("HELLO WORLD", inputString);

    // Using the std::string
    std::string str(inputString);
    ASSERT_STREQ("HELLO WORLD", inputString);
}

// Lecture 26: Assertions on Exceptions (Code Example)
TEST(SquareRootTest, NegativeArgumentTest)
{
    double input = -10;

    // ASSERT_ANY_THROW(mySqrt(input));
    ASSERT_THROW(mySqrt(input),  std::runtime_error);
}

TEST(SquareRootTest, PositiveArguments)
{
    double input = 10;

    // ASSERT_ANY_THROW(mySqrt(input));
    ASSERT_NO_THROW(mySqrt(input));
}

//

// Test main function Note: in Catch2 we can set a variable to create on its own the main function
// You don't necessarily need to write a main() function for the tests, just linking to gtest_main
// should define an entry point.
// https://google.github.io/googletest/primer.html#writing-the-main-function
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}