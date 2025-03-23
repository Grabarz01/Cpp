/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:06:23 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/23 21:49:53 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define ANIMALS 10
#define HALF 5
int main()
{
	Animal* animals[ANIMALS];
	for (int i = 0; i < HALF; i++)
		animals[i] = new Cat();
		
	for (int i = 0; i < HALF; i++)
		animals[i + HALF] = new Dog();
	
	for (int i = 0; i < ANIMALS; i++){
		std::cout << i + 1 << ".";
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < ANIMALS; i++)
        delete animals[i];
	return 0;

	Dog basic;
	{
		Dog tmp = basic;
	}
}