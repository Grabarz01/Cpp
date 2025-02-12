/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:32:06 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/06 18:37:16 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float trianglArea (const Point p1, const Point p2, const Point p3)
{
	Point vec_ab = 
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float d0, d1, d2, d3;
	bool ret_val = false;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);

	if ( d1 == 0 || d2 == 0 || d3 == 0)
		ret_val = false;
	else if ( d1 + d2 + d3 == d0 )
		ret_val = true;

	return (ret_val);
}