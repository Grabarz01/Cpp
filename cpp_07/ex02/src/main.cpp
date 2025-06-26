/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 07:39:33 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 09:14:43 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(){
	Array <int>a;
	try{
		std::cout << "a Array" << std::endl;
		std::cout << "Size: " << a.size() <<  std::endl;
		std::cout << a[0] << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	Array <int>b = a;
	try{
		std::cout << "b Array" << std::endl;
		std::cout << "Size: " << b.size() <<  std::endl;
		std::cout << b[0] << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl;
	Array<char> c(10);
	try{
		std::cout << "c Array" << std::endl;
		std::cout << "Size: " << c.size() <<  std::endl;
		std::cout << c[0] << std::endl;
		std::cout << c[10] << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl;
	Array<char> d = c;
	try{
		std::cout << "d Array" << std::endl;
		std::cout << "Size: " << d.size() <<  std::endl;
		std::cout << d[0] << std::endl;
		std::cout << d[10] << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Changing copy does not influence the base instance" << std::endl;
	std::cout << "d[5] before change: " << d[5] << std::endl; 
	std::cout << "c[5] before change: " << c[5] << std::endl;
	d[5] = 'z';
	std::cout << "d[5] after change:" << d[5] << std::endl;
	std::cout << "c[5] after change:" << c[5] << std::endl;
	std::cout << "_" << char() << "_" << std::endl;

}