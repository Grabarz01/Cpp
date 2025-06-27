/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:44:28 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 19:53:46 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <iterator>
#include <cmath>
#include <algorithm>

Span::Span() : _size(0) {}
Span::Span(unsigned int n) : _size(n) {}
Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
  if (&other == this)
    return *this;
  _arr.clear();
  _size = other._size;
  for (unsigned int i; i < other._arr.size(); i++) {
    _arr.push_back(other._arr[i]);
  }
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
  if (_arr.size() >= _size)
    throw std::runtime_error("Array is full");
  _arr.push_back(num);
}

unsigned int Span::shortestSpan() {
  if (_arr.size() < 2)
    throw std::runtime_error("Not enough nubers to find the span");
  std::vector<int> tmp_arr = _arr;
  std::sort(tmp_arr.begin(), tmp_arr.end());
  unsigned int diff = UINT_MAX;
  for (std::vector<int>::iterator it = tmp_arr.begin() + 1; it != tmp_arr.end(); it++) {
    unsigned int tmp = std::abs(static_cast<long>(*(it - 1)) - *it);
    if (diff > tmp)
      diff = tmp;
  }
  return diff;
}

unsigned int Span::longestSpan() {
  if (_arr.size() < 2)
    throw std::runtime_error("Not enough nubers to find the span");
  int min = *std::min_element(_arr.begin(),_arr.end());
	int max = *std::max_element(_arr.begin(),_arr.end());
	return std::abs(static_cast<long>(max) - min);
}

