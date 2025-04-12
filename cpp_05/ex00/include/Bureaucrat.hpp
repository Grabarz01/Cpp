#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat {
 private:
  const std::string name;
  unsigned int grade;

 public:
  Bureaucrat();
  Bureaucrat(std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();

  const Bureaucrat& operator=(const Bureaucrat& other);
  void gradeIncrement();
  void gradeDecrement();
  unsigned int getGrade();
  const std::string getName();
  
  class GradeTooHighException : public std::exception {
	public:
    	virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
	public:
    	virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &a);

#endif
