#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>

//공유자원
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//initialization
Account::Account( int initial_deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";" << "amount:" << initial_deposit << ";" << "created" << std::endl;
    //각 계좌정보
    Account::_amount = initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_accountIndex = Account::_nbAccounts;

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_totalNbDeposits = 0;
    Account::_totalNbWithdrawals = 0;
    return ;
}
Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";" << "amount:" << Account::_amount << ";" << "closed" << std::endl;
    return ;
}

//public
//get data
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
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";" << "total:" << Account::_totalAmount << ";" << "deposits:" << Account::_totalNbDeposits << ";" << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
    return ;
}
//public
//make data
void	Account::makeDeposit( int deposit )
{
    Account::_nbDeposits += 1;
    int p_amount = Account::_amount;
    Account::_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    _displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposits:" << deposit << ";" << "amount:" << Account::_amount << ";" << "nb_deposit:" << Account::_nbDeposits << std::endl;
    return ;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount = Account::_amount;
    _displayTimestamp();
    if (Account::_amount < withdrawal)
    {
        std::cout << "index:" << Account::_accountIndex << ";" << "p_amount:" << p_amount << ";" << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
    Account::_nbWithdrawals += 1;
    Account::_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << "index:" << Account::_accountIndex << ";" << "p_amount:" << p_amount << ";" << "withdrawal:" << withdrawal << ";" << "amount:" << Account::_amount << ";" << "nb_Withdrawals:" << Account::_nbWithdrawals << std::endl;
    return (true);
}
int		Account::checkAmount( void ) const
{
    //????용도 모름
    return (0);
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";" << "amount:" << Account::_amount << ";" << "deposits:" << Account::_nbDeposits << ";" << "withdrawals:" << Account::_nbWithdrawals << std::endl;
    return ;
}


//private
//timestamp 출력
void	Account::_displayTimestamp( void )
{
    std::time_t currentTime = std::time(0); //time_t타입의 변수에 time함수사용하여 현재시간 얻음.
    std::tm* timeInfo = std::localtime(&currentTime);
    std::string padding = "0";

    std::cout << "[" << timeInfo->tm_year + 1900;
    if (timeInfo->tm_mon + 1 < 10)
         std::cout << padding;
    std::cout << timeInfo->tm_mon + 1;
    if (timeInfo->tm_mday < 10)
         std::cout << padding;
    std::cout << timeInfo->tm_mday << "_";
    if (timeInfo->tm_hour < 10)
         std::cout << padding;
    std::cout << timeInfo->tm_hour;
    if (timeInfo->tm_min < 10)
         std::cout << padding;
    std::cout << timeInfo->tm_min;
    if (timeInfo->tm_sec < 10)
         std::cout << padding;
    std::cout << timeInfo->tm_sec << "]" << " ";

    return ;
}
