#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	{
		std::cout << "--- TEST 1: Form can't be created " << std::endl;
		try
		{
			Bureaucrat	bill("Bill", 100);
			Bureaucrat	paul("Paul", 50);
			Form		argeement1("Agreement 1", 100, 110);
			Form		argeement2("Agreement 2", 0, 0);

			std::cout << bill << std::endl;
			std::cout << paul << std::endl;
			std::cout << argeement1 << std::endl;
			std::cout << argeement2 << std::endl;

			std::cout << std::endl << "- Bill recieved Agreement 1:" << std::endl;
			bill.signForm(argeement1);
			std::cout << std::endl << "- Paul recieved Agreement 1:" << std::endl;
			paul.signForm(argeement1);
			std::cout << std::endl << "- Bill recieved Agreement 2:" << std::endl;
			bill.signForm(argeement2);
		}
		catch(const std::exception& e)
		{
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		std::cout << "--- TEST 2: Form can't be signed " << std::endl;
		try
		{
			Bureaucrat	bill("Bill", 100);
			Bureaucrat	paul("Paul", 50);
			Form		argeement2("Agreement 2", 50, 100);
			Form		argeement3("Agreement 3", 1, 50);

			std::cout << bill << std::endl;
			std::cout << paul << std::endl;
			std::cout << argeement2 << std::endl;
			std::cout << argeement3 << std::endl;

			std::cout << std::endl << "- Paul recieved Agreement 2:" << std::endl;
			paul.signForm(argeement2);
			std::cout << std::endl << "- Paul recieved Agreement 3:" << std::endl;
			paul.signForm(argeement3);
		}
		catch(const std::exception& e)
		{
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	return 0;
}