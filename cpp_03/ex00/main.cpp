/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:18:49 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 10:00:05 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b(a);
	
	a.attack("Maciek");
	b.takeDamage(10);
	b.attack("Filip");
	b.beRepaired(5);
	b.attack("Maciek");
}