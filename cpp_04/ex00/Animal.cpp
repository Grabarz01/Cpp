/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:28:24 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 19:32:11 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Unknown")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}
Animal& Animal::operator= (const Animal& other)
{
	std::cout << "Animal overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	this->_type = other._type;
	return(*this);
}

void Animal::makeSound(void)
{
	std::cout << "Some unknown sound..." << std::endl;
}
