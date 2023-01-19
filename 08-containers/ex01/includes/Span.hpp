#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

typedef std::vector<int>::const_iterator v_cit;
typedef std::vector<int>::iterator v_it;

class Span {
public:
	Span(const unsigned int& max);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	void setSize(const unsigned int& value);
	unsigned int getSize(void) const;
	std::vector<int> getArr(void) const;

	void addNumber(int value);
	void addRange(v_it a, v_it z);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

	v_it begin(void);
	v_it end(void);

private:
	unsigned int 	 m_size;
	std::vector<int> m_arr;
};

std::ostream& operator<<(std::ostream &out, Span &inst);
