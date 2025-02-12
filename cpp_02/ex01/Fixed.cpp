/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:07:23 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/06 14:24:01 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fracBits;
	
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _fracBits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fucntion called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fracBits);
}
int Fixed::toInt( void ) const
{
	return _value >> _fracBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return(os);
}