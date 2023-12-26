#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_VectorTime = 0;
	_DequeTime = 0;
	_elementCount = 0;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_VectorTime = other._VectorTime;
        this->_DequeTime = other._DequeTime;
        this->_elementCount = other._elementCount;
        this->_jacobsthalNumber = other._jacobsthalNumber;
        this->_myVector = other._myVector;
        this->_beforeMyVector = other._beforeMyVector;
        this->_mainChainVector = other._mainChainVector;
 	   	this->_myDeque = other._myDeque;
  	  	this->_beforeMyDeque = other._beforeMyDeque;
   		this->_mainChainDeque = other._mainChainDeque;
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

void PmergeMe::initJacobsthalNumber(int n)
{
	int before_t0 = 0;
	int before_t1 = 1;
	int current_t = 0;

	while (current_t <= n)
	{
		_jacobsthalNumber.push_back(current_t);
		current_t = before_t1 + (before_t0 * 2);
		before_t0 = before_t1;
		before_t1 = current_t;
	}
	_jacobsthalNumber.push_back(current_t);
}

void PmergeMe::vectorBinarySort(int start, int end, int pendPos, int onePairSize, std::vector<int> &pendingChainVector)
{
	int mainNpendingDiff = onePairSize / 2;
	int right = 1;
	std::vector<int>::iterator insertPos_it;
	std::vector<int>::iterator pendStart_it;
	std::vector<int>::iterator pendEnd_it;
	int start_adj = start * mainNpendingDiff;
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
	if (_mainChainVector[start_adj + (((end - start) / 2) * mainNpendingDiff)] < pendingChainVector[pendPos_adj])
		vectorBinarySort((start + ((end - start) / 2)) + 1, end, pendPos, onePairSize, pendingChainVector);
	else
		vectorBinarySort(start, (start + ((end - start) / 2)) - 1, pendPos, onePairSize, pendingChainVector);
}

void PmergeMe::vectorJacobMerge(std::vector<int> &pendingChainVector, int onePairSize)
{
	int mainNpendingDiff = onePairSize / 2;
	int jacobIdex = 1;
	int insertedCnt = 0;
	int previous = -1;
	int pendingChainSize = static_cast<int>(pendingChainVector.size()) / mainNpendingDiff;

	for (int pendIdx = 0; pendIdx < pendingChainSize; pendIdx++)
	{
		pendIdx = _jacobsthalNumber[jacobIdex] + previous;
		if (pendIdx + 1 > pendingChainSize)
			pendIdx = pendingChainSize - 1;
		while(_jacobsthalNumber[jacobIdex + previous] < pendIdx + 1)
		{
			vectorBinarySort(0, pendIdx + insertedCnt - 1, pendIdx, onePairSize, pendingChainVector);
			insertedCnt++;
			pendIdx--;
		}
		pendIdx = _jacobsthalNumber[jacobIdex] + previous;
		jacobIdex++;
	}
}

void PmergeMe::vectorDecouplePendingChain(std::vector<int> &pendingChainVector, int elementCount, int onePairSize, std::vector<int> oddPending)
{
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
			pendingChainVector.push_back(oddPending[pairIndex + leftPair]);
	_mainChainVector = mainchain;
}

void PmergeMe::vectorSwapPairs(int totalPairCnt, int onePairSize, int mainNpendingDiff)
{
	int pairIndex = 0;

	for (int i = 0; i < totalPairCnt; i++)
	{
		pairIndex = i * onePairSize;
		if (_myVector[pairIndex] < _myVector[pairIndex + mainNpendingDiff])
		{
			for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
				std::swap(_myVector[pairIndex + leftPair], _myVector[pairIndex + mainNpendingDiff + leftPair]);
		}
	}
}

void PmergeMe::vectorMergeInsertSort(int elementCount, int onePairSize, std::vector<int> oddPending)
{
	int mainNpendingDiff = onePairSize / 2;
	int totalPairCnt = elementCount / 2;
	std::vector<int> pendingChainVector;

	if (elementCount == 1)
	{
		oddPending = _myVector;
		_mainChainVector = _myVector;
		return ;
	}
	vectorSwapPairs(totalPairCnt, onePairSize, mainNpendingDiff);
	oddPending = _myVector;
	vectorMergeInsertSort(elementCount / 2, onePairSize * 2, oddPending);
	vectorDecouplePendingChain(pendingChainVector, elementCount, onePairSize, oddPending);
	vectorJacobMerge(pendingChainVector, onePairSize);
}

void PmergeMe::sortVector()
{
	std::vector<int> oddPending;
	double before = 0;
	double After = 0;
	_beforeMyVector = _myVector;
	before = clock();
	vectorMergeInsertSort(this->_elementCount, 2, oddPending);
	After = clock();
	this->_VectorTime = (After - before) / 1000;
}

void PmergeMe::DequeBinarySort(int start, int end, int pendPos, int onePairSize, std::deque<int> &pendingChainDeque)
{
	int mainNpendingDiff = onePairSize / 2;
	int right = 1;
	std::deque<int>::iterator insertPos_it;
	std::deque<int>::iterator pendStart_it;
	std::deque<int>::iterator pendEnd_it;
	int start_adj = start * mainNpendingDiff;
	int pendPos_adj = pendPos * mainNpendingDiff;

	if (start >= end)
	{
		pendStart_it = pendingChainDeque.begin() + pendPos_adj;
		pendEnd_it = pendingChainDeque.begin() + (pendPos_adj + (mainNpendingDiff));
		if (pendingChainDeque[pendPos_adj] < _mainChainDeque[start_adj])
			insertPos_it = _mainChainDeque.begin() + start_adj;
		else
			insertPos_it = _mainChainDeque.begin() + ((start + right) * mainNpendingDiff);
		_mainChainDeque.insert(insertPos_it, pendStart_it, pendEnd_it);
		return ;
	}
	if (_mainChainDeque[start_adj + (((end - start) / 2) * mainNpendingDiff)] < pendingChainDeque[pendPos_adj])
		DequeBinarySort((start + ((end - start) / 2)) + 1, end, pendPos, onePairSize, pendingChainDeque);
	else
		DequeBinarySort(start, (start + ((end - start) / 2)) - 1, pendPos, onePairSize, pendingChainDeque);
}

void PmergeMe::DequeJacobMerge(std::deque<int> &pendingChainDeque, int onePairSize)
{
	int mainNpendingDiff = onePairSize / 2;
	int jacobIdex = 1;
	int insertedCnt = 0;
	int previous = -1;
	int pendingChainSize = static_cast<int>(pendingChainDeque.size()) / mainNpendingDiff;

	for (int pendIdx = 0; pendIdx < pendingChainSize; pendIdx++)
	{
		pendIdx = _jacobsthalNumber[jacobIdex] + previous;
		if (pendIdx + 1 > pendingChainSize)
			pendIdx = pendingChainSize - 1;
		while(_jacobsthalNumber[jacobIdex + previous] < pendIdx + 1)
		{
			DequeBinarySort(0, pendIdx + insertedCnt - 1, pendIdx, onePairSize, pendingChainDeque);
			insertedCnt++;
			pendIdx--;
		}
		pendIdx = _jacobsthalNumber[jacobIdex] + previous;
		jacobIdex++;
	}
}

void PmergeMe::DequeDecouplePendingChain(std::deque<int> &pendingChainDeque, int elementCount, int onePairSize, std::deque<int> oddPending)
{
	//a = this->_mainChainDeque[i * onePairSize]
	//b = this->_mainChainDeque[i * onePairSize + (onePairSize / 2)]
	std::deque<int> mainchain;
	int pairIndex = 0;
	int mainNpendingDiff = onePairSize / 2;
	int totalPairCnt = elementCount / 2;
	int i = 0;

	while (i < totalPairCnt)
	{
		pairIndex = i * onePairSize;
		for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
			mainchain.push_back(_mainChainDeque[pairIndex + leftPair]);
		for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
			pendingChainDeque.push_back(_mainChainDeque[pairIndex + mainNpendingDiff + leftPair]);
		i++;
	}
	pairIndex = i * onePairSize;
	if (elementCount % 2 == 1)
		for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
			pendingChainDeque.push_back(oddPending[pairIndex + leftPair]);
	_mainChainDeque = mainchain;
}

void PmergeMe::DequeSwapPairs(int totalPairCnt, int onePairSize, int mainNpendingDiff)
{
	int pairIndex = 0;

	for (int i = 0; i < totalPairCnt; i++)
	{
		pairIndex = i * onePairSize;
		if (_myDeque[pairIndex] < _myDeque[pairIndex + mainNpendingDiff])
		{
			for (int leftPair = 0; leftPair < mainNpendingDiff; leftPair++)
				std::swap(_myDeque[pairIndex + leftPair], _myDeque[pairIndex + mainNpendingDiff + leftPair]);
		}
	}
}

void PmergeMe::DequeMergeInsertSort(int elementCount, int onePairSize, std::deque<int> oddPending)
{
	int mainNpendingDiff = onePairSize / 2;
	int totalPairCnt = elementCount / 2;
	std::deque<int> pendingChainDeque;

	if (elementCount == 1)
	{
		oddPending = _myDeque;
		_mainChainDeque = _myDeque;
		return ;
	}
	DequeSwapPairs(totalPairCnt, onePairSize, mainNpendingDiff);
	oddPending = _myDeque;
	DequeMergeInsertSort(elementCount / 2, onePairSize * 2, oddPending);
	DequeDecouplePendingChain(pendingChainDeque, elementCount, onePairSize, oddPending);
	DequeJacobMerge(pendingChainDeque, onePairSize);
}

void PmergeMe::sortDeque()
{
	std::deque<int> oddPending;
	double before = 0;
	double After = 0;
	_beforeMyDeque = _myDeque;
	before = clock();
	DequeMergeInsertSort(this->_elementCount, 2, oddPending);
	After = clock();
	this->_DequeTime = (After - before) / 1000;
	return ;
}

void PmergeMe::printResult()
{
	std::cout << "Before: ";
	printVector(this->_beforeMyVector);
	std::cout << "After Vector:  ";
	printVector(this->_mainChainVector);
	std::cout << "After Deque :  ";
	printDeque(this->_mainChainDeque);
	std::cout \
	<< "Time to process a range of " << this->_elementCount \
	<< " elements with std::vector : " << this->_VectorTime \
	<< " ms" << std::endl;
	std::cout \
	<< "Time to process a range of " << this->_elementCount \
	<< " elements with std::deque : " << this->_DequeTime \
	<< " ms" << std::endl;
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
	_elementCount = i;
	if (_elementCount > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

void PmergeMe::run(char **argv)
{
	this->_DequeTime = 0;
	if (charPtrToInt(argv) == false)
		return (errorPrint("Error"));
	initJacobsthalNumber(_elementCount);
	sortVector();
	sortDeque();
	printResult();
}
