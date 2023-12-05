#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin();
        iterator end();
        //rbegin
        //rend

        //cbegin
        //cend
        //crbegin
        //crend
};

#include "MutantStack.tpp"
#endif