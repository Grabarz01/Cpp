/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:29:34 by fgrabows          #+#    #+#             */
/*   Updated: 2025/08/19 09:15:30 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <algorithm>
#include <exception>
#include <cctype>
#include <iostream>

std::stack<int> stack;
float result;

RPN::RPN(){
	std::cout << "Default constructor called" << std::endl;
	std::cout << "Result: 0" << std::endl;
}

RPN::RPN(std::string input){
	validInput(input);
	execute(input);
}

RPN::RPN(const RPN& other) : _stack(other._stack), _result(other._result){
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Result: " << _result << std::endl;		
}

RPN::~RPN(){
	std::cout << "Destructor called" << std::endl;
}

RPN& RPN::operator= (const RPN& other){
	if (&other == this)
	return *this;
	_stack =other._stack;
	_result = other._result;
	return *this;
}

void RPN::validInput(std::string input){
	if (input.empty())
		throw std::runtime_error("Empty input");
	if (input.find_first_not_of(" 0123456789-+*/") != std::string::npos)
		throw std::runtime_error("Input expects only: \' 0123456789-/+*\'");
}

void RPN::execute(std::string input){
	std::string::iterator it = input.begin();
	if (*it == ' ')
		it++;
	int space = 1;
	for (;it != input.end();it++)
	{
		if (*it == ' '){
			space++;
			if (space > 1)
				throw std::runtime_error("Too many spaces between arguments");
			continue;
		}
		if (space != 1)
			throw std::runtime_error("Need space between arguments");
		space = 0;

		if (std::isdigit(*it))
			_stack.push(*it - '0');
		else
			executeOperation(*it);	
	}
	if(_stack.size() != 1 )
		throw std::runtime_error("Wrong amount of operations");
	std::cout << _stack.top() << std::endl;
	
}

void RPN::executeOperation(char& c){
	float result;
	if (_stack.size() < 2)
		throw std::runtime_error("Not enough numbers to execute the operation");
	float second = _stack.top();
	_stack.pop();
	float first = _stack.top();
	_stack.pop();
	switch (c){
		case '/':
			if (second == 0)
				throw std::runtime_error("Error: divison by 0");
			result = first / second;
			break;
		case '*':
			result = first * second;
			break;
		case '-':
			result = first - second;
			break;
		case '+':
			result = first + second;
			break;
	}
	if (result > 200000000)
		throw std::runtime_error("You reached maximum value");
	_stack.push(result);
}