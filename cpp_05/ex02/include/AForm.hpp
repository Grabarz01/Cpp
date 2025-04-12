/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:40:16 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 14:56:09 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
 private:
  const std::string name;
  bool isSigned;
  const unsigned int gradeSign;
  const unsigned int gradeExecute;
  unsigned int validateGrade(unsigned int x);
  virtual void runForm() const = 0;

 public:
  AForm();
  AForm(std::string name,
        bool isSigned,
        unsigned int gradeSign,
        unsigned int gradeExecute);
  ~AForm();
  const AForm& operator=(const AForm& other);

  class GradeTooHighException : public std::exception {
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char* what() const throw();
  };
  void execute(Bureaucrat const& executor) const;
  std::string getName() const;
  bool getIsSigned() const;
  unsigned int getGradeSign() const;
  unsigned int getGradeExecute() const;
  virtual void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm& a);

#endif
