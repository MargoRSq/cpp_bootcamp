#include <iostream>
#include "easyfind.hpp"

int main( void )
{
	{
		std::cout << "--- Create the array" << std::endl;
		std::vector<int>					a;
		std::vector<int>::const_iterator	ptr;

		try {
			ptr = easyfind(a, 21);
			std::cout << *ptr << " is found" << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
		std::cout << "--- Fill the array" << std::endl;
		for (size_t i = 0; i < 22; i++) {
			a.push_back(i);
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "--- Find 21" << std::endl;
		try {
			ptr = easyfind(a, 21);
			std::cout << *ptr << " is found" << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}

		std::cout << "--- Find -42" << std::endl;
		try {
			ptr = easyfind(a, -42);
			std::cout << *ptr << " is found" << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
	}
}