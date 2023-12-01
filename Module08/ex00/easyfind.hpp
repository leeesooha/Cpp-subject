#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
T& easyfind(T &container, int target) const
{
	T* ptr;

	ptr = std::find(container.begein(), container.last(), target);
	if (ptr == container.last())
		throw std::out_of_range("not found value!");
	else
		return (ptr);
}

#endif