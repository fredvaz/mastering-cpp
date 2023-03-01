#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

#include <map>

#include "IDatabaseConnection.hpp"
#include "Employee.hpp"
#include "EmployeeManager.hpp"

//

// Using Google Mock

class MockDatabaseConnection : public IDatabaseConnection // Mocked Class derived from the Super Class
{
public:
    MockDatabaseConnection(std::string serverAddress, HelperClass *hc);

    // MOCK_METHOD(void, connect, ());    // Mocking the connect() method form the IDatabaseConnect Class
    MOCK_METHOD(void, disconnect, ()); // Mocking the disconnect() method form the IDatabaseConnect Class

    MOCK_METHOD(float, getSalary, (int), (const)); // returns a float, method getSalary, the parameter is a int, const method
    MOCK_METHOD(void, updateSalary, (int, float));

    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, getSalariesRange, (float, float), (const));
    MOCK_METHOD(void, onConnect, (), (override)); // Lecture 54: Mocking Private and Static Methods

};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress, HelperClass *hc) 
    : IDatabaseConnection(serverAddress, hc)
{
}

// Now the Mock it for the increaseConnectionCount method
class MockHelper : public HelperClass
{
public:
    MOCK_METHOD(void, increaseConnectionCount, (), (override));
};

// Lecture 54: Mocking Private and Static Methods
TEST(TestCallback, BasicTest)
{
    // HelperClass hc; // this one allows only access to the private variable member
    MockHelper hc; // this one allows access to the private variable member and method
    EXPECT_CALL(hc, increaseConnectionCount());
    
    MockDatabaseConnection mdb("127.0.0.1", &hc);
    EXPECT_CALL(mdb, onConnect());

    mdb.connect();
    
}

//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}