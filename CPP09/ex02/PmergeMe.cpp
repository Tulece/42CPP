#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vectorData = other._vectorData;
		this->_dequeData = other._dequeData;
		this->_vectorTime = other._vectorTime;
		this->_dequeTime = other._dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::loadData(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (!isValidNumber(arg))
			throw std::invalid_argument("Error");

		long num = std::strtol(arg.c_str(), NULL, 10);
		if (num < 0 || num > INT_MAX)
			throw std::invalid_argument("Error");

		int value = static_cast<int>(num);
		_vectorData.push_back(value);
		_dequeData.push_back(value);
		_listData.push_back(value);

		_originalVectorData.push_back(value);
		_originalDequeData.push_back(value);
		_originalListData.push_back(value);
	}
}


bool PmergeMe::isValidNumber(const std::string& str)
{
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void PmergeMe::sortData()
{
	const int iterations = 1000;
	double totalVectorTime = 0.0;
	double totalDequeTime = 0.0;
	double totalListTime = 0.0;

	for (int i = 0; i < iterations; ++i)
	{
		std::vector<int> vectorCopy = _originalVectorData;
		std::deque<int> dequeCopy = _originalDequeData;
		std::list<int> listCopy = _originalListData;

		clock_t startClock = clock();
		mergeInsertSortVector(vectorCopy);
		clock_t endClock = clock();
		totalVectorTime += static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1e6;

		startClock = clock();
		mergeInsertSortDeque(dequeCopy);
		endClock = clock();
		totalDequeTime += static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1e6;

		startClock = clock();
		mergeInsertSortList(listCopy);
		endClock = clock();
		totalListTime += static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1e6;
	}

	_vectorTime = totalVectorTime / iterations;
	_dequeTime = totalDequeTime / iterations;
	_listTime = totalListTime / iterations;

	_vectorData = _originalVectorData;
	mergeInsertSortVector(_vectorData);

	_dequeData = _originalDequeData;
	mergeInsertSortDeque(_dequeData);

	_listData = _originalListData;
	mergeInsertSortList(_listData);
}




void PmergeMe::displayResults(bool beforeSorting)
{
	const std::vector<int>& vectorToDisplay = beforeSorting ? _originalVectorData : _vectorData;
	std::cout << (beforeSorting ? "Before: " : "After: ");
	for (size_t i = 0; i < vectorToDisplay.size(); ++i)
	{
		std::cout << vectorToDisplay[i] << " ";
		if (i == 4 && vectorToDisplay.size() > 5)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;

	if (!beforeSorting)
	{
		std::cout << std::fixed << std::setprecision(3);
		std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : ";
		std::cout << _vectorTime << " us" << std::endl;

		std::cout << "Time to process a range of " << _dequeData.size() << " elements with std::deque : ";
		std::cout << _dequeTime << " us" << std::endl;

		std::cout << "Time to process a range of " << _listData.size() << " elements with std::list : ";
		std::cout << _listTime << " us" << std::endl;
	}
}



void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;
	int left = 0;
	int right = vec.size() - 1;
	int threshold = 16;
	if (right - left <= threshold)
		insertionSortVector(vec, left, right);
	else
	{
		int mid = (left + right) / 2;
		std::vector<int> leftVec(vec.begin(), vec.begin() + mid + 1);
		std::vector<int> rightVec(vec.begin() + mid + 1, vec.end());
		mergeInsertSortVector(leftVec);
		mergeInsertSortVector(rightVec);
		vec.clear();
		vec.insert(vec.end(), leftVec.begin(), leftVec.end());
		vec.insert(vec.end(), rightVec.begin(), rightVec.end());
		mergeVector(vec, left, mid, right);
	}
}

void PmergeMe::insertionSortVector(std::vector<int>& vec, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= left && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}
}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int mid, int right)
{
	std::vector<int> temp(vec.begin() + left, vec.begin() + right + 1);
	int i = 0;
	int j = mid - left + 1;
	int k = left;

	while (i <= mid - left && j <= right - left)
	{
		if (temp[i] <= temp[j])
			vec[k++] = temp[i++];
		else
			vec[k++] = temp[j++];
	}
	while (i <= mid - left)
		vec[k++] = temp[i++];
	while (j <= right - left)
		vec[k++] = temp[j++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;
	int left = 0;
	int right = deq.size() - 1;
	int threshold = 16;
	if (right - left <= threshold)
		insertionSortDeque(deq, left, right);
	else
	{
		int mid = (left + right) / 2;
		std::deque<int> leftDeq(deq.begin(), deq.begin() + mid + 1);
		std::deque<int> rightDeq(deq.begin() + mid + 1, deq.end());
		mergeInsertSortDeque(leftDeq);
		mergeInsertSortDeque(rightDeq);
		deq.clear();
		deq.insert(deq.end(), leftDeq.begin(), leftDeq.end());
		deq.insert(deq.end(), rightDeq.begin(), rightDeq.end());
		mergeDeque(deq, left, mid, right);
	}
}

void PmergeMe::insertionSortDeque(std::deque<int>& deq, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = deq[i];
		int j = i - 1;
		while (j >= left && deq[j] > key)
		{
			deq[j + 1] = deq[j];
			--j;
		}
		deq[j + 1] = key;
	}
}

void PmergeMe::mergeDeque(std::deque<int>& deq, int left, int mid, int right)
{
	std::deque<int> temp(deq.begin() + left, deq.begin() + right + 1);
	int i = 0;
	int j = mid - left + 1;
	int k = left;

	while (i <= mid - left && j <= right - left)
	{
		if (temp[i] <= temp[j])
			deq[k++] = temp[i++];
		else
			deq[k++] = temp[j++];
	}
	while (i <= mid - left)
		deq[k++] = temp[i++];
	while (j <= right - left)
		deq[k++] = temp[j++];
}

void PmergeMe::mergeInsertSortList(std::list<int>& lst)
{
	if (lst.size() <= 1)
		return;

	if (lst.size() <= 16)
	{
		insertionSortList(lst);
		return;
	}

	std::list<int> left;
	std::list<int> right;
	std::list<int>::iterator it = lst.begin();
	std::advance(it, lst.size() / 2);
	left.splice(left.begin(), lst, lst.begin(), it);
	right.splice(right.begin(), lst, lst.begin(), lst.end());

	mergeInsertSortList(left);
	mergeInsertSortList(right);

	lst.clear();
	mergeList(left, right, lst);
}

void PmergeMe::insertionSortList(std::list<int>& lst)
{
	if (lst.size() <= 1)
		return;

	std::list<int>::iterator it = lst.begin();
	++it;

	for (; it != lst.end(); ++it)
	{
		int key = *it;
		std::list<int>::iterator prev = it;
		--prev;

		while (it != lst.begin() && *prev > key)
		{
			std::list<int>::iterator next = prev;
			++next;
			*next = *prev;
			if (prev == lst.begin())
				break;
			--prev;
		}

		std::list<int>::iterator next = prev;
		++next;
		*next = key;
	}
}

void PmergeMe::mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& result)
{
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft <= *itRight)
		{
			result.push_back(*itLeft);
			++itLeft;
		}
		else
		{
			result.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end())
	{
		result.push_back(*itRight);
		++itRight;
	}
}
