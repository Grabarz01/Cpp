/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:17:29 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/12 10:16:19 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

std::string TextCutter(std::string str);
std::string SafeStringInput(void);
int SafeIntInput(void);


int PhoneBook::_nr_of_contacts = 0;
int PhoneBook::_indicatro = 0;

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook got created <3" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook got destroyed :(" << std::endl;
}

void PhoneBook::AddContact()
{
	if (_nr_of_contacts == 8)
		std::cout << "The oldest contact got deleted\n";
	if (_indicatro == 8)
		_indicatro = 0;
	this->_contact[_indicatro].Add();
	_indicatro++;
	if(_nr_of_contacts < 8) 
		(_nr_of_contacts)++;
	if (_nr_of_contacts == 8)
		std::cout << "You reached the maximum number of contacts\n";
}

void PhoneBook::PrintContact(void) const
{
	int index;
	std::cout << "Which contact do you want? Insert the index:";
	while(1)
	{
		index = SafeIntInput();
		if(index < 0 || index >= _nr_of_contacts)
			std::cout << "Index is out of range.\nInsert index:";
		else
			break;
	}
	std::cout << "First name: " << this->_contact[index].GetArgument("f_name")
			<< "\nLast name: " << this->_contact[index].GetArgument("l_name")
			<< "\nNickname: " << this->_contact[index].GetArgument("nickname")
			<< "\nPhone number: " << this->_contact[index].GetArgument("number")
			<< "\nDarkest secret: " << this->_contact[index].GetArgument("secret")
			<< std::endl;
}

void PhoneBook::SearchContact() const
{
	std::string input;
	if(_nr_of_contacts == 0)
	{
		std::cout << "#No contacts to search#\n";
		return;
	}
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << "|\n" ;

	for(int i = 0; i < _nr_of_contacts; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) 
			<< TextCutter(this->_contact[i].GetArgument("f_name")) << "|";
		std::cout << std::right << std::setw(10) 
			<< TextCutter(this->_contact[i].GetArgument("l_name")) << "|";
		std::cout << std::right << std::setw(10) 
			<< TextCutter(this->_contact[i].GetArgument("nickname")) << "|\n";
	}
	this->PrintContact();
}
