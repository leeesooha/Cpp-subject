#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>

class Span
{
	public :
		Span(unsigned int N);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();
		void addNumber(int element);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
        void addNumbers(std::vector<int> newVector);
        size_t size();
		class FullError : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
		class TooSmall : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
	private :
		Span();
		unsigned int _max;
		std::vector<int> _vector;
};

#endif
