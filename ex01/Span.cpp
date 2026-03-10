/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:48:37 by plichota          #+#    #+#             */
/*   Updated: 2026/03/10 16:23:52 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span& other) : _N(other._N)
{
    numbers = other.numbers;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (numbers.size() >= _N)
        throw std::runtime_error("Span is full");
    numbers.push_back(number);
}

// minimum difference between all the numbers stored
// distance = difference between two numbers
int Span::shortestSpan()
{
    // if there are no numbers stored, or only one, no span can be found
    if (numbers.size() < 2)
      throw std::runtime_error("Not enough numbers to find a span");
    // otherwise return the distance
    std::vector<int> v2 = numbers;
    std::sort(v2.begin(), v2.end());
    std::vector<int>::iterator it1 = v2.begin();
    std::vector<int>::iterator it2 = it1 + 1; // +1 funziona solo con iteratori "random access" di vector e deque
    // confronto solo elementi vicini
    // it = v2.begin() già inizializzato
    // si usa != per standard iteratori
    int diff = *it2 - *it1;
    /*
      diff = std::numeric_limits<int>::max()
      e' un pattern piu' robusto:
      anche se il ciclo non viene mai eseguito
      il valore rimane “impossibile” (max int)
      quindi puoi gestire il caso a parte.
    */
    for (; it2 != v2.end(); ++it1, ++it2)
    {
      if (*it2 - *it1 < diff)
          diff = *it2 - *it1;
    }
    return diff;
}

// sort all numbers, return max - min
int Span::longestSpan()
{
    if (numbers.size() < 2)
      throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> v2 = numbers;
    std::sort(v2.begin(), v2.end());
    return v2.back() - v2.front();
}

void Span::printNumbers()
{
  size_t size = numbers.size();
  if (size == 0)
  {
    std::cout << "Empty Span" << std::endl;
    return;
  }
  std::vector<int>::iterator it = numbers.begin();
  std::vector<int>::iterator end = numbers.end();
  for ( ; it != end; ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// instead of using addNumber and reallocating memory every time
// calculate the size and mass insert all numbers at once, using vector::insert
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
  size_t count = std::distance(begin, end);
  if (numbers.size() + count > _N)
    throw std::runtime_error("Span is full");
  numbers.insert(numbers.end(), begin, end);
}