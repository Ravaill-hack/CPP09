/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:58:21 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/04 13:51:15 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               CANONIC +                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

RPN::RPN() : _expr("empty"){}

RPN::RPN(const std::string & expr)
{
	if (expr.empty())
		throw std::runtime_error("Empty arg");
	else
		_expr = expr;
	if (isValidNb(0) == false)
		throw std::runtime_error("First element must be an int");
}
	
RPN::~RPN(){}

RPN::RPN(const RPN & toCopy)
{
	*this = toCopy;
}

RPN & RPN::operator=(const RPN & other)
{
	if (this != &other)
	{
		this->_expr = other._expr;
		this->_nbs = other._nbs;
	}
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                MEMBERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	RPN::process()
{
	std::istringstream	iss(_expr);
	std::string			oneChar;
	std::string			operands = "+-*/";
	int					n1 = 0;
	int					n2 = 0;
	size_t				i = 0;
	int					res = 0;
	
	while (iss >> oneChar)
	{
		if (oneChar.size() == 1 && operands.find(oneChar) != operands.npos) // si on est sur un char Operator
		{
			if (this->_nbs.size() < 2)
				throw std::runtime_error("Incorrect number of operands");
			n1 = this->_nbs.top();
			this->_nbs.pop();
			n2 = this->_nbs.top();
			this->_nbs.pop();			
			res = chooseOperand(oneChar[0], n1, n2);
			this->_nbs.push(res);
		}
		else
			this->_nbs.push(toInt(oneChar[0]));
		i++;
	}
	std::cout << this->_nbs.top() << std::endl;
}

bool	RPN::isValidNb(size_t i) const
{
	if (static_cast<int>(_expr[i] - '0') >= 0 && static_cast<int>(_expr[i] - '0') <= 9)
		return (true);
	return (false);
}

bool	RPN::isValidOperand(size_t i) const
{
	if (_expr[i] == '+' || _expr[i] == '-' || _expr[i] == '*' || _expr[i] == '/')
		return (true);
	return (false);
}

int	RPN::chooseOperand(char op, int nb1, int nb2)
{
	char 	tabOperands[4] = {'+', '-', '*', '/'};
	int		(*functionsTab[4])(int nb1, int nb2) = {plus, minu, fact, divi};

	for (size_t i1 = 0; i1 < 4; i1++)
	{
		if (op == tabOperands[i1])
			return (functionsTab[i1](nb1, nb2));
	}
	throw std::runtime_error("Invalid operand");
	return (-1);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

int	toInt(char nbChar)
{
	return (static_cast<int>(nbChar - '0'));
}

int	plus(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int	minu(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int	fact(int nb1, int nb2)
{
	return (nb1 * nb2);
}

int	divi(int nb1, int nb2)
{
	if (nb2 != 0)
		return (nb1 / nb2);
	else
		throw std::runtime_error("Division by Zero");
}

