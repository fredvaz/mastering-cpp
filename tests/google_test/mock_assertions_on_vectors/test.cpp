#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

#include <map>

#include "LibraryCode.hpp"

//

// Lecture 52: Assertions on Vectors (Code Example) / Shows how to check that the method was called with a certain value 
TEST(VecToTests, ElementAreTest)
{
    std::vector<int> v = generateNumbers(5, 3);
    // 0, 1, 2, 0, 1

    ASSERT_THAT(v, testing::ElementsAre(0, 1, 2, 0, 1));
}

TEST(VecToTests, RangeTest)
{
    using namespace testing;

    std::vector<int> v = generateNumbers(5, 3);
    // 0, 1, 2, 0, 1

    ASSERT_THAT(v, Each(AllOf(Ge(0), Lt(3))));
}

//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}