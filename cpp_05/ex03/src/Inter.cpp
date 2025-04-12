/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:46:08 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 17:20:15 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) {
  (void)other;
}
Intern::~Intern() {}
const Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

AForm* createShrubbery(std::string& target) {
  if (target.empty())
    return new ShrubberyCreationForm();
  return new ShrubberyCreationForm(target);
}
AForm* createRobotomy(std::string& target) {
  if (target.empty())
    return new RobotomyRequestForm();
  return new RobotomyRequestForm(target);
}
AForm* createPresidential(std::string& target) {
  if (target.empty())
    return new PresidentialPardonForm();
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string& formName, std::string& target) {
  AForm* (*formsCreators[])(std::string&) = {
      createShrubbery, createPresidential, createRobotomy};
  std::string forms[] = {"ShrubberyCreationForm", "PresidentialPardonForm",
                         "RobotomyRequestForm"};
  for (int i = 0; i < 3; i++) {
    if (formName == forms[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      return formsCreators[i](target);
    }
  }
  std::cerr << "Unfortunately such a form does not exit" << std::endl;
  return NULL;
}
