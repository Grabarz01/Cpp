/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:22:13 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 15:31:17 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp; 
}

template <typename T>
T min(T &a, T &b){
	if (a < b)
		return a;
	else 
		return b;
}

template <typename T>
T max(T &a, T &b){
	if (a > b)
		return a;
	else 
		return b;
}
