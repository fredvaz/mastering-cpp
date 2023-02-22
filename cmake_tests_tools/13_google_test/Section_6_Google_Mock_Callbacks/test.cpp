#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>
 #include <functional>
 
#include <map>

#include "IDatabaseConnection.hpp"
#include "Employee.hpp"
#include "EmployeeManager.hpp"

// Using Google Mock

class MockDatabaseConnection : public IDatabaseConnection // Mocked Class derived from the Super Class
{
public:
    // using Callback = testing::MockFunction<void()>; // Lecture 53: Callbacks
    using Callback = testing::MockFunction<void(int, int)>;

    MockDatabaseConnection(std::string serverAddress);

    MOCK_METHOD(void, connect, ());    // Mocking the connect() method form the IDatabaseConnect Class
    MOCK_METHOD(void, disconnect, ()); // Mocking the disconnect() method form the IDatabaseConnect Class

    MOCK_METHOD(float, getSalary, (int), (const)); // returns a float, method getSalary, the parameter is a int, const method
    MOCK_METHOD(void, updateSalary, (int, float));

    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float, float), (const));

};

// Lecture 53: Callbacks
void realCallback()
{
    std::cout << "Real callback invoked\n";
}

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{
}

TEST(TestEmployeeManager, CallbackTest)
{
    MockDatabaseConnection dbConnection("127.0.0.1");
    
    // dbConnection.setOnConnect(realCallback); // Not working!

    testing::MockFunction<void(int, int)> mockFunction;
    dbConnection.setOnConnect(mockFunction.AsStdFunction()); // Not working!

    EXPECT_CALL(mockFunction, Call(testing::_, testing::_));

    dbConnection.connect();

}

//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}