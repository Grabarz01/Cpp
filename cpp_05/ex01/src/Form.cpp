/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:40:08 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/02 22:06:12 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("_default_"), isSigned(false), gradeSign(150), gradeExecute(150) {}
Form::Form(std::string name,
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
Form::~Form() {
  std::cout << "[Form destructor called]" << std::endl;
}
const Form& Form::operator=(const Form& other) {
  if (this == &other)
    return *this;
  this->isSigned = other.isSigned;
  return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
  return ("Grade is too high\n");
}
const char* Form::GradeTooLowException::what() const throw() {
  return ("Grade is too low\n");
}

std::string Form::getName() const {
  return name;
}
bool Form::getIsSigned() const {
  return isSigned;
}
unsigned int Form::getGradeSign() const {
  return gradeSign;
}
unsigned int Form::getGradeExecute() const {
  return gradeExecute;
}
void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeSign)
    throw GradeTooLowException();
  this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "------------Form - " << form.getName() << "------------\n"
     << "Form is signed: " << form.getIsSigned() << std::endl
     << "Form sign grade: " << form.getGradeSign() << std::endl
     << "Form execute grade " << form.getGradeExecute() << std::endl
     << "-----------------------------------------------" << std::endl;
  return os;
}

unsigned int Form::validateGrade(unsigned int x) {
  if (x > 150)
    throw GradeTooLowException();
  else if (x < 1)
    throw GradeTooHighException();
  return (x);
}
