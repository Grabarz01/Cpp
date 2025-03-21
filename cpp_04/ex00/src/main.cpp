/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:06:23 by fgrabows          #+#    #+#             */
/*   Updated: 2025/03/20 20:12:23 by fgrabows         ###   ########.fr       */
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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "--------Wrong animals below-----------" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* jeta = new WrongCat();
	beta->makeSound();
	jeta->makeSound();

	delete beta;
	delete jeta;
	
	return 0;
}