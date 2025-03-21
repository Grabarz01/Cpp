/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 19:34:46 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}
const Cat& Cat::operator= (const Cat& other)
{
	std::cout << "Cat overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	Animal::operator= (other);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << getType() << " says: MEEEOOW" << std::endl;
}