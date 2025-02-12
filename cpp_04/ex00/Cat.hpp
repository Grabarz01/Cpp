/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:30:28 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/07 19:27:19 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(std::string name);
	Cat(const Cat& other);

	const Cat& operator= (const Cat& other);
	
	void makeSound(void);
	
};

#endif