/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:44:07 by plichota          #+#    #+#             */
/*   Updated: 2026/03/10 16:38:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

// Test your Span with at least 10,000 numbers. More would be even better.

// handle only span of different numbers (no duplicates)
int main()
{
    {
        std::cout << GREEN << "=========== Add Number test ===========" << RESET << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(11);
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << GREEN << "=========== Copy span test ===========" << RESET << std::endl;
        Span sp2 = Span(sp);
        sp2.printNumbers();
        std::cout << GREEN << "=========== Operator = test ===========" << RESET << std::endl;
        Span sp3 = sp;
        // sp3.addNumber(18);
        // sp3.printNumbers();
        // sp.printNumbers();
    }
    {
        std::cout << GREEN << "=========== Add Numbers with iterators test ===========" << RESET << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.printNumbers();
        
        std::cout << "Adding numbers from vector" << std::endl;
        std::vector<int> v;
        for (size_t i = 0; i < 4; i++)
            v.push_back(i);
        try
        {
            sp.addNumbers(v.begin(), v.end());
            sp.printNumbers();
        }
        catch(const std::exception& e)
        {
            std::cerr << MAGENTA << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << GREEN << "=========== Add Numbers with iterators test (throw exception) ===========" << RESET << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.printNumbers();

        std::vector<int> v;
        for (size_t i = 0; i < 5; i++)
            v.push_back(i);
        try
        {
            sp.addNumbers(v.begin(), v.end());
            sp.printNumbers();
        }
        catch(const std::exception& e)
        {
            std::cerr << MAGENTA << e.what() << RESET << '\n';
        }
    }
    {
        std::cout << GREEN << "=========== A LOT of numbers test ===========" << RESET << std::endl;
        Span sp = Span(10000);
        for (size_t i = 0; i < 10000; i++)
        {
            sp.addNumber(i);
        }
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {
        std::cout << GREEN << "=========== Another way of adding A LOT of numbers (c++98 compatible) ===========" << RESET << std::endl;
        Span sp = Span(10000);
        int arr[10000];
        for (size_t i = 0; i < 10000; i++)
            arr[i] = i * 2;
        std::cout << "(using iterators as arguments of array constructor)" << std::endl;
        std::vector<int> v(arr, arr + 10000);
        try
        {
            sp.addNumbers(v.begin(), v.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << MAGENTA << e.what() << RESET << '\n';
        }
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {
        std::cout << GREEN << "=========== Benchmark push_back ==========" << RESET << std::endl;
        std::vector<int> v;
        clock_t start = clock();
        for (size_t i = 0; i < 10000000; i++)
            v.push_back(i);
        clock_t end = clock();
        double elapsed = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "push_back time: " << elapsed << "s" << std::endl;
    }
    {
        // allocate dynamic array because of stack limit
        // cmd to check soft limit set on your OS: $ ulimit -s
        std::cout << GREEN << "=========== Benchmark insert(range) ==========" << RESET << std::endl;
        int *arr = new int[10000000];
        for (size_t i = 0; i < 10000000; i++)
            arr[i] = i;
        std::vector<int> v;
        clock_t start = clock();
        v.insert(v.end(), arr, arr + 10000000);
        clock_t end = clock();
        double elapsed = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "insert(range) time: " << elapsed << "s" << std::endl;
        delete [] arr;
    }
}

// $> ./ex01
// 2
// 14
// $>