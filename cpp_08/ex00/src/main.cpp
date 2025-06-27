/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:04:28 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 11:33:33 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(16);
	vec.push_back(8);

	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(5);
	deq.push_back(16);
	deq.push_back(8);

	std::vector<char> wrong;
	wrong.push_back('1');
	wrong.push_back('2');
	wrong.push_back('3');
	try {
		std::cout << easyfind(vec,5) << std::endl;
		std::cout << easyfind(deq,5)<< std::endl;
		std::cout << easyfind(wrong,2)<< std::endl;
	}	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

}