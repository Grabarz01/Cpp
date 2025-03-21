/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:28:24 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 19:54:36 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("Unknown")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	std::cout << "WrongAnimal overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	this->_type = other._type;
	return(*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Some unknown sound..." << std::endl;
}
const std::string& WrongAnimal::getType(void) const
{
	return _type;
}
