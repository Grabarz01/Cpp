/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:05:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/06 13:08:38 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _value;
	static const int _fracBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	~Fixed(void);
	Fixed& operator= (const Fixed& other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};



#endif