/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:28:53 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 19:55:15 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	WrongAnimal& operator= (const WrongAnimal& other);

	void makeSound(void) const;
	const std::string& getType(void) const;
	

};

#endif