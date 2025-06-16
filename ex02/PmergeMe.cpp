/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:17:55 by lmatkows          #+#    #+#             */
/*   Updated: 2025/06/16 15:32:02 by Lmatkows         ###   ########.fr       */
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
		if (!nbIsPPositive(nb))
			throw NotPositiveException();
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
///                                GETTERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////



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
	
}

void	PmergeMe::makePairsVect()
{
	
}

void	PmergeMe::sortVector()
{
	std::vector<int> sortedVect;
	size_t	len = _vectInt.size();
	_startTimeVect = std::time(NULL);
	if (len <= 1)
		return;
	makePairsVect();
	_endTimeVect = std::time(NULL);
	_vectInt = sortedVect;
}

void	PmergeMe::insertInDeque(std::deque<int>& deque, size_t start, size_t end)
{
	
}

void	PmergeMe::makePairsDeque()
{
	size_t	len = _dequeInt.size();
}

void	PmergeMe::sortDeque()
{
	std::deque<int> sortedDeque;
	size_t	len = _dequeInt.size();
	_startTimeDeque = std::time(NULL);
	if (len <= 1)
		return;
	makePairsDeque();
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
