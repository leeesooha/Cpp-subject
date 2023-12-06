#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
    *this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::stack::container_type::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::stack::container_type::iterator MutantStack<T>::end()
{
    return (this->c.end());
}
template <typename T>
typename MutantStack<T>::stack::container_type::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::stack::container_type::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::stack::container_type::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}
template <typename T>
typename MutantStack<T>::stack::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::stack::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_iterator MutantStack<T>::cbegin() const
{
    return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_iterator MutantStack<T>::cend() const
{
    return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_reverse_iterator MutantStack<T>::crend() const
{
    return (this->c.crend());
}

#endif