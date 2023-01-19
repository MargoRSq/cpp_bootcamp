#pragma once


template<typename T>
void print(const T& val) { std::cout << val << " "; }


template<typename T>
void iter(const T* arr, unsigned int& len, void (*foo)(const T&))
{
	unsigned int i = -1;

	while (++i < len)
		foo(arr[i]);
}
