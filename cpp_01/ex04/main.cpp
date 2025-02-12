/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:58:08 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/04 11:43:33 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

std::string myReplace(const std::string& line, const std::string& s1,
				const std::string& s2)
{
	std::string result;
	size_t pos = 0, last_pos = 0;

	while((pos = line.find(s1,last_pos)) != std::string::npos)
	{
		result.append(line.substr(last_pos, pos - last_pos));
		result.append(s2);
		last_pos = pos + s1.length();
	}
	result.append(line.substr(last_pos));
	return result;
}

void transferInputToFile(std::ifstream& infile, const std::string& s1,
		const std::string& s2, const std::string &outfile_str)
{
	
	if (infile)
	{
		std::ofstream			outfile(outfile_str.c_str());
		std::string				line;
		std::string::iterator	occurance;
		if(outfile)
		{
			while(getline(infile, line))
				outfile << myReplace(line, s1, s2) << "\n";
		}
		else
			std::cerr << "Error Cannot open output file" << std::endl;
		infile.close();
	}
	else
		std::cerr << "Error: Cannot open input file" << std::endl;	
	
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong amount of arguments" << std::endl;
		return 1;
	}
	std::ifstream			infile(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string		outfile(std::string(argv[1]) + ".replace");
	
	if(s1.empty())
	{
		std::cerr << "Error: The string to replace cannot be empty" << std::endl;
		infile.close();
		return 1;
	}
	transferInputToFile(infile, s1, s2, outfile);
	return(0);
}