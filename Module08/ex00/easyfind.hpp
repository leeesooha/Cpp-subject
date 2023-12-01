#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int target)
{
	typename T::iterator accessContainer;

	accessContainer = std::find(container.begin(), container.end(), target);
	if (accessContainer == container.end())
		throw std::out_of_range("not found value!");
	else
		return (accessContainer);
}

#endif