#pragma once

#include <iostream>
#include <iomanip>
#include <list>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack<T>() {}
	MutantStack<T>(MutantStack<T> const & copy): std::stack<T>(copy) {}
	MutantStack<T> & operator=(MutantStack<T> const & copy)
	{
		std::stack<T>::operator=(copy);
		return *this;
	}
	~MutantStack<T>() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return std::stack<int>::c.begin(); }
	iterator end() { return std::stack<int>::c.end(); }
};
