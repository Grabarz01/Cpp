/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:21:27 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 11:37:24 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
int easyfind(T &arr, int num){
	typename T::iterator it = std::find(arr.begin(), arr.end(), num);
	if (it != arr.end())
		return std::distance(arr.begin(), it);
	throw std::runtime_error("Value not found");
}

#endif

//typename says thats the type not other thing