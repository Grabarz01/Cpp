/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:01:32 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 12:05:25 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(){
	std::srand(std::time(0));
	Base* ptr = generate();
	Base& ref = *ptr;

	identify(ptr);
	identify(ref);
}

Base* generate(void) {
  int num = rand() % 3;
  switch (num) {
    case 0:
      std::cout << "Created A class" << std::endl;
      return new A;
    case 1:
      std::cout << "Created B class" << std::endl;
      return new B;
    case 2:
      std::cout << "Created C class" << std::endl;
      return new C;
		default:
			return NULL;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Identified A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Identified B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Identified C" << std::endl;
}

void identify(Base& p) {
  try {
		(void)dynamic_cast<A&>(p);
    std::cout << "Identified A" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  try {
		(void)dynamic_cast<B&>(p);
    std::cout << "Identified B" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  try {
		(void)dynamic_cast<C&>(p);
    std::cout << "Identified C" << std::endl;
    return;
  } catch (std::exception &e) {
  }
}

/*dynamic cast - runtime casting
  pointer - returns null if wrong
  reference - throws error if wrong
*/
