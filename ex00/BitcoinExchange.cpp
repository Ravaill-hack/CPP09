/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:52:19 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/30 14:11:51 by lmatkows         ###   ########.fr       */
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



////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                            MEMBER FUNCTIONS                              ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	BitcoinExchange::storeData(const std::string &data)
{
	std::ifstream		datastream;
	std::string			tmpline;

	datastream.open(data);
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
	auto	it = _data.lower_bound(date);

	if (it == _data.begin())
		return (_data.end());
	it--;
	return (it);
}

float	BitcoinExchange::findValueInMap(const std::string & date) const
{
	auto it = _data.find(date);
	if (it != _data.end())
		return (it->second);
	else
	{
		auto it = findFirstPreviousDate(date);
		return (it->second);
	}
}

void	BitcoinExchange::finalPrint(const std::string &input) const
{
	std::ifstream	inputstream;
	std::string		tmpline;
	int				tmpnb = 1;
	std::string		tmpdate;
	float			tmpvalue = 0.0f;

	inputstream.open(input);
	if (!inputstream)
		std::cerr << "Error: cannot open " << input << std::endl;
	else
	{
		std::getline(inputstream, tmpline);
		while (std::getline(inputstream, tmpline))
		{
			if (!tmpline.empty())
			{
				tmpdate = findDate(tmpline);
				tmpvalue = findValueInMap(tmpdate);
				tmpnb = findNb(tmpline);
				std::cout << tmpdate << " => " << tmpnb << " = " << static_cast<float>(tmpnb) * tmpvalue << std::endl;
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

static	std::string	findDate(std::string line)
{
	return (line.substr(0, 10));
}

static	float	findValueInData(std::string line)
{
	float	nb = 0.0f;

	std::stringstream	datestream(line.substr(11));
	datestream >> nb;
	return (nb);
}

static	int	findNb(const std::string line)
{
	int					nb = 0;
	std::stringstream	streamnb(line.substr(12));
	streamnb >> nb;
	return (nb);
}

