/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:32:06 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 08:52:31 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

int main(){
	char str[7] = "warsaw";
	int tab[5] = {1,2,3,4,5};
	std::string remember[4] = {"warsaw", "is", "really", "nice"};

	iter<char>(str, 6, printValue);
	iter<int>(tab, 5, printValue);
	iter<std::string>(remember, 4, printValue);

}