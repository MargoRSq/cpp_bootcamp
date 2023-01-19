#pragma once

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

template <typename T>
typename T::const_iterator easyfind(T &arr, int n)
{
	typename T::const_iterator iter = find(arr.begin(), arr.end(), n);
	if (arr.begin() == arr.end())
		throw std::overflow_error("Array is empty");
	else if (iter == arr.end())
		throw std::overflow_error("Value not found");
	else
		return iter;
}
