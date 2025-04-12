/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:38:21 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/11 12:06:10 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  Form a("GDPR_150", false, 10, 10);
  std::cout << a;
  try {
    Form b("GDPR", false, 151, 1);
  } catch (const std::exception& e) {
    std::cout << e.what();
  }
  try {
    Form b("GDPR", false, 0, 1);
  } catch (const std::exception& e) {
    std::cout << e.what();
  }
  try {
    Form b("GDPR", false, 1, 151);
  } catch (const std::exception& e) {
    std::cout << e.what();
  }
  try {
    Form b("GDP", false, 1, 0);
  } catch (const std::exception& e) {
    std::cout << e.what();
  }
  //-------------------------------------------------
  std::cout << "---------New Bureaucrat---------\n";
  Bureaucrat filip("Filip", 10);
  filip.signForm(a);
  try {
	Form gdpr("GDPR_1", false, 9,9);
    filip.signForm(gdpr);
  } catch (const std::exception& e) {
    std::cout << e.what();
  }
}