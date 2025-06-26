/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:32:09 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 16:08:28 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T *arr, int len, void(*f)(T const&))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void printValue(T const& a){
	std::cout << a << std::endl;
}