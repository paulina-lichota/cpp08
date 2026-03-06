/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:57:00 by plichota          #+#    #+#             */
/*   Updated: 2026/03/06 20:34:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <iterator>

#include <vector>
#include <list>
#include <deque>

// I don't handle associative containers (not requested by the subject)
// Sequence Containers : Vector, Deque, List, Forward List (c++11), Array (c++11)
// only sequencial containers are compatible with std::find (because they have .begin() and .end())
int main()
{
    {
        std::cout << BLUE << "===== Vectors ======" << RESET << std::endl;
        // can't use { 1, 2, 3 } declaration in containers in c++98
        std::vector<int> v;
        for (size_t i = 0; i < 10; i++)
          v.push_back(i);

        // print vector
        for (std::vector<int>::iterator x = v.begin(); x != v.end(); ++x) {
            std::cout << *x << " ";
        }
        std::cout << std::endl << std::endl;

        // Find element
        std::cout << "Looking for 2..." << std::endl;
        std::vector<int>::iterator it = easyfind(v, 2);
        if (it != v.end())
            std::cout << GREEN << "Found at index: " << std::distance(v.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;

        std::cout << "Looking for 20..." << std::endl;
        it = easyfind(v, 20);
        if (it != v.end())
            std::cout << GREEN << "Found at index: " << std::distance(v.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << BLUE << "===== List ======" << RESET << std::endl;
        // can't use { 1, 2, 3 } declaration in containers in c++98
        std::list<int> l;
        for (size_t i = 0; i < 10; i++)
          l.push_back(i*2);

        // print list using iterator
        for (std::list<int>::iterator x = l.begin(); x != l.end(); ++x) {
            std::cout << *x << " ";
        }
        std::cout << std::endl;

        // Find element
        std::cout << "Looking for 2..." << std::endl;
        std::list<int>::iterator it = easyfind(l, 2);
        if (it != l.end())
            std::cout << GREEN << "Found at index: " << std::distance(l.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;

        std::cout << "Looking for 20..." << std::endl;
        it = easyfind(l, 20);
        if (it != l.end())
            std::cout << GREEN << "Found at index: " << std::distance(l.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << BLUE << "===== Dequeue + chars ======" << RESET << std::endl;
        const char* str = "ciao mondo";
        std::deque<char> l;
        for (size_t i = 0; i < 10; i++)
          l.push_back(str[i]);

        // print list using iterator
        for (std::deque<char>::iterator x = l.begin(); x != l.end(); ++x) {
            std::cout << *x << " ";
        }
        std::cout << std::endl;

        // Find element
        std::cout << "Looking for 'c'..." << std::endl;
        std::deque<char>::iterator it = easyfind(l, 'c');
        if (it != l.end())
            std::cout << GREEN << "Found at index: " << std::distance(l.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;

        std::cout << "Looking for 'z'..." << std::endl;
        it = easyfind(l, 'z');
        if (it != l.end())
            std::cout << GREEN << "Found at index: " << std::distance(l.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;

        std::cout << "Looking for 'o'..." << std::endl;
        it = easyfind(l, 'o');
        if (it != l.end())
            std::cout << GREEN << "Found at index: " << std::distance(l.begin(), it) << RESET << std::endl;
        else
            std::cout << MAGENTA << "Not found" << RESET << std::endl;
        std::cout << std::endl;
    }
}

// begin(), end() — iteratori di inizio e fine
// size() — numero di elementi
// empty() — true se il container è vuoto
// front(), back() — primo e ultimo elemento
// push_back(), pop_back() — aggiungi/rimuovi in fondo
// insert(), erase() — inserisci/rimuovi in una posizione specifica
// clear() — svuota il container
// operator[] (solo vector, deque) — accesso diretto per indice
// at() — accesso sicuro per indice (lancia eccezione se fuori range)
// assign() — assegna nuovi valori