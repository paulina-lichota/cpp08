/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:42:32 by plichota          #+#    #+#             */
/*   Updated: 2026/03/10 19:58:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    stack is iterable but the interface intentionally doesn't expose any iterators
    std::stack istanzia un container c protected, deque di default (https://cplusplus.com/reference/stack/stack/)
*/

/*
    Iterators:
    https://cplusplus.com/reference/iterator/RandomAccessIterator/
*/

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define GREEN   	"\033[0;32m"
# define YELLOW  	"\033[0;33m"
# define BLUE    	"\033[0;34m"
# define MAGENTA 	"\033[0;35m"
# define RESET   	"\033[0m"

#include <stack>
#include <iterator>

template <class T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> 
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif