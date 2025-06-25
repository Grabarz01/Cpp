/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:49:21 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 09:20:06 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data{
	std::string name;
	int value; 
};

class Serializer
{
private:
	Serializer();
public:
	~Serializer();
  Serializer(const Serializer& other);
  const Serializer& operator=(const Serializer& other);
	
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


#endif
