/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:18:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 13:43:09 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(void) 
	: _name("Unknown hero"), _hitPoints(10), _attackDamage(2), _energyPoints(10)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
} 

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _attackDamage(2), _energyPoints(10)
{
	std::cout << "Claptrap Constructor with std::string called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Claptrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other)
{
	std::cout << "Claptrap Copy assignment operator called" << std::endl;
	if (this == &other)
			return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	return (*this);
}


void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << RIP << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " 
				<< target << ", causing " << _attackDamage 
				<< "points of damage!" << std::endl;
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!isAlive())
		return;
	else
	std::cout << "ClapTrap " << this->_name << " takes hard hit  " 
				<< ", causing " << amount 
				<< " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " died regarding"
					<< " taken damage" << std::endl;
		
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(!isAbleToAct())
		return;
	std::cout << "ClapTrap" << _name << "reapairs itself by " << amount
				<< " hit points" << std::endl;
	_hitPoints += amount;
	std::cout << "ClapTrap" << _name << "hp equals" << _hitPoints << std::endl;
}

bool ClapTrap::isAbleToAct(void)
{
	if (!isAlive())
		return (false);
	if (!hasEnergy())
		return (false);
	return (true);
}

bool ClapTrap::isAlive(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << RIP << std::endl;
		return (false);
	}
	return (true);
}

bool ClapTrap::hasEnergy(void)
{
	if (_energyPoints <= 0)
	{
		std::cout << NO_ENERGY << std::endl;
		return (false);
	}
	return (true);
}