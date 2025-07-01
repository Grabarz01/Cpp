/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:55:53 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/30 20:40:36 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <list>
#include <deque>

int main(){
	std::cout << "Content of the list" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << "Content of the MutantStack" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "--------------------------------" << std::endl;
	std::cout << "copy" << std::endl;
	MutantStack<int>copy(mstack);
	MutantStack<int>::iterator it2 = copy.begin();
	MutantStack<int>::iterator ite2 = copy.end();
	++it2;
	--it2;
	*it2 = 15;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	it = mstack.begin();
	ite = mstack.end();	

	std::cout << "Original:" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "--------------------------------" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator itt = list.begin();
	std::list<int>::iterator itee = list.end();
	++itt;
	--itt;

	std::cout << "Content of the list" << std::endl;
	while (itt != itee)
	{
		std::cout << *itt << std::endl;
		++itt;
	}
	std::stack<int, std::list<int> > sl(list);
	return 0;
}
