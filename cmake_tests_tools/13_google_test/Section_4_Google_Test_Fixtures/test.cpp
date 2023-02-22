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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
