/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:28:15 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 21:06:29 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal("Dog")
{
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}
Dog& Dog::operator= (const Dog& other)
{
	std::cout << "Dog overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	Animal::operator= (other);
	return (*this);
}