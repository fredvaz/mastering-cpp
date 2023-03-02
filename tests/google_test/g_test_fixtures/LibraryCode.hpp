#pragma once

class Account
{
public:
    Account();
    void deposit(double sum);
    void withdraw(double sum);
    double get_balance() const;
    void transfer(Account &to, double sum);

private:
    double m_balance;
};

class Validator
{
public:
    Validator(int low, int high);
    bool inRange(int value_to_test) const;

private:
    int m_low;
    int m_high;
};