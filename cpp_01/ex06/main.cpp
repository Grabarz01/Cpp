/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:58:22 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/04 15:32:23 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>
int main(int argc, char** argv)
{
	
	if (argc == 2)
	{
		Harl harl;
		harl.complain(std::string(argv[1]));
	}
	else 
		std::cout << "Harl accepts only one argument, no more no less" << std::endl; 
}