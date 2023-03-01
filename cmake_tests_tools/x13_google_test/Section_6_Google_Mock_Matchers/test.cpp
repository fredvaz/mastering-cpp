#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

#include <map>

#include "IDatabaseConnection.hpp"
#include "Employee.hpp"
#include "EmployeeManager.hpp"

// Using Google Mock

class MockDatabaseConnection : public IDatabaseConnection // Mocked Class derived from the Super Class
{
public:
    MockDatabaseConnection(std::string serverAddress);

    MOCK_METHOD(void, connect, ());    // Mocking the connect() method form the IDatabaseConnect Class
    MOCK_METHOD(void, disconnect, ()); // Mocking the disconnect() method form the IDatabaseConnect Class

    MOCK_METHOD(float, getSalary, (int), (const)); // returns a float, method getSalary, the parameter is a int, const method
    MOCK_METHOD(void, updateSalary, (int, float));

    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float, float), (const));
    
    // MOCK_METHOD(std::map<std:string, int>, something, ());
    // NOTE: Compiler error due to std::map<std:string, int>, we must declare it like (std::map<std:string, int>)

};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{
}

// Lecture 51: Matchers (Code Example) / Shows how to check that the method was called with a certain value 
TEST(TestEmployeeManager, TestGetSalaryInRange)
{
    const int low = 5000;
    const int high = 8000;
    std::vector<Employee> returnedVector{Employee{1, 5600, "John"},
                                         Employee{2, 7000, "Jane"},
                                         Employee{3, 6600, "Alex"}};

    MockDatabaseConnection dbConnection("127.0.0.1");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
    EXPECT_CALL(dbConnection, getSalariesRange(low, high)).WillOnce(testing::Return(returnedVector));

    EmployeeManager employeeManager(&dbConnection);

    std::map<std::string, float> returnedMap = employeeManager.getSalariesBetween(low, high);

    for (auto it = returnedMap.begin(); it != returnedMap.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
        // ASSERT_THAT(it->second, testing::Gt(low)); // low+1000 FAILS 
        // First thing is the object that you are testing and then the matcher that want to test against
        // ASSERT_THAT(it->second, testing::AllOf(testing::Gt(low), testing::Lt(high))); // Combining the matchers
        ASSERT_THAT(it->second, testing::AnyOf(testing::Gt(low), testing::Lt(high)));   
    }
}

//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}