/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:58:15 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/04 15:34:42 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <vector>

void Harl::debug(void)
{
	std::cout <<  "[DEBUG]\nI love having extra bacon for my\n"
				<< "7XL-double-cheese-triple-pickle-special-\n"
					<< "ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger!\n"
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you\n"
				<< "started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG","INFO","WARNING","ERROR"};
	void (Harl::*fun[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*fun[i])();
			return;
		}
	}
	std::cout << "[INVALID]\nInvalid complaint level" << std::endl;
	
}