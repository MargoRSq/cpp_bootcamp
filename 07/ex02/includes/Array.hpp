#pragma once

# include <iostream>
#include <iomanip>

template <typename T>
class Array {
private:
	unsigned int		m_size;
	T *					m_arr;
public:
	Array<T>();
	Array<T>(unsigned int size);
	Array<T>(Array<T> const & src);
	Array<T> & operator=(Array<T> const & rhs);
	~Array<T>();

	T & operator[](const unsigned int index) const;
	unsigned int size() const;
};