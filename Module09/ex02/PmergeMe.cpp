#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{
}

// void PmergeMe::initJacobsthalNumber(int num)
// {
	
// }

void PmergeMe::printResult()
{
	std::cout << "Before: ";
	printVector(this->_myVector);
	std::cout << "After: ";
	printVector(this->_sortedMyVector);
	std::cout \
	<< "Time to process a range of " << this->_elementCount \
	<< " elements with std::vector : " << this->_VectorTime \
	<< " us" << std::endl;
	std::cout \
	<< "Time to process a range of " << this->_elementCount \
	<< " elements with std::deque : " << this->_DequeTime \
	<< " us" << std::endl;
}

// void PmergeMe::binarySort(int pending)
// {
// 	return ;
// }

void PmergeMe::mergeInsertSort(int totalPairCnt, int depth, int onePairSize)
{
	if (totalPairCnt == 1)
		return ;
	for (int i = 0; i < totalPairCnt / 2; i++)
	{
		if (this->_myVector[i * onePairSize] < this->_myVector[i * onePairSize + (onePairSize / 2)])
			std::swap(this->_myVector[i * onePairSize], this->_myVector[i * onePairSize + (onePairSize / 2)]);
		std::cout << "[" << this->_myVector[i * onePairSize] << "," << this->_myVector[i * onePairSize + (onePairSize / 2)] << "]" << std::endl;
	}
	std::cout << "" << std::endl;
	mergeInsertSort(totalPairCnt / 2, depth + 1, onePairSize * 2);
	// binarySort(b3);
}

void PmergeMe::sortVector()
{
	mergeInsertSort(this->_elementCount, 1, 2);
}

void PmergeMe::sortDeque()
{
	return ;
}

void PmergeMe::errorPrint(std::string message)
{
	std::cout << message << std::endl;
}

void PmergeMe::printDeque(std::deque<int> DequeVar)
{
	for (std::deque<int>::iterator it = DequeVar.begin(); it != DequeVar.end(); it++)
	{
		std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::printVector(std::vector<int> vectorVar)
{
	for (std::vector<int>::iterator it = vectorVar.begin(); it != vectorVar.end(); it++)
	{
		std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

bool PmergeMe::formatCheck(std::string str)
{
	if (str[0] == '+')
		str = str.substr(1);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]) == 0)
			return (false);		
	}
	return (true);
}

bool PmergeMe::charPtrToInt(char **argv)
{
	int i = 0;
	std::istringstream iss;
	double num;

	while (argv[i] != '\0')
	{
		if (formatCheck(argv[i]) == false)
			return (false);
		iss.clear();
		iss.str(argv[i]);
		iss >> num;
		if (num > std::numeric_limits<int>::max())
			return (false);
		this->_myVector.push_back(num);
		this->_myDeque.push_back(num);
		i++;
	}
	this->_elementCount = i;
	return (true);
}

void PmergeMe::run(char **argv)
{
	this->_DequeTime = 0;
	if (charPtrToInt(argv) == false)
		return (errorPrint("Error"));
	sortVector();
	// sortDeque();
	printResult();
}
