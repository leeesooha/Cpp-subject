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
        typedef typename MutantStack<T>::stack::container_type::const_iterator ConstIterator;
        ConstIterator begin() const;
        ConstIterator end() const;

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator ReverseIterator;
        ReverseIterator rbegin();
        ReverseIterator rend();
        typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator ConstReverseIterator;
        ConstReverseIterator rbegin() const;
        ConstReverseIterator rend() const;

        ConstIterator cbegin() const;
        ConstIterator cend() const;
    
        ConstReverseIterator crbegin() const;
        ConstReverseIterator crend() const;
};

#include "MutantStack.tpp"
#endif