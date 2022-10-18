#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
    _displayTimestamp();
    _accountIndex = Account::_nbAccounts;
    _amount = 0;
    Account::_nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

Account::Account(int firstDeposit)
{
    _displayTimestamp();
    _accountIndex = Account::_nbAccounts;
    _amount = firstDeposit;
    Account::_totalAmount += _amount;
    Account::_nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount << ";closed" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    Account::_totalAmount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount
        << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int     Account::checkAmount() const
{
    return (_amount);
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount << ";deposits:" << _nbDeposits
        << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int     Account::getNbAccounts()
{
    return(Account::_nbAccounts);
}

int     Account::getTotalAmount()
{
    return(Account::_totalAmount);
}

int     Account::getNbWithdrawals()
{
    return(Account::_totalNbWithdrawals);
}

int     Account::getNbDeposits()
{
    return(Account::_totalNbDeposits);
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts
        << ";total:" << Account::_totalAmount
        << ";deposits:" << Account::_totalNbDeposits
        << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void    Account::_displayTimestamp()
{
    time_t  t = time(NULL);
    tm      *now = localtime(&t);

    std::cout << std::setfill('0') << "[" << (1900 + now->tm_year) << std::setw(2) << (now->tm_mon + 1)
    << std::setw(2) << now->tm_mday << "_" << std::setw(2) << now->tm_hour
    << std::setw(2) << now->tm_min << std::setw(2) << now->tm_sec << "] ";
}
