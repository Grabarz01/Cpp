/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:05:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/06 16:02:49 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed
{
private:
	int _value;
	static const int _fracBits = 8;
	
public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);
	
	
	Fixed& operator= (const Fixed& other);
	bool operator> (const Fixed& other) const;
	bool operator< (const Fixed& other) const;
	bool operator>= (const Fixed& other) const;
	bool operator<= (const Fixed& other) const;
	bool operator== (const Fixed& other) const;
	bool operator!= (const Fixed& other) const;

	Fixed operator+ (const Fixed& other);
	Fixed operator- (const Fixed& other);
	Fixed operator* (const Fixed& other);
	Fixed operator/ (const Fixed& other);

	Fixed& operator ++();
	Fixed operator ++(int);

	Fixed& operator --();
	Fixed operator --(int);

	static const Fixed& min(const Fixed& first, const Fixed& second);
	static const Fixed& min(Fixed& first, Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);
	static const Fixed& max(Fixed& first, Fixed& second);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif