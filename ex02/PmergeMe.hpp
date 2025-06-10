
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & toCopy);
		PmergeMe & operator=(const PmergeMe & other);

	private:
		time_t		_startTime;

};

#endif
