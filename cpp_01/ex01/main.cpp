/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:27:55 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/03 14:55:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *horde_fiats = zombieHorde(7,"Fiat");
	delete []horde_fiats;
}