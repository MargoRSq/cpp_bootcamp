#include <iostream>
#include <vector>
#include "Span.hpp"

int main(void) {
	{
		std::cout << "--- 10 000 elem " << std::endl;
		unsigned int size = 10000;
		Span A(size);

		for (unsigned int i = 0; i <= size; i++) {
			try {
				A.addNumber(rand());
			}
			catch(const std::exception& e) {
				std::cerr << ">> Exception caught: " << e.what() << '\n';
			}
		}

		std::cout << "--- Shortest span " << std::endl;
		try {
			int span = A.shortestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}

		std::cout << "--- Longest span " << std::endl;
		try {
			int span = A.longestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
	}
	{
		std::cout << "--- 10 elem " << std::endl;
		unsigned int size = 10;
		Span A(size);

		for (unsigned int i = 0; i < size; i++) {
			try {
				A.addNumber(rand());
			}
			catch(const std::exception& e) {
				std::cerr << ">> Exception caught: " << e.what() << '\n';
			}
		}
		std::cout << "--- Shortest span " << std::endl;
		try {
			int span = A.shortestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}

		std::cout << "--- Longest span " << std::endl;
		try {
			int span = A.longestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
	}
	{
		std::cout << "--- Test from the Subject " << std::endl;
		Span sp = Span(5);

		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		sp.addNumber(7);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "--- Test addRange() " << std::endl;
		Span				sp = Span(5);
		std::vector<int>	vals;

		std::cout << "--- Add empty range " << std::endl;
		try {
			sp.addRange(vals.begin(), vals.end());
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
		std::cout << sp << std::endl;

		for (size_t i = 0; i < 5; i++) {
			vals.push_back(i * 10);
		}
		std::cout << "--- Add range of 5 " << std::endl;
		try {
			sp.addRange(vals.begin(), vals.end());
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
		std::cout << sp << std::endl;

		for (size_t i = 5; i > 0; i--) {
			vals.push_back(i * -10);
		}
		std::cout << "--- Add range of 10 " << std::endl;
		try {
			sp.addRange(vals.begin(), vals.end());
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
		std::cout << sp << std::endl;
	}
	return 0;
}