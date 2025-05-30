
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <string>
# include <limits>
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

		class TooLargeNumberException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Error: too large a number.");
				}
		};
		class NegativeNumberException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Error: not a positive number.");
				}
		};

	private:
		std::map<std::string, float>					_data;
		void											storeData(const std::string & data);
		float											findValueInMap(const std::string & date) const;
		std::map<std::string, float>::const_iterator	findFirstPreviousDate(const std::string & date) const;
};

std::string	findDate(std::string line);
float		findValueInData(std::string line);
float		findNb(const std::string line);

#endif