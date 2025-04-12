/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:38:21 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/02 19:48:10 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main()
{
	//-------------------------------------------------
    try {
		std::cout << "---------New Bureaucrat---------\n";
        Bureaucrat a("Filip", 150);
    	std::cout << a;
        a.gradeIncrement();
        std::cout << a;
        a.gradeDecrement();
        std::cout << a;
        a.gradeDecrement();
    }
    catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
    }
	
	//-------------------------------------------------
	try {
		std::cout << "---------New Bureaucrat---------\n";
        Bureaucrat a("Filip", 151);
    	std::cout << a;
        a.gradeIncrement();
        std::cout << a;
        a.gradeDecrement();
        std::cout << a;
        a.gradeDecrement();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
    }

	//-------------------------------------------------
	try {
		std::cout << "---------New Bureaucrat---------\n";
        Bureaucrat a("Filip", 0);
    	std::cout << a;
        a.gradeIncrement();
        std::cout << a;
        a.gradeDecrement();
        std::cout << a;
        a.gradeDecrement();

    }
    catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
    }
	
	//-------------------------------------------------
	try {
		std::cout << "---------New Bureaucrat---------\n";
		Bureaucrat a("Filip", -150);
    	std::cout << a;
        a.gradeIncrement();
        std::cout << a;
        a.gradeDecrement();
        std::cout << a;
        a.gradeDecrement();

    }
    catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
    }

	//-------------------------------------------------
	try {
		std::cout << "---------New Bureaucrat---------\n";
		Bureaucrat a("Filip", 1);
		std::cout << a;
		a.gradeIncrement();
		std::cout << a;
		a.gradeDecrement();
		std::cout << a;
		a.gradeDecrement();

	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	//-------------------------------------------------
	try {
		std::cout << "---------New Bureaucrat---------\n";
		Bureaucrat a("Filip", 1);
		std::cout << a;
		std::cout << "---------Honest Bureaucrat---------\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}