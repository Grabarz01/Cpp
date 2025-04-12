/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:46:16 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 14:59:57 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", false, 145, 137), target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", false, 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (&other == this)
    return *this;
  AForm::operator=(other);
  this->target = other.target;
  return *this;
}

void ShrubberyCreationForm::runForm() const {
  std::cout << "ShrubberyCreationForm execution" << std::endl;
  std::ofstream file((this->target + "_shrubbery").c_str());
  if (file.is_open()) {
    file << " ,d\n"
    << " 88\n"
    << "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba, \n"
    << " 88    88P\'   \"Y8 a8P_____88 a8P_____88  \n"
    << " 88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  \n"
    << " 88,   88         \"8b,   ,aa \"8b,   ,aa  \n"
    << " \"Y888 88          `\"Ybbd8\"\'  `\"Ybbd8\"\'\n";
	file.close();
  } else
    std::cerr << "Cannot open file" << std::endl;
}
