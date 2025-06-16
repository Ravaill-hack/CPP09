/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:26:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/16 16:17:00 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Error: usage: ./PmergeMe <unsigned int1> <...> <unsigned int n>" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	toSort(argc, argv);
		toSort.process();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}