#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

class PmergeMe
{
    private :
        double _VectorTime;
        double _DequeTime;
        int _elementCount;
        std::vector<int> _jacobsthalNumber;
        std::vector<int> _myVector;
        std::vector<int> _sortedMyVector;
        std::deque<int> _myDeque;
        std::vector<int> _sortedMyDeque;
        bool charPtrToInt(char **argv);
        bool formatCheck(std::string str);
        void printVector(std::vector<int> vectorVar);
        void printDeque(std::deque<int> DequeVar);
        void errorPrint(std::string message);
        void printResult();
        void sortVector();
        void sortDeque();
        void initJacobsthalNumber(int num);
        void binarySort(int pending);
        void mergeInsertSort(int totalPairCnt, int depth, int onePairSize);
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