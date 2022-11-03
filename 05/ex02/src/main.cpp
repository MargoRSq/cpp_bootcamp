#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main(void) {
	{
		std::cout << "--- ShrubberyCreationForm Test " << std::endl;
		Bureaucrat	boss("The Boss", 1);
		Bureaucrat	paul("Paul", 150);
		ShrubberyCreationForm		park("Park");

		std::cout << boss << std::endl;
		std::cout << paul << std::endl;
		std::cout << park << std::endl;
		
		try {
			std::cout << std::endl << "- The Boss recieved Agreement:" << std::endl;
			boss.signForm(park);
			std::cout << std::endl << "- Paul to execute Agreement:" << std::endl;
			paul.executeForm(park);
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what()  << '\n';
			try {
				std::cout << std::endl << "- Boss to execute Agreement:" << std::endl;
				boss.executeForm(park);
			}
			catch(const std::exception& e) {
				std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
			}
			
		}
	}
	{
		std::cout << "--- RobotomyRequestForm "<< std::endl;
		try
		{
			Bureaucrat				bill("Bill", 5);
			RobotomyRequestForm		roboCat("RoboCat");

			std::cout << bill << std::endl;
			std::cout << roboCat << std::endl;

			std::cout << std::endl << "- Bill recieved RoboCat form:" << std::endl;
			bill.signForm(roboCat);
			for (size_t i = 0; i < 10; i++)
			{
				std::cout << std::endl << "- Bill to execute :: " << i << std::endl;
				bill.executeForm(roboCat);
			}
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		std::cout << "--- PresidentialPardonForm "<< std::endl;
		try {
			Bureaucrat					bill("Bill", 5);
			PresidentialPardonForm		form("Guilty 100500");

			std::cout << bill << std::endl;
			std::cout << form << std::endl;

			std::cout << std::endl << "- Bill recieved form:" << form.getName() << std::endl;
			bill.signForm(form);
			std::cout << std::endl << "- Bill to execute" << std::endl;
			bill.executeForm(form);
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	return 0;
}