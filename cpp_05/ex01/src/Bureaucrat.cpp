/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:37:32 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/11 12:09:09 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Somone"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : grade(other.grade) {}
Bureaucrat::~Bureaucrat() {
  std::cout << "[Bureaucrat destructor]" << std::endl;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (&other == this)
    return *this;
  this->grade = other.grade;
  return *this;
}
void Bureaucrat::gradeIncrement() {
  if (grade == 1)
    throw GradeTooHighException();
  grade--;
}
void Bureaucrat::gradeDecrement() {
  if (grade == 150)
    throw GradeTooLowException();
  grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is going to be higher than the maximum value(1)\n");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is going to be lower than the minimum value(150)\n");
}

unsigned int Bureaucrat::getGrade() const {
  return this->grade;
}
const std::string Bureaucrat::getName() const {
  return this->name;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& a) {
  os << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
  return os;
}

void Bureaucrat::signForm(Form& form) {
  if (form.getIsSigned())
    std::cout << form.getName() << " is already signed" << std::endl;
  try {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << this->name << " couldn't sign " << form.getName()
              << " becaues " << e.what() << std::endl;
  }
}
