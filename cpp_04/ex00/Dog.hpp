/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:30:31 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 21:22:05 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(std::string name);
	Dog(const Dog& other);

	const Dog& operator= (const Dog& other);
	
	void makeSound(void);
	
};

#endif