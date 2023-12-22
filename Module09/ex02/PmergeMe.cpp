#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_jacobsthalNumber.push_back(0);
	_jacobsthalNumber.push_back(1);
	_jacobsthalNumber.push_back(3);
	_jacobsthalNumber.push_back(5);
	_jacobsthalNumber.push_back(11);
	_jacobsthalNumber.push_back(21);
	_jacobsthalNumber.push_back(43);
	_jacobsthalNumber.push_back(85);
	_jacobsthalNumber.push_back(171);
	_jacobsthalNumber.push_back(341);
	_jacobsthalNumber.push_back(683);
	_jacobsthalNumber.push_back(1365);
	_jacobsthalNumber.push_back(2731);
	_jacobsthalNumber.push_back(5461);
	_jacobsthalNumber.push_back(10923);
	_jacobsthalNumber.push_back(21845);
	_jacobsthalNumber.push_back(43691);
	_jacobsthalNumber.push_back(87381);
	_jacobsthalNumber.push_back(174763);
	_jacobsthalNumber.push_back(349525);
	_jacobsthalNumber.push_back(699051);
	_jacobsthalNumber.push_back(1398101);
	_jacobsthalNumber.push_back(2796203);
	_jacobsthalNumber.push_back(5592405);
	_jacobsthalNumber.push_back(11184811);
	_jacobsthalNumber.push_back(22369621);
	_jacobsthalNumber.push_back(44739243);
	_jacobsthalNumber.push_back(89478485);
	_jacobsthalNumber.push_back(178956971);
	_jacobsthalNumber.push_back(357913941);
	_jacobsthalNumber.push_back(715827883);
	_jacobsthalNumber.push_back(1431655765);
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

void PmergeMe::binarySort(int start, int end, int pendPos, int onePairSize, std::vector<int> &pendingChainVector)
{
	int mainNpendingDiff = onePairSize / 2;
	int right = 1;
	std::vector<int>::iterator insertPos_it;
	std::vector<int>::iterator pendStart_it;
	std::vector<int>::iterator pendEnd_it;
	int start_adj = start * mainNpendingDiff;
	int end_adj = end * mainNpendingDiff;
	int pendPos_adj = pendPos * mainNpendingDiff;

	if (start >= end)
	{
		pendStart_it = pendingChainVector.begin() + pendPos_adj;
		pendEnd_it = pendingChainVector.begin() + (pendPos_adj + (mainNpendingDiff));
		if (pendingChainVector[pendPos_adj] < _mainChainVector[start_adj])
			insertPos_it = _mainChainVector.begin() + start_adj;
		else
			insertPos_it = _mainChainVector.begin() + ((start + right) * mainNpendingDiff);
		_mainChainVector.insert(insertPos_it, pendStart_it, pendEnd_it);
		return ;
	}
	// std::cout << "here" << std::endl;
	std::cout << "start: " << start << " end: " << end << std::endl;
	std::cout << "start_adj: " << start_adj << " end_adj: " << end_adj << std::endl;
	std::cout << "mid_value: " << _mainChainVector[start + ((end - start) / 2)] << " mididx: " << start + ((end - start) / 2) << std::endl;
	if (_mainChainVector[start_adj + ((end_adj - start_adj) / 2)] < pendingChainVector[pendPos_adj])
		binarySort((start + ((end - start) / 2)) + 1, end, pendPos, onePairSize, pendingChainVector);
	else
		binarySort(start, (start + ((end - start) / 2)) - 1, pendPos, onePairSize, pendingChainVector);
}

void PmergeMe::jacobMerge(std::vector<int> &pendingChainVector, int onePairSize)
{
	int mainNpendingDiff = onePairSize / 2;
	int jacobIdex = 1;
	int insertedCnt = 0;
	int previous = -1;
	int pendingChainSize = static_cast<int>(pendingChainVector.size()) / mainNpendingDiff;

	// std::cout << "before fore line" << std::endl;
	for (int pendIdx = 0; pendIdx < pendingChainSize; pendIdx++)
	{
		pendIdx = _jacobsthalNumber[jacobIdex] + previous;
		if (pendIdx + 1 > pendingChainSize)
		{
			pendIdx = pendingChainVector.size() / mainNpendingDiff - 1;
			// std::cout << "last: " << pendIdx << std::endl;
		}
		while(_jacobsthalNumber[jacobIdex + previous] < pendIdx + 1)
		{
			std::cout << "sort start" << std::endl;
			if (pendIdx == 0)
				binarySort(0, pendIdx + insertedCnt, pendIdx, onePairSize, pendingChainVector);
			else
				binarySort(0, pendIdx + insertedCnt - 1, pendIdx, onePairSize, pendingChainVector);
			insertedCnt++;
			std::cout << "sort result: " << "pending_idx " << pendIdx << std::endl;
			for (int i = 0; i < static_cast<int>(_mainChainVector.size()); i++)
				std::cout << _mainChainVector[i] << " ";
			std::cout << std::endl << std::endl;
			pendIdx--;
		}
		pendIdx = _jacobsthalNumber[jacobIdex] + previous;
		jacobIdex++;
	}
	// std::cout << std::endl << std::endl;
}

void PmergeMe::decouplePendingChain(std::vector<int> &pendingChainVector, int elementCount, int onePairSize)
{
	//a = this->_mainChainVector[i * onePairSize]
	//b = this->_mainChainVector[i * onePairSize + (onePairSize / 2)]
	std::vector<int> mainchain;
	int pairIndex = 0;
	int mainNpendingDiff = onePairSize / 2;
	int totalPairCnt = elementCount / 2;
	int i = 0;

	while (i < totalPairCnt)
	{
		pairIndex = i * onePairSize;
		for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
			mainchain.push_back(_mainChainVector[pairIndex + leftPair]);
		for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
			pendingChainVector.push_back(_mainChainVector[pairIndex + mainNpendingDiff + leftPair]);
		i++;
	}
	pairIndex = i * onePairSize;
	if (elementCount % 2 == 1)
		for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
			pendingChainVector.push_back(_mainChainVector[pairIndex + leftPair]);
	_mainChainVector = mainchain;
}

void PmergeMe::swapPairs(int totalPairCnt, int onePairSize, int mainNpendingDiff)
{
	int pairIndex = 0;

	std::cout << "swap" << std::endl;
	for (int i = 0; i < totalPairCnt; i++)
	{
		pairIndex = i * onePairSize;
		if (_myVector[pairIndex] < _myVector[pairIndex + mainNpendingDiff])
		{
			for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
				std::swap(_myVector[pairIndex + leftPair], _myVector[pairIndex + mainNpendingDiff + leftPair]);
		}
		std::cout << "[" << this->_myVector[pairIndex] << "," << this->_myVector[pairIndex + mainNpendingDiff] << "]" << std::endl;
	}
}

void PmergeMe::mergeInsertSort(int elementCount, int onePairSize)
{
	int mainNpendingDiff = onePairSize / 2;
	int totalPairCnt = elementCount / 2;
	std::vector<int> pendingChainVector;

	if (elementCount == 1)
	{
		_mainChainVector = _myVector;
		return ;
	}
	swapPairs(totalPairCnt, onePairSize, mainNpendingDiff);
	mergeInsertSort(elementCount / 2, onePairSize * 2);
	decouplePendingChain(pendingChainVector, elementCount, onePairSize);

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "mainChain: " << onePairSize / 2 << " set" << ", depth " << onePairSize / 2 << std::endl;
	for (size_t i = 0; i < this->_mainChainVector.size(); i++)
		std::cout << this->_mainChainVector[i] << " ";
	std::cout << std::endl;
	std::cout << "pendingChain" << std::endl;
	for (size_t i = 0; i < pendingChainVector.size(); i++)
		std::cout << pendingChainVector[i] << " ";
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	jacobMerge(pendingChainVector, onePairSize);
	std::cout << std::endl;
}

void PmergeMe::sortVector()
{
	int before = 0;
	int After = 0;
	_beforeMyVector = _myVector;
	before = clock();
	mergeInsertSort(this->_elementCount, 2);
	After = clock();
	this->_VectorTime = After - before;
}

void PmergeMe::printResult()
{
	std::cout << "Before: ";
	printVector(this->_beforeMyVector);
	std::cout << "After:  ";
	printVector(this->_mainChainVector);
	std::cout \
	<< "Time to process a range of " << this->_elementCount << std::setw(10) << std::setfill('0') \
	<< " elements with std::vector : " << this->_VectorTime \
	<< " us" << std::endl;
	std::cout \
	<< "Time to process a range of " << this->_elementCount \
	<< " elements with std::deque : " << this->_DequeTime << std::setw(10) << std::setfill('0') \
	<< " us" << std::endl;
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
	// int i = 20;
	for (std::vector<int>::iterator it = vectorVar.begin(); it != vectorVar.end(); it++)
	{
		// if (i == 0)
		// {
		// 	std::cout << "...." << std::endl;
		// 	return ;
		// }
		std::cout << " ";
		std::cout << *it;
		// i--;
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
	printResult();
}
