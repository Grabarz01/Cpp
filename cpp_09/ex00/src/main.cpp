/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:16:18 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/28 20:33:40 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Usage: btc [filename]" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	std::ifstream db_file("db/data.csv");
	if (!file.is_open() || !db_file.is_open())
	{
		std::cout << "Cannot open one of the files" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange db(db_file);
		db.exchange(file);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
 	}

}