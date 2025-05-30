/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:53:42 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/30 14:18:09 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: there must be one and only one input" << std::endl;
		std::cerr << "The usage is : ./btc <input.txt>" << std::endl;
	}
	else
	{
		std::string	dataFileName = "data.csv";

		BitcoinExchange	data(dataFileName);
		data.finalPrint(argv[1]);
	}	
}
