
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <iostream>
# include <algorithm>
# include <deque>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & toCopy);
		PmergeMe & operator=(const PmergeMe & other);
		void		getChrono() const;

	private:
		time_t				_startTime;
		// static void sortVector(std::vector<int>& vec);
        // static void sortDeque(std::deque<int>& deq);

		std::vector<int>&	_vectInt;
		std::deque<int>&	_dequeInt;

};

#endif
