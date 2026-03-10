/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:41:31 by plichota          #+#    #+#             */
/*   Updated: 2026/03/10 20:15:10 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
    {
        std::cout << GREEN << "=========== MutantStack with std::stack ===========" << RESET << std::endl;
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
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout << "size: " << mstack.size() << std::endl;
    }
    {
        std::cout << GREEN << "=========== same with std::list ===========" << RESET << std::endl;
        std::list<int> l;
        l.push_back(5);
        l.push_back(17);
        std::cout << l.back() << std::endl; // (top) ultimo inserito, non lo rimuove
        l.pop_back(); // (pop) rimuove l'ultimo inserito, non lo restituisce
        std::cout << l.size() << std::endl;
        l.push_back(3);
        l.push_back(5);
        l.push_back(737);
        //[...]
        l.push_back(0);
        std::list<int>::iterator it = l.begin();
        std::list<int>::iterator ite = l.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        // std::stack<int> s(l); // non funziona, devo specificare il tipo del container sottostante
        std::stack<int, std::list<int> > s(l);
        std::cout << "size: " << l.size() << std::endl;
    }
}