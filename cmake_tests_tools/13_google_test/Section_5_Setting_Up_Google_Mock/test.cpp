#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibraryCode.hpp"

// Using Google Mock

class SomeClass
{
public: 
    SomeClass() = default;
    virtual void someMethod()
    {
        std::cout << "Say something\n";
    }
};

class MockedClass : public SomeClass
{
public:
    MockedClass() = default;
    MOCK_METHOD0(someMethod, void());
};

TEST(TestSample, TestMock)
{
    MockedClass mc;
    EXPECT_CALL(mc, someMethod()).Times(1); // Calls the mehtod 1 time
    mc.someMethod();
    // mc.someMethod(); // Fails the Test
}

// 

int add(int a, int b)
{
 return a + b;
}

TEST(TestSample, TestAddition)
{
    ASSERT_EQ(2, add(1, 1));
}

//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}