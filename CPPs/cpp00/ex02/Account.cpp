#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
		- deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year << (ltm->tm_mon
		+ 1 < 10 ? "0" : "") << 1
		+ ltm->tm_mon << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "_" << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] ";
}
