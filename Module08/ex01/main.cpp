#include <iostream>
#include "Span.hpp"
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>

void leak_check(void)
{
    system("leaks a.out");
}

int main()
{
    Span sp = Span(10);
    std::vector<int> vec;

    for(int i = 0; i <= 20000; i = i + 10)
    {
        vec.push_back(i);
    }
    Span sp2(10000);
    sp2.addNumbers(vec);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;


    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(-17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(17);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    return 0; 
}