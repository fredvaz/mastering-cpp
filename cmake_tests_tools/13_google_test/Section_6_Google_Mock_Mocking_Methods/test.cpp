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

// #define LEGACY_CODE

class MockDatabaseConnection : public IDatabaseConnection // Mocked Class derived from the Super Class
{
public:
    MockDatabaseConnection(std::string serverAddress);

#ifndef LEGACY_CODE

    MOCK_METHOD(void, connect, ());    // Mocking the connect() method form the IDatabaseConnect Class
    MOCK_METHOD(void, disconnect, ()); // Mocking the disconnect() method form the IDatabaseConnect Class

    MOCK_METHOD(float, getSalary, (int), (const)); // returns a float, method getSalary, the parameter is a int, const method
    MOCK_METHOD(void, updateSalary, (int, float));

    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float, float), (const));

    // MOCK_METHOD(std::map<std:string, int>, something, ());
    // NOTE: Compiler error due to std::map<std:string, int>, we must declare it like (std::map<std:string, int>)

    void someMemberMethod(std::string param)
    {
        std::cout << "Memember method called with param = " << param << "\n";
        throw std::runtime_error("Dummy error");
    }

#endif

    // Lecture 45: Mocking Methods - Legacy / old way of using Mock methods
#ifdef LEGACY_CODE
    // MOCK_METHODn, n=0, 10
    MOCK_METHOD0(connect, void()); // 0 because the method function takes no parameters
    MOCK_METHOD0(disconnect, void());

    MOCK_CONST_METHOD1(getSalary, float(int));    // _CONST_ because is a const method
    MOCK_METHOD2(updateSalary, void(int, float)); // METHOD2 because takes 2 parametes

    MOCK_CONST_METHOD1(getSalariesRange, std::vector<Employee>(float));
    MOCK_CONST_METHOD2(getSalariesRange, std::vector<Employee>(float, float));

#endif
};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{
}

// Lecture 44: Mocking Methods - Current Way (Code Example)
TEST(TestEmployeeManager, TestConnection)
{
    // IDatabaseConnection dbConnection("dummyConnection"); // NO Mocked Class
    MockDatabaseConnection dbConnection("127.0.0.1"); // We must call the Mocked Class

    EXPECT_CALL(dbConnection, connect());    // This two methods are called from IDatabaseConnect Class
    EXPECT_CALL(dbConnection, disconnect()); // in the below Employee EmployeeManager Class object below

    EmployeeManager employeeManager(&dbConnection); // We are creat the Mocked method
}

// Lecture 47: Mocking - Times (Code Example) / Expected calls and parameters
TEST(TestEmployeeManager, TestUpdateSalary)
{
    MockDatabaseConnection dbConnection("127.0.0.1");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
    // EXPECT_CALL(dbConnection, updateSalary(50, 60000)).Times(1); // We expexct to be called one time
    EXPECT_CALL(dbConnection, updateSalary(testing::_, testing::_)).Times(1); // use of testing::_ if the called parameters does not interest

    EmployeeManager employeeManager(&dbConnection);

    employeeManager.setSalary(50, 60000);
}

// Lecture 48: Mocking - Returns (Code Example) // Expected calls and returns
TEST(TestEmployeeManager, TestGetSalary)
{
    const int employeeId = 50;
    const float salary = 6100.0;
    MockDatabaseConnection dbConnection("127.0.0.1");
    EXPECT_CALL(dbConnection, connect());
    EXPECT_CALL(dbConnection, disconnect());
    // EXPECT_CALL(dbConnection, getSalary(testing::_)).WillOnce(testing::Return(salary));
    EXPECT_CALL(dbConnection, getSalary(testing::_)).Times(1).WillOnce(testing::Return(salary));

    EmployeeManager employeeManager(&dbConnection);

    float returnedSalary = employeeManager.getSalary(employeeId);

    ASSERT_EQ(salary, returnedSalary);
}

// Lecture 49: Invoking Actions (Code Example)
TEST(TestEmployeeManager, TestConnectionError)
{
    MockDatabaseConnection dbConnection("127.0.0.1");
    EXPECT_CALL(dbConnection, connect()).WillOnce(testing::Throw(std::runtime_error("Dummy error")));
    // EXPECT_CALL(dbConnection, disconnect()); // In this case it will not be called any more due to the connection error

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
}

// Another way using ACTION macro
ACTION(myThrow)
{
    std::cout << "Throwing an error!\n";
    throw std::runtime_error("Dummy error");
}

TEST(TestEmployeeManager, TestConnectionErrorAction)
{
    MockDatabaseConnection dbConnection("127.0.0.1");
    EXPECT_CALL(dbConnection, connect()).WillOnce(myThrow()); // Calls the ACTION

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
}

// Another way using INVOKE
void someFreeFunction()
{
    std::cout << "Free function\n";
    throw std::runtime_error("Dummy exception");
}

TEST(TestEmployeeManager, TestConnectionErrorInvoke)
{
    MockDatabaseConnection dbConnection("127.0.0.1");
    // EXPECT_CALL(dbConnection, connect()).WillOnce(testing::Invoke(someFreeFunction)); // Calls the someFreeFunction()

    // Also we can use with a Lambda expression
    // EXPECT_CALL(dbConnection, connect()).WillOnce(testing::Invoke(
    // []() { // Using the lambda function has some adavantages like capturing values from outisde scope
    //     std::cout << "Free function\n";
    //     throw std::runtime_error("Dummy exception");
    // }));

    auto boundMethod = std::bind(&MockDatabaseConnection::someMemberMethod, &dbConnection, "Some param");

    // Calling as a member in the Mocked Class
    EXPECT_CALL(dbConnection, connect()).WillOnce(testing::InvokeWithoutArgs(boundMethod));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
}

//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}