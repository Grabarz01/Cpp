/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:17:10 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 15:18:05 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", false, 72, 45), target("default") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", false, 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (&other == this)
    return *this;
  AForm::operator=(other);
  this->target = other.target;
  return *this;
}

void RobotomyRequestForm::runForm() const {
	srand (time(NULL));
	std::cout << "Some weird noises...." << std::endl;
	std::cout << "https://www.youtube.com/watch?v=lNjXPml_PIU" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "Robotomy failed" << std::endl;
	else 
		std::cout << target << " has been robotomized" << std::endl;
		
  }
  