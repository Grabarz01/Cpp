/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:18:53 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/18 22:07:58 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

#define RIP "ClapTrap is dead"
#define NO_ENERGY "ClapTrap is out of energy"
class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints;
	int _attackDamage;
	int _energyPoints;
	
	bool isAbleToAct(void);
	bool isAlive(void);
	bool hasEnergy(void);
	
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	ClapTrap& operator= (const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setName(std::string _name);
	std::string& getName(void);
};


#endif