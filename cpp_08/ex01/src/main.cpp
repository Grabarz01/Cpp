/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:44:04 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/26 20:10:30 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime> 

int main(){
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;

/*	
	srand(time(0));

	std::cout << "Expected: Array is full" << std::endl;
	try {
		Span obj(0);
		obj.addNumber(10);
		std::cout << obj.longestSpan() << std::endl;
		std::cout << obj.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "--------------------------" << std::endl;
	std::cout << "Expected: Not enough nubers to find the span" << std::endl;

	try {
		Span obj(10);
		obj.addNumber(10);
		std::cout << "Longest span: "<< obj.longestSpan() << std::endl;
		std::cout << "Shortest span: "<< obj.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;
	std::cout << "Expected: 1 | 1" << std::endl;

	try {
		Span obj(10);
		obj.addNumber(10);
		obj.addNumber(11);
		std::cout << "Longest span: "<< obj.longestSpan() << std::endl;
		std::cout << "Shortest span: "<< obj.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "--------------------------" << std::endl;
	std::cout << "Expected: 2137483648 | 10000000" << std::endl;

	try {
		Span obj(10);
		obj.addNumber(10000000);
		obj.addNumber(0);
		obj.addNumber(INT_MIN);
		std::cout << "Longest span: "<< obj.longestSpan() << std::endl;
		std::cout << "Shortest span: "<< obj.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;
	std::cout << "Expected: 4294967295 | 4294967295" << std::endl;
	
	try {
		Span obj(10);
		obj.addNumber(INT_MAX);
		obj.addNumber(INT_MIN);
		std::cout << "Longest span: "<< obj.longestSpan() << std::endl;
		std::cout << "Shortest span: "<< obj.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try {
		Span obj(100000);
		for (int i = 0; i < 100; i++){
			obj.addNumber(rand() % 10000000 - 10000);
		}
		std::cout << "Longest span: "<< obj.longestSpan() << std::endl;
		std::cout << "Shortest span: "<< obj.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;

	std::cout << static_cast<long>(INT_MAX) - INT_MIN << std::endl;
*/}