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

void PmergeMe::binarySort(int start, int end, int pendingPosition, int onePairSize, int elementCount, std::vector<int> &pendingChainVector)
{
	if (start >= end)
	{
		if (pendingChainVector[pendingPosition * (onePairSize / 2)] < this->_mainChainVector[start * (onePairSize / 2)])
		{
			std::vector<int>::iterator it = this->_mainChainVector.begin() + (start * (onePairSize / 2));
			std::vector<int>::iterator pendingIdexStart = pendingChainVector.begin() + pendingPosition * (onePairSize / 2);
			std::vector<int>::iterator pendingIdexEnd = pendingChainVector.begin() + (pendingPosition * (onePairSize / 2) + ((onePairSize / 2)));
			this->_mainChainVector.insert(it, pendingIdexStart, pendingIdexEnd);
		}
		else
		{
			std::vector<int>::iterator it = this->_mainChainVector.begin() + ((start + 1) * (onePairSize / 2));
			std::vector<int>::iterator pendingIdexStart = pendingChainVector.begin() + pendingPosition * (onePairSize / 2);
			std::vector<int>::iterator pendingIdexEnd = pendingChainVector.begin() + (pendingPosition * (onePairSize / 2) + ((onePairSize / 2)));
			this->_mainChainVector.insert(it, pendingIdexStart, pendingIdexEnd);
		}
		return ;
	}
	// std::cout << "here" << std::endl;
	if (this->_mainChainVector[(start * (onePairSize / 2)) + (((end * (onePairSize / 2)) - (start * (onePairSize / 2))) / 2)] \
		< pendingChainVector[pendingPosition * (onePairSize / 2)])
		binarySort((start + ((end - start) / 2)) + 1, end, pendingPosition, onePairSize, elementCount, pendingChainVector);
	else
		binarySort(start, (start + ((end - start) / 2)) - 1, pendingPosition, onePairSize, elementCount, pendingChainVector);
}

void PmergeMe::decouplePendingChain(std::vector<int> &pendingChainVector, int elementCount, int depth, int onePairSize)
{
	//a = this->_mainChainVector[i * onePairSize]
	//b = this->_mainChainVector[i * onePairSize + (onePairSize / 2)]
	std::vector<int> mainchain;

	(void)depth;
	int i = 0;

	while (i < elementCount / 2)
	{
		for (int leftPair = 0; leftPair < onePairSize / 2; leftPair++)
			mainchain.push_back(this->_mainChainVector[i * onePairSize + leftPair]);
		for (int leftPair = 0; leftPair < onePairSize / 2; leftPair++)
			pendingChainVector.push_back(this->_mainChainVector[i * onePairSize + (onePairSize / 2) + leftPair]);
		i++;
	}
	if (elementCount % 2 == 1)
		for (int leftPair = 0; leftPair < onePairSize / 2; leftPair++)
			pendingChainVector.push_back(this->_mainChainVector[i * onePairSize + leftPair]);
	this->_mainChainVector = mainchain;
}

void PmergeMe::mergeInsertSort(int elementCount, int depth, int onePairSize)
{
	if (elementCount == 1)
	{
		this->_mainChainVector = this->_myVector;
		return ;
	}
	int totalPairCnt = elementCount / 2;
	for (int i = 0; i < totalPairCnt; i++)
	{
		if (this->_myVector[i * onePairSize] < this->_myVector[i * onePairSize + (onePairSize / 2)])
		{
			for (int leftPair = 0; leftPair < onePairSize / 2; leftPair++)
				std::swap(this->_myVector[i * onePairSize + leftPair], this->_myVector[i * onePairSize + (onePairSize / 2) + leftPair]);
		}
		// std::cout << "[" << this->_myVector[i * onePairSize] << "," << this->_myVector[i * onePairSize + (onePairSize / 2)] << "]" << std::endl;
	}
	// std::cout << std::endl << std::endl;
	mergeInsertSort(elementCount / 2, depth + 1, onePairSize * 2);
	std::vector<int> pendingChainVector;
	decouplePendingChain(pendingChainVector, elementCount, depth, onePairSize);

	// std::cout << "mainChain : " << std::endl;
	// for (size_t i = 0; i < this->_mainChainVector.size(); i++)
	// 	std::cout << this->_mainChainVector[i] << " ";
	// std::cout << std::endl;
	// std::cout << "pendingChain : " << std::endl;
	// for (size_t i = 0; i < pendingChainVector.size(); i++)
	// 	std::cout << pendingChainVector[i] << " ";
	// std::cout << std::endl << std::endl;

	int jacobIdex = 1;
	size_t insertedCnt = 0;

	if (pendingChainVector.size() / (onePairSize / 2) == 1)
	{
		binarySort(0, 0, 0, onePairSize, elementCount, pendingChainVector);
		insertedCnt++;
		// std::cout << std::endl << "0 sort -------------: " << std::endl;
		// for (size_t i = 0; i < this->_mainChainVector.size(); i++)
		// 	std::cout << this->_mainChainVector[i] << " ";
		// std::cout << std::endl << std::endl;
		return ;
	}
	// std::cout << "before fore line" << std::endl;
	for (int i = 0; i < static_cast<int>(pendingChainVector.size()) / (onePairSize / 2); i++)
	{
		// std::cout << "for inner" << std::endl;
		if (i < this->_jacobsthalNumber[jacobIdex])
		{
			i = this->_jacobsthalNumber[jacobIdex] - 1;
			if (i + 1 > static_cast<int>(pendingChainVector.size()) / (onePairSize / 2))
			{
				i = pendingChainVector.size() / (onePairSize / 2) - 1;
				// std::cout << "last: " << i << std::endl;
			}
			while(this->_jacobsthalNumber[jacobIdex - 1] < i + 1)
			{
				// std::cout << "while inner" << std::endl;
				if (i == 0)
					binarySort(0, i + insertedCnt, i, onePairSize, elementCount, pendingChainVector);
				else
					binarySort(0, i + insertedCnt - 1, i, onePairSize, elementCount, pendingChainVector);
				insertedCnt++;
				// std::cout << std::endl << i << " sort -------------: " << std::endl;
				// for (size_t i = 0; i < this->_mainChainVector.size(); i++)
				// 	std::cout << this->_mainChainVector[i] << " ";
				// std::cout << std::endl << std::endl;
				i--;
			}
			i = this->_jacobsthalNumber[jacobIdex] - 1;
		}
		jacobIdex++;
	}
	// std::cout << std::endl << std::endl;
}

void PmergeMe::sortVector()
{
	int before = 0;
	int After = 0;
	before = clock();
	mergeInsertSort(this->_elementCount, 1, 2);
	After = clock();
	this->_VectorTime = After - before;
}

void PmergeMe::printResult()
{
	std::cout << "Before: ";
	printVector(this->_myVector);
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
