/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:28:15 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/23 21:27:03 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

Dog::Dog(void)
{
	_brain = new Brain;
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*(other._brain));
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

const Dog& Dog::operator= (const Dog& other)
{
	std::cout << "Dog overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	Animal::operator= (other);
	
	if (_brain)
		delete _brain;
	_brain = new Brain(*(other._brain));
	
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << getType() << " says: BARK BARK" << std::endl;
}
