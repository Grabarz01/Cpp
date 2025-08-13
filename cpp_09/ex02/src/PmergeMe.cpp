/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:11:09 by fgrabows          #+#    #+#             */
/*   Updated: 2025/08/13 20:11:34 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (&other == this)
    return (*this);
  vec = other.vec;
  deq = other.deq;
  return *this;
}

PmergeMe::PmergeMe(int argc, char** argv) {
  if (argc == 1)
    throw std::runtime_error("Error: empty input");
  try {
    for (int i = 1; i < argc; i++) {
      vec.push_back(extractArg(argv[i]));
    }
  } catch (std::exception& e) {
    throw std::runtime_error("Error: Invalid argument");
  }

  if (is_sorted(vec))
    throw std::runtime_error("Error: input is already sorted");

  std::cout << "Before: " << vec << std::endl;
  std::sort(vec.begin(), vec.end());
  std::cout << "After: " << vec << std::endl;
  vec.clear();
  clock_t timeDeque = clock();  // long
  transformInputToDeque(argc, argv);
  sortDeque(1);
  timeDeque = clock() - timeDeque;
  clock_t timeVec = clock();
  transformInputToVector(argc, argv);
  sortVector(1);
  timeVec = clock() - timeVec;
  printResult(timeDeque, timeVec);
  std::cout << (is_sorted(vec) ? "Sorted" : "Error") << std::endl;
  std::cout << (is_sorted(deq) ? "Sorted" : "Error") << std::endl;
}

void PmergeMe::transformInputToVector(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    vec.push_back(extractArg(argv[i]));
  }
}
void PmergeMe::transformInputToDeque(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    deq.push_back(extractArg(argv[i]));
  }
}

int PmergeMe::extractArg(char* arg) {
  std::string tmp(arg);
  if (tmp.find_first_not_of("0123456789") != std::string::npos)
    throw std::runtime_error("Error: Program accepts only numbers as an input");
  std::istringstream iss(tmp);
  int x;
  if (!(iss >> x))
    throw std::runtime_error("Error: Invalid argument");
  return x;
}

void PmergeMe::printResult(clock_t timeDeq, clock_t timeVec) {
  printTime(timeDeq, "deque");
  printTime(timeVec, "vector");
}

void PmergeMe::printTime(clock_t time, std::string container) {
  double ms = static_cast<double>(time) * (1000.0 / CLOCKS_PER_SEC);
  std::cout << "Time to process a range of " << std::setw(5) << vec.size()
            << " with std::" << container << " : " << std::fixed
            << std::setprecision(5)
            << ms << " ms"
            << std::endl;
}

// DEQUE
void PmergeMe::sortDeque(int elements) {
  int units =
      deq.size() /
      elements;  // number of grups(first iteration with single elements)

  // if less than 2 grups there is nothing to do
  if (units < 2)
    return;

  bool isOdd = units % 2 == 1;
  deqIterator last =
      getNext(deq.begin(), elements * units);  // last group(full group)
  deqIterator lastEven =
      getNext(last, -(isOdd * elements));  // last but one if odd

  // divide into pairs and sort them
  sortPairsDeque(elements,lastEven);

  // next recursion lvl
  sortDeque(elements * 2);

  std::deque<deqIterator> main;
  std::deque<deqIterator> pend;

  main.push_back(getNext(deq.begin(), elements - 1));      //{b1}
  main.push_back(getNext(deq.begin(), elements * 2 - 1));  //{a1}
  for (int i = 4; i <= units; i += 2) {
    pend.push_back(getNext(deq.begin(), elements * (i - 1) - 1));  //{bx}
    main.push_back(getNext(deq.begin(), elements * i - 1));        //{ax}
  }
  if (isOdd) {
    pend.push_back(getNext(lastEven, elements - 1));
  }

  dequeJacobsthal(main, pend);

  // Insert rest of pend in reverse order
  for (int i = pend.size() - 1; i >= 0; i--) {
    std::deque<deqIterator>::iterator currPend = getNext(pend.begin(), i);
    std::deque<deqIterator>::iterator currBound =
        getNext(main.begin(), main.size() - pend.size() + i + isOdd);
    std::deque<deqIterator>::iterator idx = std::upper_bound(
        main.begin(), currBound, *currPend, compare<deqIterator>);
    main.insert(idx, *currPend);
  }

  // create the copy and overwrite the original
  std::deque<int> copy;
  for (std::deque<deqIterator>::iterator it = main.begin(); it != main.end(); ++it) {
    for (int i = 0; i < elements; i++) {
      deqIterator pairStart = *it;
      std::advance(pairStart, -elements + i + 1);
      copy.push_back(*pairStart);
    }
  }

   for (deqIterator copyIt = copy.begin(), deqIt = deq.begin();
       copyIt != copy.end() && deqIt != deq.end(); ++copyIt, ++deqIt) {
    *deqIt = *copyIt;
  }
}

void PmergeMe::dequeJacobsthal(std::deque<deqIterator> main,
                               std::deque<deqIterator> pend) {
  int prevprevJacobsthal = 0;
  int prevJacobsthal = 1;
  int insertedNumbers = 0;
  for (int k = 2;; k++) {
    int currJacobsthal = prevJacobsthal + 2 * prevprevJacobsthal;
    int diff = currJacobsthal - prevJacobsthal;
    if (diff > static_cast<int>(pend.size()))
      break;
    int offset = 0;
    int iterations = diff;
    std::deque<deqIterator>::iterator pendIt = getNext(pend.begin(), diff - 1);
    std::deque<deqIterator>::iterator boundIt =
        getNext(main.begin(), currJacobsthal + insertedNumbers);
    while (iterations) {
      std::deque<deqIterator>::iterator idx = std::upper_bound(
          main.begin(), boundIt, *pendIt, compare<deqIterator>);
      main.insert(idx, *pendIt);
      iterations--;
      pendIt = pend.erase(pendIt);
      if (pendIt != pend.begin())
        std::advance(pendIt, -1);
      offset += (idx - main.begin()) == currJacobsthal + insertedNumbers;
      boundIt =
          getNext(main.begin(), currJacobsthal + insertedNumbers - offset);
    }
    prevprevJacobsthal = prevJacobsthal;
    prevJacobsthal = currJacobsthal;
    insertedNumbers += diff;
    offset = 0;
  }
}

void PmergeMe::sortPairsDeque(int elements, deqIterator lastEven) {
  int jump = 2 * elements;
  for (deqIterator it = deq.begin(); it != lastEven; std::advance(it, jump)) {
    deqIterator thisPair = getNext(it, elements - 1);
    deqIterator nextPair = getNext(it, elements * 2 - 1);
    if (*thisPair > *nextPair) {
      swapPair(thisPair, nextPair, elements);
    }
  }
}

// VECTOR
void PmergeMe::sortVector(int elements) {
  int units =
      vec.size() /
      elements;  // number of grups(first iteration with single elements)

  // if less than 2 grups there is nothing to do
  if (units < 2)
    return;

  bool isOdd = units % 2 == 1;
  vecIterator last =
      getNext(vec.begin(), elements * units);  // last group(full group)
  vecIterator lastEven =
      getNext(last, -(isOdd * elements));  // last but one if odd

  // divide into pairs and sort them
  sortPairsVector(elements, lastEven);

  // next recursion lvl
  sortVector(elements * 2);

  std::vector<vecIterator> main;
  std::vector<vecIterator> pend;

  // divide into pairs and sort them
  main.push_back(getNext(vec.begin(), elements - 1));      //{b1}
  main.push_back(getNext(vec.begin(), elements * 2 - 1));  //{a1}
  for (int i = 4; i <= units; i += 2) {
    pend.push_back(getNext(vec.begin(), elements * (i - 1) - 1));  //{bx}
    main.push_back(getNext(vec.begin(), elements * i - 1));        //{ax}
  }
  if (isOdd) {
    pend.push_back(getNext(lastEven, elements - 1));
  }

  vectorJacobsthal(main, pend);

  // Insert rest of pend in reverse order
  for (int i = pend.size() - 1; i >= 0; i--) {
    std::vector<vecIterator>::iterator currPend = getNext(pend.begin(), i);
    std::vector<vecIterator>::iterator currBound =
        getNext(main.begin(), main.size() - pend.size() + i + isOdd);
    std::vector<vecIterator>::iterator idx = std::upper_bound(
        main.begin(), currBound, *currPend, compare<vecIterator>);
    main.insert(idx, *currPend);
  }

  // create the copy and overwrite the original
  std::vector<int> copy;
  copy.reserve(vec.size());
  for (std::vector<vecIterator>::iterator it = main.begin(); it != main.end();
       ++it) {
    for (int i = 0; i < elements; i++) {
      vecIterator pairStart = *it;
      std::advance(pairStart, -elements + i + 1);
      copy.push_back(*pairStart);
    }
  }

  for (vecIterator copyIt = copy.begin(), vecIt = vec.begin();
       copyIt != copy.end() && vecIt != vec.end(); ++copyIt, ++vecIt) {
    *vecIt = *copyIt;
  }
}

void PmergeMe::vectorJacobsthal(std::vector<vecIterator> main,
                                std::vector<vecIterator> pend) {
  int prevprevJacobsthal = 0;
  int prevJacobsthal = 1;
  int insertedNumbers = 0;
  for (int k = 2;; k++) {
    int currJacobsthal = prevJacobsthal + 2 * prevprevJacobsthal;
    int diff = currJacobsthal - prevJacobsthal;
    if (diff > static_cast<int>(pend.size()))
      break;
    int iterations = diff;
    int offset = 0;
    std::vector<vecIterator>::iterator pendIt = getNext(pend.begin(), diff - 1);
    std::vector<vecIterator>::iterator boundIt =
        getNext(main.begin(), currJacobsthal + insertedNumbers);
    while (iterations) {
      std::vector<vecIterator>::iterator idx = std::upper_bound(
          main.begin(), boundIt, *pendIt, compare<vecIterator>);
      main.insert(idx, *pendIt);
      iterations--;
      pendIt = pend.erase(pendIt);
      if (pendIt != pend.begin())
        std::advance(pendIt, -1);
      offset += (idx - main.begin()) == currJacobsthal + insertedNumbers;
      boundIt =
          getNext(main.begin(), currJacobsthal + insertedNumbers - offset);
    }
    prevprevJacobsthal = prevJacobsthal;
    prevJacobsthal = currJacobsthal;
    insertedNumbers += diff;
    offset = 0;
  }
}

void PmergeMe::sortPairsVector(int elements, vecIterator lastEven) {
  int jump = 2 * elements;
  for (vecIterator it = vec.begin(); it != lastEven; std::advance(it, jump)) {
    vecIterator thisPair = getNext(it, elements - 1);
    vecIterator nextPair = getNext(it, elements * 2 - 1);
    if (*thisPair > *nextPair) {
      swapPair(thisPair, nextPair, elements);
    }
  }
}

// UTILS
template <typename T>
void PmergeMe::swapPair(T first, T second, int elements) {
  T end = second;
  while (end != first) {
    std::iter_swap(end, getNext(end, -elements));
    --end;
  }
}

template <typename T>
bool is_sorted(const T& v) {
  if (v.empty())
    return true;
  for (typename T::size_type i = 1; i < v.size(); ++i) {
    if (v[i] < v[i - 1])
      return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin())
      os << " ";
    os << *it;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const std::deque<int>& v) {
  for (std::deque<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin())
      os << " ";
    os << *it;
  }
  return os;
}

template <typename Iterator>
bool compare(const Iterator& a, const Iterator& b) {
  return *a < *b;
}

template <typename T>
T getNext(T it, int steps) {
  std::advance(it, steps);
  return it;
}
