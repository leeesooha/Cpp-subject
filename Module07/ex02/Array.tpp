#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _arraySize(0)
{
    this->_arrayPtr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->_arrayPtr = new T[n];
    this->_arraySize = static_cast<size_t>(n);
}

template <typename T>
Array<T>::Array(const Array &other) : _arraySize(0)
{
    this->_arrayPtr = new T[0];
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->_arrayPtr;
        this->_arrayPtr = new T[other.getArraySize()];
        for (size_t i = 0; i < other.getArraySize(); i++)
            this->_arrayPtr[i] = other._arrayPtr[i];
        this->_arraySize = other.getArraySize();
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](const long &idex)
{
    if (idex < 0 || this->_arraySize <= static_cast<size_t>(idex))
        throw std::exception();
    return (this->_arrayPtr[idex]);
}

template <typename T>
const T &Array<T>::operator[](const long &idex) const
{
    if (idex < 0 || this->_arraySize <= static_cast<size_t>(idex))
        throw std::exception();
    return (this->_arrayPtr[idex]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_arrayPtr;
}

template <typename T>
size_t Array<T>::getArraySize() const
{
    return(this->_arraySize);
}

#endif