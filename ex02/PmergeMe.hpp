
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <iostream>
# include <algorithm>
# include <deque>
# include <vector>
# include <exception>
# include <climits>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe & toCopy);
		PmergeMe & operator=(const PmergeMe & other);

		void				process();

		class SyntaxException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: syntax error";
				}
		};
		class NotPositiveException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: all numbers must be positive";
				}
		};
		class NotIntException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: all numbers must be under INT_MAX";
				}
		};

	private:
		clock_t				_startTimeVect;
		clock_t				_endTimeVect;
		clock_t				_startTimeDeque;
		clock_t				_endTimeDeque;
		std::vector<int>	_vectInt;
		std::deque<int>		_dequeInt;

		void				sortVector();
		void				sortDeque();

		void				sortPairsVect(size_t n);
		void				insertPairsSecondMembersVect(size_t n, std::vector<int>& vect);
		void				insertInVect(std::vector<int>& vect, size_t start, size_t end);
		void				sortPairsDeque(size_t n);
		void				insertPairsSecondMembersDeque(size_t n, std::deque<int>& deque);
		void				insertInDeque(std::deque<int>& deque, size_t start, size_t end);
		void				announce(std::string message);

};

#endif
