/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:07:23 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/05 13:37:33 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <exception>

#define MAX_FIXED 8388600
#define MIN_FIXED -8388600

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
	if (intValue > INT_MAX || intValue < INT_MIN){
		std::cout << "Too big value for this variable type" << std::endl;
		exit(1);
	}
    else 
		_value = intValue << _fracBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	if(MAX_FIXED > floatValue || MIN_FIXED > floatValue){
		std::cout << "Too big value for this variable type" << std::endl;
		exit(1);
	}
	else
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