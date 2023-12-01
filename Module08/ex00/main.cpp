#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    std::vector<int> numbers(10, 8);
    try {
        std::cout << *easyfind(numbers, 8) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << numbers.size() << std::endl;

    std::list<int> myList;
    for (size_t i = 0; i < 10; i++)
        myList.push_back(i);
    try {
        std::cout << *easyfind(myList, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::deque<int> myDeque;
    for (size_t i = 0; i < 10; i++)
        myDeque.push_back(i);
    try {
        std::cout << *easyfind(myDeque, 100) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}