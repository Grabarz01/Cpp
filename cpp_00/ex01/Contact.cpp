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

std::string Contact::GetArgument(std::string arg) const
{
	if(arg == "f_name")
		return _first_name;
	else if(arg == "l_name")
		return _last_name;
	else if(arg == "number")
		return _phone_number;
	else if(arg == "nickname")
		return _nickname;
	else if(arg == "secret")
		return _darkest_secret;
	else 
		return("#Wrong arg#\n");
}
