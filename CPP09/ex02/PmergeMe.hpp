#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <climits>

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
	std::list<int> _listData;

	std::vector<int> _originalVectorData;
	std::deque<int> _originalDequeData;
	std::list<int> _originalListData;

	double _vectorTime;
	double _dequeTime;
	double _listTime;

	bool isValidNumber(const std::string& str);

	void mergeInsertSortVector(std::vector<int>& vec);
	void insertionSortVector(std::vector<int>& vec, int left, int right);
	void mergeVector(std::vector<int>& vec, int left, int mid, int right);

	void mergeInsertSortDeque(std::deque<int>& deq);
	void insertionSortDeque(std::deque<int>& deq, int left, int right);
	void mergeDeque(std::deque<int>& deq, int left, int mid, int right);

	void mergeInsertSortList(std::list<int>& lst);
	void insertionSortList(std::list<int>& lst);
	void mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& result);
};

#endif
