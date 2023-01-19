#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

int main(void) {
	{
		std::cout << "--- TEST 1: grade 200" << std::endl;
		try {
			Bureaucrat	bill("Bill", 200);
		}
		catch(const std::exception& e) {
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		std::cout << "--- TEST 2: increment by 140 " << std::endl;
		Bureaucrat	bill("Bill", 100);
		Bureaucrat	paul("Paul", 100);

		std::cout << bill << std::endl;
		std::cout << paul << std::endl;
		try {
			bill.decrementGrade(30);
			paul.incrementGrade(40);
			bill.incrementGrade(140);
		}
		catch(const std::exception& e) {
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		std::cout << "--- TEST 2: decrement -30 " << std::endl;
		Bureaucrat	bill("Bill", 10);
		Bureaucrat  paul = bill;

		std::cout << bill << std::endl;
		try {
			paul.incrementGrade(5);
			bill.decrementGrade(-30);
		}
		catch(const std::exception& e) {
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	return 0;
}