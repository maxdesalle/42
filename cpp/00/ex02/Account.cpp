/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:10:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/18 14:03:58 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void	timer(void)
{
	const time_t	t = std::time(nullptr);
	tm 				timestamp = *std::localtime(&t);
	std::cout << "[" << std::put_time(&timestamp, "%Y%m%d_%H%M%S") << "]";
}

int			Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int			Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int			Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int			Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void		Account::displayAccountsInfos(void)
{
	timer();
	std::cout << " accounts:";
	std::cout << getNbAccounts();
	std::cout << ";total:";
	std::cout << getTotalAmount();
	std::cout << ";deposits:";
	std::cout << getNbDeposits();
	std::cout << ";withdrawals:";
	std::cout << getNbWithdrawals();
	std::cout << std::endl;
}

Account::~Account(void)
{
	timer();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";amount:";
	std::cout << _amount;
	std::cout << ";closed";
	std::cout << std::endl;
}

Account::Account(int initial_deposit): _amount(initial_deposit)
{
	timer();
	_accountIndex = _nbAccounts;
	std::cout << " index:";
	std::cout << _nbAccounts;
	std::cout << ";amount:";
	std::cout << initial_deposit;
	std::cout << ";created";
	std::cout << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts += 1;
}

void		Account::makeDeposit(int deposit)
{
	timer();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";p_amount:";
	std::cout << _amount;
	std::cout << ";deposit:";
	std::cout << deposit;
	std::cout << ";amount:";
	_amount += deposit;
	std::cout << _amount;
	_nbDeposits += 1;
	std::cout << ";nb_deposits:";
	std::cout << _nbDeposits;
	std::cout << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	timer();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";p_amount:";
	std::cout << _amount;
	std::cout << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused";
		std::cout << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:";
	std::cout << _amount;
	_nbWithdrawals += 1;
	std::cout << "nb_withdrawals:";
	std::cout << _nbWithdrawals;
	std::cout << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	return (true);
}

int			Account::checkAmount(void) const
{
	return (_amount);
}

void		Account::displayStatus(void) const
{
	timer();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";amount:";
	std::cout << _amount;
	std::cout << ";deposits:";
	std::cout << _nbDeposits;
	std::cout << ";withdrawals:";
	std::cout << _nbWithdrawals;
	std::cout << std::endl;
}
