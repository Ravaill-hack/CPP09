
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
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

	private:
		std::map<int, float>	_map;
};

#endif