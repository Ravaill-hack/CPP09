/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:26:11 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/07 12:27:19 by lmatkows         ###   ########.fr       */
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
	
}