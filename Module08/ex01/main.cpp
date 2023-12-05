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
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(-17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(17);
        // sp.addNumber(2142483647);
        // sp.addNumber(-2147483648);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
    std::cout << "shorestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "size: " << sp.size() << std::endl << std::endl;


    std::vector<int> vec;
    Span sp2(1000000);
    try {
        for(int i = 0; i < 100000; i++)
            vec.push_back(i);
        sp2.addNumbers(vec);
        sp2.addNumber(2147483647);
        sp2.addNumber(-2147483648);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
    std::cout << "shorestSpan: " << sp2.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp2.longestSpan() << std::endl;
    std::cout << "size: " << sp2.size() << std::endl;
    return 0; 
}