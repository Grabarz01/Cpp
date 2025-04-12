/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:38:21 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 15:24:11 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::cout << "---------New Bureaucrat---------\n";
  Bureaucrat filip("Filip", 10);
  ShrubberyCreationForm tree("home");
  PresidentialPardonForm president("42");
  RobotomyRequestForm test;
  filip.signForm(tree);
  filip.signForm(president);
  filip.signForm(test);

  std::cout << "---------Execution---------\n";
  tree.execute(filip);
  filip.executeForm(president);
  filip.executeForm(test);
}