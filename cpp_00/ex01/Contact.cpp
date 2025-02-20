/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:18:19 by fgrabows          #+#    #+#             */
/*   Updated: 2025/01/30 10:56:52 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

std::string SafeStringInput(void);

void Contact::Add(void)
{
	std::cout << "Insert First Name: ";
	this->_first_name = SafeStringInput();
	std::cout << "Insert Last Name: ";
	this->_last_name = SafeStringInput();
	std::cout << "Insert Phone Number: ";
	this->_phone_number = SafeStringInput();
	std::cout << "Insert Nickname: ";
	this->_nickname = SafeStringInput();
	std::cout << "Insert Darkeset Secret: ";
	this->_darkest_secret = SafeStringInput();
	
};

std::string Contact::GetFirstName() const
{
	return _first_name;
}

std::string Contact::GetSecondName() const
{
	return _last_name;	
}

std::string Contact::GetPhoneNumber() const
{
	return _phone_number;
}

std::string Contact::GetSecret() const
{
	return _darkest_secret;
}

std::string Contact::GetNickname() const
{
	return _nickname;
}
