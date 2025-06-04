
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <iomanip>
# include <vector>
# include <exception>

class RPN
{
	public:
		RPN();
		RPN(const std::string & expr);
		~RPN();
		RPN(const RPN & toCopy);
		RPN & operator=(const RPN & other);

		void		process();

		class InvalidNbArgsException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Error: there must be one and only one input");
				}
		};

		class InvalidSyntaxException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Error: Invalid Syntax");
				}
		};

	private:
		std::string				_expr;
		std::vector<char>		_operands;
		std::vector<int>		_nbs;
		int						_res;

		int						chooseOperand(size_t i);
		void					fill();
		bool					isValidNb(size_t i) const;
		bool					isValidOperand(size_t i) const;

};

int	toInt(char nbChar);
int	plus(int nb1, int nb2);
int	minu(int nb1, int nb2);
int	fact(int nb1, int nb2);
int	divi(int nb1, int nb2);

#endif