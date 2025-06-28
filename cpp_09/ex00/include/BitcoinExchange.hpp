/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:39:04 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/28 20:18:15 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>

#define WRG_DB "Wrong input in database"

class Date;

class BitcoinExchange
{
private:
	std::map<Date, float> _db;
	BitcoinExchange();
	float extractValue(std::string str);
	float exchangeResult(float value, Date &date);
	float getBtcRate(Date &date);

public:
	BitcoinExchange(std::ifstream& file);
	BitcoinExchange(const BitcoinExchange&other);

	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& other);
	void exchange(std::ifstream& filename);
};

#endif