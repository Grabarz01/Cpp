/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:39:00 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/29 13:10:10 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include "Date.hpp"
#include <iomanip>
#include <exception>

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::ifstream& db_name) {
  std::string line;
  if (!std::getline(db_name, line))
    throw std::runtime_error("Error: empty datebase file");
  if (line.find(',') == std::string::npos)
    throw std::runtime_error(WRG_DB);
  if (!(line.substr(0, line.find(',')) == "date" &&
        line.substr(line.find(',') + 1) == "exchange_rate"))
    throw std::runtime_error(WRG_DB);
  while (std::getline(db_name, line)) {
    if (line.size() > 24 || line.find(',') == std::string::npos)
      throw std::runtime_error(WRG_DB);
    Date date(line.substr(0, line.find(',')));
    float rate = extractValue(line.substr(line.find(',') + 1));
    _db.insert(std::pair<Date, float>(date, rate));
  }
}

void BitcoinExchange::exchange(std::ifstream& filename) {
  std::string line;
  if (!std::getline(filename, line))
    throw std::runtime_error("Error: empty input file");
  //
  std::cout << line << std::endl;
  //
  if ("date | value" != line)
    throw std::runtime_error(
        "Wrong header of the input file, expected \'date | value\'");

  while (std::getline(filename, line)) {
    size_t delimiterPos = line.find(" | ");
    if (delimiterPos == std::string::npos || delimiterPos != 10 ||
        line.size() < 14) {
      std::cout
          << "Wrong input line. Expected format 'YYYY-MM-DD | NNNNNNNNNNNNNNN\'"
          << std::endl;
      continue;
    }
    if (line.size() > 30)
      std::cout << "Wrong input line. Input is too large(max 30)" << std::endl;
    try {
      Date date(line.substr(0, 10));
      float value = extractValue(line.substr(14));
			if(value > 1000)
				throw std::runtime_error("Number too big (you're not that rich... yet)");
      float result = exchangeResult(value, date);
      std::cout << date << " => " << value << " = " << std::fixed
                << std::setprecision(2) << result << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << " | Your input: " << line << std::endl;
    }
  }
}

// yyyy-mm-dd | 111234.12345
float BitcoinExchange::extractValue(std::string str) {
  if (str.size() > 15)
    throw std::runtime_error("Input limited to 15 characters");
  if (str.find_first_not_of("0123456789.") != std::string::npos)
    throw std::runtime_error(
        "Expected value consists of numbers and optionaly decimal point only");
  if (str.find('.') != str.rfind('.'))
    throw std::runtime_error("Error: only one decimal point expected");
  char* end;
  errno = 0;
  float value = std::strtof(str.c_str(), &end);
  if (errno == ERANGE || *end != '\0')
    throw std::runtime_error("Error: invalid value");
  return value;
}

float BitcoinExchange::exchangeResult(float value, Date& date) {
  return (value * getBtcRate(date));
}

float BitcoinExchange::getBtcRate(Date& date) {
  std::map<Date, float>::const_iterator it = _db.lower_bound(date);

  if (it != _db.end() && !(date < it->first))
    return it->second;
  if (it == _db.begin())
    throw std::runtime_error(
        "There is no date about Bitcoin of this day or before in database");
  --it;
  return it->second;
}

// tests
/*
-empty input file
-permisions of the file
-big numbers
-wrogn dates



*/