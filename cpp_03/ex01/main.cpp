/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:18:49 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/18 21:01:03 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a;
	ScavTrap ab;
	ScavTrap b(ab);
	
	a.attack("Maciek");
	b.takeDamage(10);
	b.attack("Filip");
	b.beRepaired(5);
	b.attack("Maciek");
	
}