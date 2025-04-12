/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:40:16 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/11 12:18:49 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string name;
  bool isSigned;
  const unsigned int gradeSign;
  const unsigned int gradeExecute;
  unsigned int validateGrade(unsigned int x);

 public:
  Form();
  Form(std::string name, bool isSigned, unsigned int gradeSign, unsigned int gradeExecute);
  ~Form();
  const Form& operator=(const Form& other);

  class GradeTooHighException : public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char* what() const throw();
  };
  std::string getName() const;
  bool getIsSigned() const;
  unsigned int getGradeSign() const;
  unsigned int getGradeExecute() const;
  void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& a);

#endif
