/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:24:30 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/29 11:25:24 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
private:
	std::stack<float> _stack;
	float _result;
	void validInput(std::string input);
	void execute(std::string input);
	void executeOperation(char& c);
	
public:
	RPN();
	RPN(std::string input);
	RPN(const RPN& other);
	
	~RPN();

	RPN& operator= (const RPN& other);

};




#endif