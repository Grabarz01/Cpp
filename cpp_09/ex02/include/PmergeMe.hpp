/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:05:09 by fgrabows          #+#    #+#             */
/*   Updated: 2025/08/13 20:11:40 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>


typedef std::vector<int>::iterator vecIterator;
typedef std::deque<int>::iterator deqIterator;

class PmergeMe {
 private:
  std::vector<int> vec;
  std::deque<int> deq;
  int extractArg(char* arg);
  void transformInputToVector(int argc, char** argv);
  void transformInputToDeque(int argc, char** argv);
  void printResult(clock_t timeDeq, clock_t timeVec);
  void printTime(clock_t time, std::string container);
  
  void sortDeque(int elements);
  void sortPairsDeque(int elements, deqIterator lastEven);
  void dequeJacobsthal(std::deque<deqIterator> main, std::deque<deqIterator> pend);
  
  
  void sortVector(int elements);
  void sortPairsVector(int elements, vecIterator lastEven);
  void vectorJacobsthal(std::vector<vecIterator> main, std::vector<vecIterator> pend);

 public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  PmergeMe(int argc, char** argv);

  template <typename T>
  void swapPair(T first, T second, int elements);
};

template <typename T>
bool is_sorted(const T& v);

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v);
std::ostream& operator<<(std::ostream& os, const std::deque<int>& v);

template <typename Iterator>
bool compare(const Iterator& a, const Iterator& b);

template <typename T>
T getNext(T it, int steps);


#endif