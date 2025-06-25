/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:49:27 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 09:23:00 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main(){
	Data data;
	data.name = "Serializer";
	data.value = 1111;

	std::cout << "DATA" << std::endl;
	std::cout << "name: " << data.name<< std::endl; 
	std::cout << "value: " << data.value << std::endl; 

	std::cout << "----------------------" << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "data addres: " << &data << std::endl;

	std::cout << "----------------------" << std::endl;
	Data* deserializedData = Serializer::deserialize(ptr);
	std::cout << "Deserialized DATA" << std::endl;
	std::cout << "name: " << deserializedData->name<< std::endl; 
	std::cout << "value: " << deserializedData->value << std::endl; 
}