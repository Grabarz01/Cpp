/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 19:24:49 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal("Cat")
{
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}
Cat& Cat::operator= (const Cat& other)
{
	std::cout << "Cat overloaded operator called" << std::endl;
	if (&other == this)
		return (*this);
	Animal::operator= (other);
	return (*this);
}