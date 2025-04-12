/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:38:21 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 17:26:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::cout << "---------New Bureaucrat---------\n";
  Bureaucrat filip("Filip", 10);
  ShrubberyCreationForm tree("home");
  Intern tytus;
  AForm* president = NULL;
  RobotomyRequestForm test;
  filip.signForm(tree);
  filip.signForm(test);

  std::cout << "---------Execution---------\n";
  tree.execute(filip);
  filip.executeForm(test);

  std::cout << "--------->>>>Intern<<<<------------\n";
  std::cout << "----------Right-----------\n";
  std::string form = "PresidentialPardonForm";
  std::string target = "";
  president = tytus.makeForm(form, target);
  filip.signForm(*president);
  filip.executeForm(*president);
  delete president;
  std::cout << "----------Wrong-----------\n";
  form = "sth";
  president = tytus.makeForm(form, target);
  if (president) {
    filip.signForm(*president);
    filip.executeForm(*president);
  }
  else
  	std::cout << "The Form has not been created" << std::endl;
}