/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:19:59 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/28 20:55:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <stdexcept>
#include "Date.hpp"
#include <iostream> 

Date::Date() {}

Date::~Date() {}

Date::Date(std::string date) {
  if (!validFormat(date))
    throw std::runtime_error("Wrong date [YYYY-MM-DD]");
  std::string datePiece = date.substr(0, 4);
  _year = std::atoi(datePiece.c_str());
  datePiece = date.substr(5, 2);
  _month = std::atoi(datePiece.c_str());
  datePiece = date.substr(8, 2);
  _day = std::atoi(datePiece.c_str());
  if (!validDate())
    throw std::runtime_error("Wrong date [YYYY-MM-DD]");
}

Date::Date(const Date& other)
    : _year(other._year), _month(other._month), _day(other._day) {}

Date& Date::operator=(const Date& other) {
  if (&other == this)
    return *this;
  _year = other._year;
  _month = other._month;
  _day = other._day;
  return *this;
}

bool Date::validFormat(std::string input) {
  if (input.size() != 10)
    return false;
  if (input.find_first_not_of("0123456789-") != std::string::npos)
    return false;
  if (input.find('-') != 4 || input.find('-', 5) != 7 ||
      input.find('-', 8) != std::string::npos)
    return false;
  return true;
}

bool Date::validDate() {
  if (_month > 12 || _day > 31 || _month == 0 || _day == 0 || _year == 0)
    return false;

  int days_in_month[] = {0,  31, 0,  31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
  switch (_month) {
    case (2):
      if (((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)){
				if (_day > 29)
        	return false;
				return true;
			}
      else if (_day > 28)
        return false;
      return true;
    default:
      if (_day > days_in_month[_month])
        return false;
      return true;
  }
}

int Date::getYear() const {
	return _year;
}
int Date::getMonth() const {
	return _month;
}
int Date::getDay() const {
	return _day;
}

bool Date::operator<(const Date& other) const{
	if (_year != other._year)
			return _year < other._year;
	if (_month != other._month)
			return _month < other._month;
	return _day < other._day;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << std::setfill('0')
			<< std::setw(4) << date.getYear() << '-'
			<< std::setw(2) << date.getMonth() << '-'
			<< std::setw(2) << date.getDay();
	return os;
}

