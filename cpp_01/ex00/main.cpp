/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:27:55 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/03 15:08:47 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void)
{
	Zombie braian("Braian");
	braian.announce();
	Zombie filip("Filip");
	filip.announce();
	
	Zombie *john = newZombie("John");
	john->announce();
	delete john;
	
	randomChump("Fred");
}