#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <iostream>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void loadData(int argc, char** argv);
	void sortData();
	void displayResults(bool beforeSorting);

private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;

	std::vector<int> _originalVectorData;
	std::deque<int> _originalDequeData;

	double _vectorTime;
	double _dequeTime;

	bool isValidNumber(const std::string& str);

	void sortVector();
	void sortDeque();

	void mergeInsertSortVector(std::vector<int>& vec);
	void insertionSortVector(std::vector<int>& vec, int left, int right);
	void mergeVector(std::vector<int>& vec, int left, int mid, int right);

	void mergeInsertSortDeque(std::deque<int>& deq);
	void insertionSortDeque(std::deque<int>& deq, int left, int right);
	void mergeDeque(std::deque<int>& deq, int left, int mid, int right);
};

#endif
