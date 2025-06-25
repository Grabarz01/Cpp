/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:19:48 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 11:55:13 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv)
{
  if (argc != 2)
	{
		std::cout << "One Argument required." << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;

	
  /*TESTS*/
	/*
	//valid special lterals 
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("nan");

	//valid int literals
	ScalarConverter::convert("0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-17");
	ScalarConverter::convert("+123");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("-2147483648");

	//invalid int literals
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("99999999999");

	//valid float literals
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("1.23f");
	ScalarConverter::convert("-42.5f");
	ScalarConverter::convert("+3.14f");
	ScalarConverter::convert("123456.789f");
	ScalarConverter::convert("0.f");
	ScalarConverter::convert(".5f");
	ScalarConverter::convert("-0.001f");
	ScalarConverter::convert("1.2f");

	// Valid double literals
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("-42.5");
	ScalarConverter::convert("+3.14159");
	ScalarConverter::convert(".1");
	ScalarConverter::convert("1.");
	ScalarConverter::convert("123456.789");
	ScalarConverter::convert("-0.00001");

	// Invalid/wrong inputs
	ScalarConverter::convert("1.2.3");
	ScalarConverter::convert("12f");
	ScalarConverter::convert("abc"); 
	ScalarConverter::convert("1e309");  
	ScalarConverter::convert("..1");  
	ScalarConverter::convert("1..");      
	ScalarConverter::convert("1.2.3.4");*/
}