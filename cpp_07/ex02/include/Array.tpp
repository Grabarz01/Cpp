/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:50:17 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 09:05:42 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#include <iostream>

template <typename T>
Array<T>::Array() : _arr(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other)
    : _arr(new T[other._size]), _size(other._size) {
  for (unsigned int i = 0; i < _size; i++) {
    _arr[i] = other._arr[i];
  }
}

template <typename T>
Array<T>::~Array() {
  delete[] _arr;
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& other) {
  if (&other == this)
    return *this;
  delete[] _arr;
  _arr = new T[other.size];
  _size = other.size;
  for (unsigned int i = 0; i < _size; i++) {
    _arr[i] = other._arr[i];
  }
	return *this;
}
template <typename T>
T& Array<T>::operator[](unsigned int n) const {
  if (n >= this->_size)
    throw std::out_of_range("Array index out of range");
  return _arr[n];
}

template <typename T>
unsigned int Array<T>::size() const {
  return this->_size;
}


