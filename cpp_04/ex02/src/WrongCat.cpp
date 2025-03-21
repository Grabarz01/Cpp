/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 19:56:57 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}
const WrongCat& WrongCat::operator= (const WrongCat& other)
{
	std::cout << "WrongCat overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	WrongAnimal::operator= (other);
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << getType() << " says: MEEEOOW" << std::endl;
}