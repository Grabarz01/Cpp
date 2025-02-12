/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:58:15 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/12 14:04:43 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <vector>

void Harl::debug(void)
{
	std::cout <<  "[ DEBUG ]\nI love having extra bacon for my\n"
				<< "7XL-double-cheese-triple-pickle-special-\n"
					<< "ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger!\n"
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you\n"
				<< "started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG","INFO","WARNING","ERROR"};
	void (Harl::*fun[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int index = -1;
	
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break;
		}
	}
	
	switch (index)
	{
		case 0: 
			(this->*fun[0])(); //fall through
		case 1:
			(this->*fun[1])(); //fall through
		case 2:
			(this->*fun[2])(); //fall through
		case 3:
			(this->*fun[3])(); break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}