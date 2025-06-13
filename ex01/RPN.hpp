
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <iomanip>

# include <stack>
# include <exception>

class RPN
{
	public:
		RPN();
		RPN(const std::string & expr);
		~RPN();
		RPN(const RPN & toCopy);
		RPN & operator=(const RPN & other);

		void					process();

	private:
		std::string				_expr;
		std::stack<int>			_nbs;

		int						chooseOperand(char op, int nb1, int nb2);
		bool					isValidNb(size_t i) const;
		bool					isValidOperand(size_t i) const;

};

int	toInt(char nbChar);
int	plus(int nb1, int nb2);
int	minu(int nb1, int nb2);
int	fact(int nb1, int nb2);
int	divi(int nb1, int nb2);

#endif