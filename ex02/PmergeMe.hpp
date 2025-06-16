
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <iostream>
# include <algorithm>
# include <deque>
# include <vector>
# include <exception>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe & toCopy);
		PmergeMe & operator=(const PmergeMe & other);

		void		process();

		Class SynaxException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: syntax error";
				}
		};
		Class NotPositiveException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: all numbers must be positive";
				}
		};

	private:
		time_t				_startTimeVect;
		time_t				_endTimeVect;
		time_t				_startTimeDeque;
		time_t				_endTimeDeque;
		std::vector<int>	_vectInt;
		std::deque<int>		_dequeInt;

		void				sortVector();
		void				makePairsVect();
		void				insertInVect();
        void				sortDeque();
		void				makePairsDeque();
		void				insertInDeque();
		void				announce(std::string message);

};

#endif
