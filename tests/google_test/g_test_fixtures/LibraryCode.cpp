#include "LibraryCode.hpp"
#include <stdexcept>

//

Account::Account() : m_balance{0}
{
}

void Account::deposit(double sum)
{
    m_balance += sum;
}

void Account::withdraw(double sum)
{
    if (m_balance < sum)
    {
        throw std::runtime_error("Insufficient funds");
    }
    m_balance -= sum;
}

double Account::get_balance() const
{
    return m_balance;
}

void Account::transfer(Account &to, double sum)
{
    withdraw(sum); // willl throw an error if not enough
    to.deposit(sum);
}

Validator::Validator(int low, int high) : m_low{low}, m_high{high}
{

}
bool Validator::inRange(int value_to_test) const
{
    return m_low <= value_to_test && value_to_test <= m_high;
}