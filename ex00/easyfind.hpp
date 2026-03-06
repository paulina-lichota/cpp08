/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:57:11 by plichota          #+#    #+#             */
/*   Updated: 2026/03/06 19:02:53 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define GREEN   	"\033[0;32m"
# define YELLOW  	"\033[0;33m"
# define BLUE    	"\033[0;34m"
# define MAGENTA 	"\033[0;35m"
# define RESET   	"\033[0m"

// Write a function template easyfind that accepts a type T. It takes two parameters:
// the first one is of type T, and the second one is an integer.

// Assuming T is a container of integers, this function has to find the first occurrence
// of the second parameter in the first parameter.
template <typename T>
T easyfind(T a, int b);

#include "easyfind.tpp"

#endif