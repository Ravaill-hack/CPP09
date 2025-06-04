/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:58:21 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/04 11:59:21 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               CANONIC +                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

RPN::RPN() : _expr("empty"), _res(0){}

RPN::RPN(const std::string & expr)
{
	if (expr.empty())
		throw InvalidSyntaxException();
	else
		_expr = expr;
	if (isValidNb(0) == false)
		throw InvalidSyntaxException();
	else
		_res = toInt(_expr[0]);
	this->fill();
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
		this->_res = other._res;
		this->_operands = other._operands;
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
	size_t	i = 0;
	while (i < this->_nbs.size())
	{
		_res = chooseOperand(i);
		i++;
	}
	std::cout << _res << std::endl;
}

void	RPN::fill()
{
	size_t	i = 2;

	if (isValidNb(0) == false)
		throw InvalidSyntaxException();
	while (this->_expr.c_str()[i])
	{
		if (isValidNb(i))
			_nbs.push_back(toInt(this->_expr.c_str()[i]));
		else
			throw InvalidSyntaxException();
		i++;
		if (this->_expr.c_str()[i] && this->_expr.c_str()[i] == ' ')
			i++;
		if (isValidOperand(i))
			_operands.push_back(this->_expr.c_str()[i]);
		else
			throw InvalidSyntaxException();
		i++;
		if (this->_expr.c_str()[i] && this->_expr.c_str()[i] == ' ')
			i++;
	}
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

int	RPN::chooseOperand(size_t i)
{
	int		res;
	char 	tabOperands[4] = {'+', '-', '*', '/'};
	int		(*functionsTab[4])(int nb1, int nb2) = {plus, minu, fact, divi};

	for (size_t i1 = 0; i1 < 4; i1++)
	{
		if (_operands[i] == tabOperands[i1])
			res = (functionsTab[i1](_res, _nbs[i]));
	}
	return (res);
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
	return (nb1 / nb2);
}

