/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:40:08 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 14:55:18 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("_default_"), isSigned(false), gradeSign(150), gradeExecute(150) {}
AForm::AForm(std::string name,
           bool isSigned,
           unsigned int gradeSign,
           unsigned int gradeExecute)
    : name(name),
      isSigned(isSigned),
      gradeSign(validateGrade(gradeSign)),
      gradeExecute(validateGrade(gradeExecute)) {
  if (gradeSign > 150 || gradeExecute > 150)
    throw GradeTooLowException();
  else if (gradeSign < 1 || gradeExecute < 1)
    throw GradeTooHighException();
}
AForm::~AForm() {
  std::cout << "[AForm destructor called]" << std::endl;
}
const AForm& AForm::operator=(const AForm& other) {
  if (this == &other)
    return *this;
  this->isSigned = other.isSigned;
  return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return ("Grade is too high\n");
}
const char* AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too low\n");
}

std::string AForm::getName() const {
  return name;
}
bool AForm::getIsSigned() const {
  return isSigned;
}
unsigned int AForm::getGradeSign() const {
  return gradeSign;
}
unsigned int AForm::getGradeExecute() const {
  return gradeExecute;
}
void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeSign)
    throw GradeTooLowException();
  this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
  os << "------------AForm - " << AForm.getName() << "------------\n"
     << "AForm is signed: " << AForm.getIsSigned() << std::endl
     << "AForm sign grade: " << AForm.getGradeSign() << std::endl
     << "AForm execute grade " << AForm.getGradeExecute() << std::endl
     << "-----------------------------------------------" << std::endl;
  return os;
}

unsigned int AForm::validateGrade(unsigned int x) {
  if (x > 150)
    throw GradeTooLowException();
  else if (x < 1)
    throw GradeTooHighException();
  return (x);
}

void AForm::execute(Bureaucrat const& executor) const
{
	if(this->isSigned == false)
		throw std::runtime_error("Form isn't signed yet\n");
	if(executor.getGrade() > this->gradeExecute)
		throw GradeTooLowException();
	this->runForm();
}

