/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:50:11 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/03 16:01:25 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "HI THIS IS BRAIN";
	string* stringPTR = &str;
	string& stringREF = str;

	cout << "The memory address of the string variable\t" << &str << endl;
	cout << "The memory address held by stringPTR\t" << stringPTR << endl;
	cout << "The memory address held by stringREF\t" << &stringREF << endl;

	cout << "The value of the string variable:\t" << str << endl;
	cout << "The value pointed to by stringPTR:\t" << *stringPTR << endl;
	cout << "The value pointed to by stringREF:\t" << stringREF << endl;
	
}