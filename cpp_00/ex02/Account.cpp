/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:03:25 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/03 13:22:10 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void )
{
	return _nbAccounts;	
}
int		Account::getTotalAmount( void )
{
	return _totalAmount;
}
int		Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int		Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) 
	:  _accountIndex(_nbAccounts), _amount(initial_deposit) 
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "amount:" << initial_deposit << ";"
				<< "created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	int p_amount = _amount;
	_amount += deposit;
	std:: cout << " index:" << _accountIndex << ";"	
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > checkAmount())
	{
		std::cout << " index:" << _accountIndex << ";"
					<< "p_amount:" << _amount << ";"
					<< "withdrawal:refused" << std::endl;
		return(false);
	}
	else
	{
		int p_amount = _amount;
		_amount = _amount - withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std:: cout << " index:" << _accountIndex << ";"	
				<< "p_amount:" << p_amount << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return(true);
	} 
}
int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now;
	std::tm* timeinfo;
	char buffer[20];	

	std::time(&now);
	timeinfo = std::localtime(&now);

	std::strftime(buffer, 20, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}