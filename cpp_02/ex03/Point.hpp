/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:22 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/06 18:32:16 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& other);
	~Point(void);
	
	Point& operator= (const Point& other);



};

#endif