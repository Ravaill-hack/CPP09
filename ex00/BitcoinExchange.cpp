/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:52:19 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/30 14:45:19 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               CANONIC                                    ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & toCopy)
{
	*this = toCopy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other)
{
	if (this != &other)
		this->_data = other._data;
	return (*this);	
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                          OTHER CONSTRUCTORS                              ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(const std::string & input)
{
	storeData(input);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                            MEMBER FUNCTIONS                              ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	BitcoinExchange::storeData(const std::string &data)
{
	std::ifstream		datastream;
	std::string			tmpline;

	datastream.open(data.c_str());
	if (!datastream)
		std::cerr << "Error: cannot open " << data << std::endl;
	else
	{
		std::getline(datastream, tmpline);
		while (std::getline(datastream, tmpline))
		{
			if (!tmpline.empty())
				_data[findDate(tmpline)] = findValueInData(tmpline);
		}
		datastream.clear();
		datastream.close();
		if (datastream.fail())
			std::cerr << "Error: cannot close " << data << std::endl;
	}
}

std::map<std::string, float>::const_iterator	BitcoinExchange::findFirstPreviousDate(const std::string & date) const
{
	std::map<std::string, float>::const_iterator	it = _data.lower_bound(date);

	if (it == _data.begin())
		return (_data.end());
	it--;
	return (it);
}

float	BitcoinExchange::findValueInMap(const std::string & date) const
{
	std::map<std::string, float>::const_iterator it = _data.find(date);
	if (it != _data.end())
		return (it->second);
	else
	{
		std::map<std::string, float>::const_iterator it = findFirstPreviousDate(date);
		return (it->second);
	}
}

void	BitcoinExchange::finalPrint(const std::string &input) const
{
	std::ifstream	inputstream;
	std::string		tmpline;
	float			tmpnb = 1.0f;
	std::string		tmpdate;
	float			tmpvalue = 0.0f;

	inputstream.open(input.c_str());
	if (!inputstream)
		std::cerr << "Error: cannot open " << input << std::endl;
	else
	{
		std::getline(inputstream, tmpline);
		while (std::getline(inputstream, tmpline))
		{
			try
			{
				if (!tmpline.empty())
				{
					tmpdate = findDate(tmpline);
					tmpvalue = findValueInMap(tmpdate);
					tmpnb = findNb(tmpline);
					if (tmpnb < 0)
						throw BitcoinExchange::NegativeNumberException();
					else if (tmpnb > 1000.0f)
						throw BitcoinExchange::TooLargeNumberException();
					else
						std::cout << tmpdate << " => " << tmpnb << " = " << tmpnb * tmpvalue << std::endl;
				}
			}
			catch(const std::out_of_range& e)
			{
				std::cerr << "Error: bad input => " << tmpdate << std::endl;
			}
			catch(const BitcoinExchange::TooLargeNumberException& e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch(const BitcoinExchange::NegativeNumberException& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		inputstream.clear();
		inputstream.close();
		if (inputstream.fail())
			std::cerr << "Error: cannot close " << input << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               EXCEPTIONS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                          NON MEMBER FUNCTIONS                            ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::string	findDate(std::string line)
{
	return (line.substr(0, 10));
}

float	findValueInData(std::string line)
{
	float	nb = 0.0f;

	std::stringstream	datestream(line.substr(11));
	datestream >> nb;
	return (nb);
}

float	findNb(const std::string line)
{
	float				nb = 0.0f;
	std::stringstream	streamnb(line.substr(12));
	streamnb >> nb;
	return (nb);
}

