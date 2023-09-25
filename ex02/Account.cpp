#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created" << std::endl;

    Account::_accountIndex = Account::_nbAccounts;
    Account::_amount = initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_totalNbDeposits = 0;
    Account::_totalNbWithdrawals = 0;
    return ;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "closed" << std::endl;
    return ;
}

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
    return ;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount = Account::_amount;
    Account::_amount += deposit;
    Account::_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
    return ;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "p_amount:" << Account::_amount << ";";
    if (Account::_amount < withdrawal)
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
    else
    {
        Account::_amount -= withdrawal;
        Account::_nbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals += 1;
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << Account::_amount << ";";
        std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
        return (true);
    }
    return (true);
}

int Account::checkAmount( void ) const
{
    return (Account::_amount);
}

void    Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "deposits:" << Account::_nbDeposits << ";";
    std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
    return ;
}

void	Account::_displayTimestamp( void )
{
    std::time_t currentTime = std::time(0);
    std::tm* timeInfo = std::localtime(&currentTime);
    int cur_year = timeInfo->tm_year + 1900;
    int cur_mon = timeInfo->tm_mon + 1;
    int cur_day = timeInfo->tm_mday;
    int cur_hour = timeInfo->tm_hour;
    int cur_min = timeInfo->tm_min;
    int cur_sec = timeInfo->tm_sec;

    std::cout << "[";
    std::cout << std::setw(2) << std::setfill('0') << cur_year;
    std::cout << std::setw(2) << std::setfill('0') << cur_mon;
    std::cout << std::setw(2) << std::setfill('0') << cur_day;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << cur_hour;
    std::cout << std::setw(2) << std::setfill('0') << cur_min;
    std::cout << std::setw(2) << std::setfill('0') << cur_sec;
    std::cout << "]" << " ";

    return ;
}