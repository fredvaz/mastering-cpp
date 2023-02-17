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
TEST(countPositives, BasicTest)
{
    // Arrange - First Step of a Unit Test
    std::vector<int> inputVector{1, -2, 3, -4, 5, -6, -7};

    // Act - Second Step of a Unit Test
    int count = countPositives(inputVector);

    // Assert - Third Step of a Unit Test
    ASSERT_EQ(3, count);

}

// Lecture 19 Example 2
TEST(countPositives, EmptyVectorTest)
{
    // Arrange - First Step of a Unit Test
    std::vector<int> inputVector{};

    // Act - Second Step of a Unit Test
    int count = countPositives(inputVector);

    // Assert - Third Step of a Unit Test
    ASSERT_EQ(0, count);

}


// Lecture 19 Example 3
TEST(countPositives, AllNegativesTest)
{
    // Arrange - First Step of a Unit Test
    std::vector<int> inputVector{-1, -2, -3};

    // Act - Second Step of a Unit Test
    int count = countPositives(inputVector);

    // Assert - Third Step of a Unit Test - Assertions
    // ASSERT_EQ(20, count);
    // ASSERT_GE(20, count);
    EXPECT_EQ(20, count);

    std::cout << "After the assertion" << std::endl;

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