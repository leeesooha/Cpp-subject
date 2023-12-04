#include "Span.hpp"

Span::Span() : _max(0)
{
    this->_vector.reserve(0);
}

Span::Span(unsigned int N) : _max(N)
{
    this->_vector.reserve(N);
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_max = other._max;
    }
    return (*this);
}

Span::~Span()
{
}

const char* Span::FullError::what() const throw()
{
	return ("It's already full.");
}

const char* Span::TooSmall::what() const throw()
{
	return ("There is less than 1 element");
}

void Span::addNumber(int element)
{
    if (this->_vector.size() == this->_max)
    {
        throw Span::FullError();
        return ;
    }
    this->_vector.push_back(element);
}

unsigned int Span::shortestSpan() const
{
    if (this->_vector.size() <= 1)
    {
        throw Span::TooSmall();
        return 0;
    }
    std::vector<int> tempVector;
    tempVector = this->_vector;
    std::sort(tempVector.begin(), tempVector.end());
    std::vector<int>::iterator tempIterator = tempVector.begin();
    unsigned int num = INT_MAX;

    while (tempIterator != tempVector.end() - 1)
    {
        if (num > static_cast<unsigned int>(abs(*tempIterator - *(tempIterator + 1))))
            num = static_cast<unsigned int>(abs(*tempIterator - *(tempIterator + 1)));
        tempIterator++;
    }
    return (num);
}
unsigned int Span::longestSpan() const
{
    if (this->_vector.size() <= 1)
        throw std::out_of_range("There is less than 1 element");
    std::vector<int> tempVector;

    tempVector = this->_vector;
    std::sort(tempVector.begin(), tempVector.end());
    return (static_cast<unsigned int>(std::abs(*(tempVector.end() - 1) - *tempVector.begin())));
}

void Span::addNumbers(const std::vector<int> newVector)
{
    if (this->_vector.size() + newVector.size() <= this->_max)
    {
        std::vector<int>::iterator iterEnd = this->_vector.end();
        this->_vector.insert(iterEnd, newVector.begin(), newVector.end());
    }
    else
        throw Span::FullError();
}