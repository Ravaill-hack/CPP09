/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:17:55 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/16 16:14:51 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               CANONIC +                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

PmergeMe::PmergeMe()
{
	this->_startTimeVect = std::time(NULL);
	this->_endTimeVect = std::time(NULL);
	this->_startTimeDeque = std::time(NULL);
	this->_endTimeDeque = std::time(NULL); 
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	this->_startTimeVect = std::time(NULL);
	this->_endTimeVect = std::time(NULL);
	this->_startTimeDeque = std::time(NULL);
	this->_endTimeDeque = std::time(NULL); 
	for (int i = 1; i < argc; i++)
	{
		std::string nb(argv[i]);
		if (!validArg(nb))
			throw SynaxException();
		if (!isPositive(nb))
			throw NotPositiveException();
		if (!isInt(nb))
			throw NotIntException();
		int value = std::atoi(av[i]);
		this->_vectInt.push_back(value);
		his->_dequeInt.push_back(value);
	}
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe & toCopy)
{
	*this = toCopy;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & other)
{
	if (this != &other)
	{
		this->_startTimeVect = other._startTimeVect;
		this->_endTimeVect = other._endTimeVect;
		this->_startTimeDeque = other._startTimeDeque;
		this->_endTimeDeque = other._endTimeDeque; 
	}
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 MEMBERS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	PmergeMe::Process()
{
	announce("Before: ");
	sortVect();
	sortDeque();
	announce("After: ");
	
	double timeVect = static_cast<double>(_endTimeVec - _startTimeVec) / CLOCKS_PER_SEC * 1e6;
	double timeDeque = static_cast<double>(_endTimeDeque - _startTimeDeque) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << _vectInt.size()
			  << " elements with std::vector: " << timeVect << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeInt.size()
			  << " elements with std::deque: " << timeDeque << " us" << std::endl;
}

void	PmergeMe::insertInVect(std::vector<int>& vect, size_t start, size_t end)
{
	for (size_t i = start + 1; i < end; i++)
	{
		int nb = vec[i];
		size_t j = i;
		while (j > start && vect[j - 1] > nb)
		{
			vect[j] = vect[j - 1];
			j--;
		}
		vect[j] = nb;
	}
}

void	PmergeMe::sortPairsVect(size_t n)
{
	for (size_t i = 0; i + 1 < n; i+=2)
	{
		if (_vectInt[i] > _vectInt[i + 1])
			std::swap(_vectInt[i], _vectInt[i + 1]);
	}
}

void	PmergeMe::insertPairsSecondMembersVect(size_t n, std::vector<int>& vect)
{
	for (size_t i = 0; i + 1 < n; i+=2)
	{
		int nb = _vectInt[i + 1];
		std::vector<int>::iterator pos = std::upper_bound(vect.begin(), vect.end(), nb);
		vect.insert(pos, nb);
	}
}

void	PmergeMe::sortVector()
{
	std::vector<int> sortedVect;
	size_t	len = _vectInt.size();
	_startTimeVect = std::time(NULL);
	if (len <= 1)
		return;
	sortPairsVect(len);
	for (size_t i = 0; i + 1 < len; i+=2)
		sortedVect.push_back(_vectInt[i]);
	if (len % 2 != 0)
		sortedVect.push_back(_vectInt[len - 1]);
	insertPairsSecondMembersVect(len, sortedVect);
	_endTimeVect = std::time(NULL);
	_vectInt = sortedVect;
}

void	PmergeMe::insertInDeque(std::deque<int>& deque, size_t start, size_t end)
{
	for (size_t i = start + 1; i < end; i++)
	{
		int nb = deque[i];
		size_t j = i;
		while (j > start && deque[j - 1] > nb)
		{
			deque[j] = deque[j - 1];
			j--;
		}
		deque[j] = nb;
	}
}

void	PmergeMe::sortPairsDeque(size_t n)
{
	for (size_t i = 0; i + 1 < n; i+=2)
	{
		if (_dequeInt[i] > _dequeInt[i + 1])
			std::swap(_dequeInt[i], _dequeInt[i + 1]);
	}
}

void	PmergeMe::insertPairsSecondMembersDeque(size_t n, std::deque<int>& deque)
{
	for (size_t i = 0; i + 1 < n; i+=2)
	{
		int nb = _dequeInt[i + 1];
		std::deque<int>::iterator pos = std::upper_bound(deque.begin(), deque.end(), nb);
		deque.insert(pos, nb);
	}
}

void	PmergeMe::sortDeque()
{
	std::deque<int> sortedDeque;
	size_t	len = _dequeInt.size();
	_startTimeDeque = std::time(NULL);
	if (len <= 1)
		return;
	sortPairsDeque(len);
	for (size_t i = 0; i + 1 < len; i+=2)
		sortedDeque.push_back(_dequeInt[i]);
	if (len % 2 != 0)
		sortedDeque.push_back(_dequeInt[len - 1]);
	insertPairsSecondMembersDeque(len, sortedDeque);
	_endTimeDeque = std::time(NULL);
	_dequeInt = sortedDeque;
}

void	PmergeMe::announce(std::string message)
{
	std::cout << message;
	for (std::vector<int>::iterator it = _vectInt.begin(); it != vectInt.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

bool	validArg(std::string nbStr)
{
	if (nbStr.empty())
		return (false);
	size_t i = 0;
	if (nbStr[0] == '+' || nbStr[0] == '-')
		i++;
	if (i == nbStr.size())
		return (false);
	for (; i < nbStr.size(); ++i)
	{
		if (!std::isdigit(nbStr[i]))
			return (false);
	}
	return (true);
}

bool	isPositive(std::string nbStr)
{
	int nb = std::atoi(nbStr.c_str());
	return (nb > 0);
}

bool	isInt(std::string nbStr)
{
	long nb = std::atol(nbStr.c_str());
	return (nb <= INT_MAX);
}
