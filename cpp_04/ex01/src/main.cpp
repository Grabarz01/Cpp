/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:06:23 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 20:43:34 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	Animal* animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
		
	for (int i = 0; i < 5; i++)
		animals[i+5] = new Dog();
	
	for (int i = 0; i < 10; i++){
		std::cout << i << ".";
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < 10; i++)
        delete animals[i];
	return 0;
}