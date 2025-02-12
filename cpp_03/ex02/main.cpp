/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:18:49 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 14:15:51 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a("Boss");
	FragTrap b("Kloss");
	FragTrap c = b;
	FragTrap d;

	a.attack("Mario");
	b.highFivesGuys();
	c.highFivesGuys();
	d.beRepaired(24);
	
}