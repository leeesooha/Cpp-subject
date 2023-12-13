#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>

class PmergeMe
{
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe& other);
        virtual ~PmergeMe();
};

#endif