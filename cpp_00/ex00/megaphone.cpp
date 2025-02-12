/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:03 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/12 10:00:10 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void megaphone(const char *str)
{
	for (int i = 0; str[i]; i++)
	{	
		if (std::islower(str[i]))
			std::cout << static_cast<char>(toupper(str[i]));
		else
			std::cout << str[i];
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		megaphone(argv[i]);
	std::cout << std::endl;
}