/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:18:15 by fgrabows          #+#    #+#             */
/*   Updated: 2025/08/13 20:11:37 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <exception>

//	./PmergeMe $(shuf -i 1-1000 -n 3000) 
// -r for duplicates 

int main(int argc, char** argv){
	try{
		PmergeMe pm(argc,argv);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}