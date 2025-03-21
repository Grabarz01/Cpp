/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:28:15 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 19:34:00 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

const Dog& Dog::operator= (const Dog& other)
{
	std::cout << "Dog overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	Animal::operator= (other);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << getType() << " says: BARK BARK" << std::endl;
}
