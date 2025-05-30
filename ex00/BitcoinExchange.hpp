
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
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

		void		finalPrint(const std::string &input) const;

	private:
		std::map<std::string, float>	_data;
		void		storeData(const std::string & data);
		float		findValueInMap(const std::string & date) const;
};

static	std::string	findDate(std::string line);
static	float		findValueInData(std::string line);

#endif