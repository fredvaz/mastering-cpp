#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include "LibraryCode.hpp"

//

TEST(AccountTest, TestEmptyAccount)
{
    Account account;

    double balance = account.get_balance();

    ASSERT_EQ(0, balance);
}

// Test Fixture:
class AccountTestFixture : public testing::Test
{
public:
    AccountTestFixture();
    virtual ~AccountTestFixture();
    void SetUp() override;
    void TearDown() override;
    static void SetUpTestCase();     // Must be static
    static void TearDownTestSuite(); // Must be static


protected:
    Account *account;
};

AccountTestFixture::AccountTestFixture()
{
    std::cout << "Constructor called\n";
}

AccountTestFixture::~AccountTestFixture()
{
    std::cout << "Destructor called\n";
}

// Reuse of the Test Code
void AccountTestFixture::SetUp()
{
    std::cout << "SetUp called\n";

    // When for example a member variable is a pointer
    account = new Account();
    account->deposit(10.5);
}

void AccountTestFixture::TearDown()
{
    std::cout << "TearDown called\n";

    // When for example a member variable is a pointer
    delete account;
}

// This method is called in the begining of the Tests
void AccountTestFixture::SetUpTestCase()
{
    std::cout << "SetUpTestCase called\n";
}

// This method is called in the end of the Tests
void AccountTestFixture::TearDownTestSuite()
{
    std::cout << "TearDownTestSuite called\n";
}

// Markdown TEST_F
TEST_F(AccountTestFixture, TestDeposit)
{
    // The below code is now redudant
    // Account account;
    // account.deposit(10.5);
    std::cout << "Test body\n";
    ASSERT_EQ(10.5, account->get_balance());
}

TEST_F(AccountTestFixture, TestWithdrawOK)
{

    account->withdraw(3);

    ASSERT_EQ(7.5, account->get_balance());
}

TEST_F(AccountTestFixture, TestWithdrawInsufficientFunds)
{

    ASSERT_THROW(account->withdraw(300), std::runtime_error);
}

TEST_F(AccountTestFixture, TestTransferOK)
{

    Account to;

    account->transfer(to, 2);

    ASSERT_EQ(8.5, account->get_balance());
    ASSERT_EQ(2, to.get_balance());
}

TEST_F(AccountTestFixture, TestTransferInsufficientFunds)
{

    Account to;

    ASSERT_THROW(account->transfer(to, 200), std::runtime_error);
}

//
// Parameterized Tests

// Validator(5, 10)
// 4, 5, 6, 7, 9, 10, 11

class ValidatorFixture: public testing::TestWithParam<int>
{
public:

protected:
    Validator mValidator{5, 10};

};

// Test Body
TEST_P(ValidatorFixture, TestInRange)
{
    int param = GetParam();
    std::cout << "Param = " << param << std::endl;

    bool isInside = mValidator.inRange(param);

    ASSERT_TRUE(isInside);
}

// Test Suite with 5 Test Cases
INSTANTIATE_TEST_SUITE_P(InRangeTrue, ValidatorFixture, testing::Values(5, 6, 7, 9, 10));
// INSTANTIATE_TEST_CASE_P(InRangeTrue, ValidatorFixture, Values(5, 6, 7, 9, 10));


// Another Example
class ValidatorNegativeFixture: public testing::TestWithParam<int>
{
public:

protected:
    Validator mValidator{5, 10};

};

// Test Body
TEST_P(ValidatorNegativeFixture, TestNotInRange)
{
    int param = GetParam();
    std::cout << "Param (not in range) = " << param << std::endl;

    bool isInside = mValidator.inRange(param);

    ASSERT_FALSE(isInside);
}

INSTANTIATE_TEST_SUITE_P(InRangeFalse, ValidatorNegativeFixture, testing::Values(-50, 4, 11, 100));

//

class ValidatorFixture2: public testing::TestWithParam<std::tuple<int, bool>>
{
public:

protected:
    Validator mValidator{5, 10};

};

// Test Body
TEST_P(ValidatorFixture2, TestInRange2)
{
    std::tuple<int, bool> tuple = GetParam();

    int param = std::get<0>(tuple);

    bool expectedValue = std::get<1>(tuple);

    std::cout << "Param = " << param << " Expected value: " << expectedValue << std::endl;

    bool isInside = mValidator.inRange(param);

    ASSERT_EQ(expectedValue, isInside);
}

// Test Suite with 5 Test Cases
INSTANTIATE_TEST_SUITE_P(InRangeTrue2, ValidatorFixture2, testing::Values(
                                                            std::make_tuple(-50, false),
                                                            std::make_tuple(4, false),
                                                            std::make_tuple(5, true),
                                                            std::make_tuple(6, true), 
                                                            std::make_tuple(7, true), 
                                                            std::make_tuple(9, true), 
                                                            std::make_tuple(10, true),
                                                            std::make_tuple(11, false),
                                                            std::make_tuple(100, false)));


//

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
