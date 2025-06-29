/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:30:02 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/29 12:23:19 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv){
	if (argc != 2){
		std::cout << "Wrong amount of arguments. Usage .RPN \"ARG\"" << std::endl;
		return 1;
	}
	try{
		RPN a(argv[1]);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	try {
		std::cout << "Expression: 3 4 + => ";
		RPN rpn1("3 4 +");

		std::cout << "Expression: 9 8 - => ";
		RPN rpn2("9 8 -");

		std::cout << "Expression: 6 2 / => ";
		RPN rpn3("6 2 /");

		std::cout << "Expression: 2 3 + 5 * => ";
		RPN rpn4("2 3 + 5 *");

		std::cout << "Expression: 2 3 4 + * => ";
		RPN rpn5("2 3 4 + *");

		std::cout << "Expression: 5 1 2 + 4 * + 3 - => ";
		RPN rpn6("5 1 2 + 4 * + 3 -"); 

	} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}