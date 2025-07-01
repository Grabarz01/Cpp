/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:43:13 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/30 21:00:29 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int> _arr;
	unsigned int _size;
	
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span & operator=(const Span& other);
	~Span();

	void addNumbers(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end);
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif