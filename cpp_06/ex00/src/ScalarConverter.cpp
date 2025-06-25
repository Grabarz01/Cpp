/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:19:51 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/25 09:40:59 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

bool isSpecialLiteral(const std::string& input);
bool isChar(const std::string& input);
bool isInt(const std::string& input);
bool validInput(const std::string& input);
bool isFloat(const std::string& input);
bool isDouble(const std::string& input);

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  *this = other;
}

const ScalarConverter& ScalarConverter::operator=(
    const ScalarConverter& other) {
  (void)other;
  return *this;
}

void ScalarConverter::convert(const std::string& input) {
  std::cout << "-----------------------------" << std::endl;
  std::cout << "INPUT: " << input << std::endl;
  if (input.empty()) {
    std::cout << "Error: Empty input" << std::endl;
    return;
  }

  if (isSpecialLiteral(input)) {
    return;
  }

  if (!validInput(input)) {
    std::cout << "Invalid input" << std::endl;
    return;
  }

  if (isChar(input) || isInt(input) || isFloat(input) || isDouble(input))
    return;

  std::cout << "Invalid input" << std::endl;
}

bool isSpecialLiteral(const std::string& input) {
  float resultF = 0.0f;
  double resultD = 0.0;

  if (input == "-inff" || input == "+inff" || input == "nanf")
    resultF = std::atof(input.c_str());
  else if (input == "-inf" || input == "+inf" || input == "nan")
    resultD = std::atof(input.c_str());
  else
    return false;
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (resultF != 0) {
    std::cout << "float: " << resultF << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(resultF) << std::endl;
  } else {
    std::cout << "float: " << static_cast<float>(resultD) << "f" << std::endl;
    std::cout << "double: " << resultD << std::endl;
  }
  return true;
}

bool isChar(const std::string& input) {
  if (input.size() != 1)
    return false;
  if (std::isprint(input[0])) {
    std::cout << "char: " << input << std::endl;
  } else
    std::cout << "char: non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
  std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
  return true;
}

bool isInt(const std::string& input) {
  if (input.find_first_not_of("+-01234567890") != std::string::npos)
    return false;
  errno = 0;
  long result = std::strtol(input.c_str(), NULL, 10);
  if (errno == ERANGE || result > INT_MAX || result < INT_MIN) {
    std::cout << "Invalid input" << std::endl;
    return true;
  }

  if (result < 0 || result > 127)
    std::cout << "char: impossible" << std::endl;
  else {
    char a = static_cast<char>(result);
    if (std::isprint(a))
      std::cout << "char: " << a << std::endl;
    else
      std::cout << "char: non displayable" << std::endl;
  }
  std::cout << "int: " << result << std::endl;
  std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(result) << "f" << std::endl;
  std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(result) << std::endl;
  return true;
}

bool validInput(const std::string& input) {
  (void)input;
  if (input.find_last_of("-+") != std::string::npos &&
      input.find_last_of("-+") != 0)
    return false;
  if (input.find_first_of(".") != input.find_last_of("."))
    return false;
  if (input.find_first_not_of("0123456789-+f.") != std::string::npos)
    return false;
  if (input.find_first_of("0123456789") == std::string::npos)
    return false;
  return true;
}

bool isFloat(const std::string& input) {
  if (input.size() < 3 || input.find('f') != input.size() - 1 ||
      input.find('.') == std::string::npos)
    return false;
  char* end;
  errno = 0;
  float result = std::strtof(input.c_str(), &end);
  if (*end != 'f' || errno == ERANGE) {
    std::cout << "Invalid input" << std::endl;
    return true;
  }
  char a = static_cast<char>(result);
  if (result <= -1 || result >= 128)
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(a))
    std::cout << "char: " << a << std::endl;
  else
    std::cout << "char: non displayable" << std::endl;

  int b = static_cast<int>(result);
  if (result > INT_MAX || result < INT_MIN)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << b << std::endl;

  std::cout << std::fixed << std::setprecision(5) << "float: " << result << "f"
            << std::endl;
  std::cout << std::fixed << std::setprecision(5)
            << "double: " << static_cast<double>(result) << std::endl;
  return true;
}

bool isDouble(const std::string& input) {
  if (input.size() < 2 || input.find('f') != std::string::npos ||
      input.find('.') == std::string::npos)
    return false;
  char* end;
  errno = 0;
  double result = std::strtod(input.c_str(), &end);
  if (*end != '\0' || errno == ERANGE) {
    std::cout << "Invalid input" << std::endl;
    return true;
  }
  char a = static_cast<char>(result);
  if (result <= -1 || result >= 128)
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(a))
    std::cout << "char: " << a << std::endl;
  else
    std::cout << "char: non displayable" << std::endl;

  int b = static_cast<int>(result);
  if (result > INT_MAX || result < INT_MIN)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << b << std::endl;

  std::cout << std::fixed << std::setprecision(5)
            << "float: " << static_cast<float>(result) << "f" << std::endl;
  std::cout << std::fixed << std::setprecision(5) << "double: " << result
            << std::endl;
  return true;
}
