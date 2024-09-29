#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;

	try
	{
		sorter.loadData(argc, argv);
		sorter.displayResults(true);

		sorter.sortData();

		sorter.displayResults(false);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}

