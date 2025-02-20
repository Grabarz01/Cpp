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
	int N = 7;
	Zombie *horde_fiats = zombieHorde(N,"Fiat");
	for (int i = 0; i<N ; i++)
		horde_fiats[i].announce();
	delete []horde_fiats;
}