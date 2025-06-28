/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:37:12 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/28 20:19:27 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <cstdlib>

class Date
{
private:
	int _year;
	int _month;
	int _day;

	Date();

	bool validFormat(std::string input);
	bool validDate();

public:
	Date(std::string date);
	Date(const Date& other);

	Date &operator=(const Date& other);
	bool operator<(const Date& other) const;

	int getYear() const ;
  int getMonth() const ;
  int getDay() const ;
	

	~Date();
};

std::ostream& operator<<(std::ostream& os, const Date& date); 


#endif


