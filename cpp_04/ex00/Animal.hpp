/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:28:53 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 19:30:14 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal& other);

	Animal& operator= (const Animal& other);

	void makeSound(void);

};

#endif