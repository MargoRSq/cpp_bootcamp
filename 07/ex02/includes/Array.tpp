#include "Array.hpp"

template<typename T>
Array<T>::Array(): m_size(0), m_arr(NULL)
{
	std::cout << "Array default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int size): m_size(size), m_arr(new T[size])
{
	std::cout << "Array constructor called" << std::endl;
}

template<typename T>
Array<T>::Array (Array<T> const & copy): m_size(copy.size()), m_arr(new T[copy.size()])
{
	unsigned int	i = 0;

	while (i < this->m_size) {
		this->m_arr[i] = copy.m_arr[i];
		i++;
	}
	std::cout << "Array copy constructor called" << std::endl;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & copy)
{
	unsigned int	i = 0;

	if (this->m_size)
		delete [] this->m_arr;
	this->m_size = copy.size();
	this->m_arr = new T[this->m_size];
	while (i < this->m_size) {
		this->m_arr[i] = copy.m_arr[i];
		i++;
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] this->m_arr;
	std::cout << "Array destructor called" << std::endl;
}

template<typename T>
T & Array<T>::operator[](const unsigned int index) const {
	if (index >= this->m_size)
		throw std::overflow_error("Index out of bounds");
	return this->m_arr[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return (this->m_size);
}