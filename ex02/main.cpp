/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:26:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/16 14:26:26 by Lmatkows         ###   ########.fr       */
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
	
	int	i = 0;
	while (i < argc)
	{
		std::string stringNb = argv[i];
		i++;
	}
	std::string nbList = argv[1];
	
	
}