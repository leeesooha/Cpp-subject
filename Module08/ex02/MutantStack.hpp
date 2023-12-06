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
        const iterator begin() const;
        const iterator end() const;

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator ReverseIterator;
        ReverseIterator rbegin();
        ReverseIterator rend();
        const reverse_iterator rbegin() const;
        const reverse_iterator rend() const;
};

#include "MutantStack.tpp"
#endif