#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <deque>

class PmergeMe
{
    private :
        double _VectorTime;
        double _DequeTime;
        int _elementCount;
        std::vector<int> _jacobsthalNumber;
        std::vector<int> _myVector;
        std::vector<int> _beforeMyVector;
        std::vector<int> _mainChainVector;
        std::deque<int> _myDeque;
        std::deque<int> _beforeMyDeque;
        std::deque<int> _mainChainDeque;
        bool charPtrToInt(char **argv);
        bool formatCheck(std::string str);
        void printVector(std::vector<int> vectorVar);
        void printDeque(std::deque<int> DequeVar);
        void errorPrint(std::string message);
        void printResult();
        void initJacobsthalNumber(int n);
        void sortVector();
        void vectorMergeInsertSort(int elementCount, int onePairSize);
        void vectorSwapPairs(int totalPairCnt, int onePairSize, int mainNpendingDiff);
        void vectorDecouplePendingChain(std::vector<int> &pendingChainVector, int totalPairCnt, int onePairSize);
        void vectorJacobMerge(std::vector<int> &pendingChainVector, int onePairSize);
        void vectorBinarySort(int start, int end, int pendPos, int onePairSize, std::vector<int> &pendingChainVector);
        void sortDeque();
        void DequeMergeInsertSort(int elementCount, int onePairSize);
        void DequeSwapPairs(int totalPairCnt, int onePairSize, int mainNpendingDiff);
        void DequeDecouplePendingChain(std::deque<int> &pendingChainDeque, int totalPairCnt, int onePairSize);
        void DequeJacobMerge(std::deque<int> &pendingChainDeque, int onePairSize);
        void DequeBinarySort(int start, int end, int pendPos, int onePairSize, std::deque<int> &pendingChainDeque);
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe& other);
        virtual ~PmergeMe();
        void run(char **argv);
};

#endif


		// a = this->_myVector[i * onePairSize];
		// b = this->_myVector[i * onePairSize + (onePairSize / 2)];
		// if (a < b)
		// 	std::swap(this->_myVector[i * onePairSize], this->_myVector[i * onePairSize + (onePairSize / 2)]);