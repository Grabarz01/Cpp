/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:37:41 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 09:01:18 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
	private:
  T* _arr;
  unsigned int _size;
	
	public:
  Array();
  Array(unsigned int n);
  Array(const Array<T>& other);
	
  ~Array();
	
  const Array<T>& operator=(const Array<T>& other);
  T& operator[](unsigned int n) const;
	
  unsigned int size() const;
};

#include "Array.tpp"


#endif