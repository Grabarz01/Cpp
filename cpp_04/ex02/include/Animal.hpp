/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:28:53 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 20:50:31 by fgrabows         ###   ########.fr       */
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
	Animal(const Animal& other);
	virtual ~Animal(void);

	Animal& operator= (const Animal& other);

	virtual void makeSound(void) const = 0;
	const std::string& getType(void) const;
	

};

#endif