/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:14 by fgrabows          #+#    #+#             */
/*   Updated: 2025/01/30 10:52:53 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>

#define INFO "You can:\n\
ADD a new contact\n\
SEARCH for a contact\n\
EXIT the program.\n"

std::string TextCutter(std::string str)
{
	int lenght = str.length();

	if(lenght > 10)
		return (str.substr(0,9).append("."));
	else 
		return str;
}
std::string SafeStringInput(void)
{
	std::string input;
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	while(!(std::cin >> input))
	{
		std::cerr << "Error reading input!\n";
		std::cout << "Try again:";	
	}
	return input;
}
int SafeIntInput(void)
{
	int number;
	while(!(std::cin >> number))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Wrong input. Try again:";
	}
	return number;
}
int main(void)
{
	PhoneBook phonebook;
	std::string input;
	
	std::cout << INFO;
	std::cin >> input;
	while(input != "EXIT")
	{
		if (input == "SEARCH")
			phonebook.SearchContact();
		else if (input == "ADD")
			phonebook.AddContact();
		else
			std::cout << "#Wrong input#" << std::endl;
		std::cout << INFO;
		std::cin >> input;
	}
}