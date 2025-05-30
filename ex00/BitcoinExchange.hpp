
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & toCopy);
		BitcoinExchange & operator=(const BitcoinExchange & other);

		BitcoinExchange(const std::string & input);

		void		finalPrint(const std::string &input) const;

	private:
		std::map<std::string, float>					_data;
		void											storeData(const std::string & data);
		float											findValueInMap(const std::string & date) const;
		std::map<std::string, float>::const_iterator	findFirstPreviousDate(const std::string & date) const;
};

std::string	findDate(std::string line);
float		findValueInData(std::string line);
int			findNb(const std::string line);

#endif