/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:44:38 by plichota          #+#    #+#             */
/*   Updated: 2026/03/08 18:41:33 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

// can store a maximum of N integers. N is an unsigned int variable and will be the only parameter passed to the constructor.

// addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.

// Next, implement two member functions: shortestSpan() and longestSpan() (DISTANCE -  between all the numbers stored, and return it. If there are no numbers stored,
// or only one, no span can be found. Thus, throw an exception)

// Implement a member function that use range of iterators to add multiple numbers to your Span in a single cal

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int _N;
    public:
        Span(unsigned int N);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif