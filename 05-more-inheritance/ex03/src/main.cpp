#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void) {
	{
		std::cout << "--- ShrubberyCreationForm Test " << std::endl;
		Bureaucrat	boss("The Boss", 1);
		Bureaucrat	paul("Paul", 150);
		Intern		noname;

		AForm*		park = noname.makeForm("shrubbery creation", "Park");
		std::cout << std::endl << boss << std::endl;
		std::cout << std::endl << paul << std::endl;
		std::cout << std::endl << *park << std::endl;
		
		try {
			std::cout << std::endl << "- The Boss recieved Agreement:" << std::endl;
			boss.signForm(park);
			std::cout << std::endl << "- Paul to execute Agreement:" << std::endl;
			paul.executeForm(park);
		}
		catch(const Bureaucrat::DocDoesntExist& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
			try {
				std::cout << std::endl << "- Boss to execute Agreement:" << std::endl;
				boss.executeForm(park);
			}
			catch(const std::exception& e) {
				std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
			}
			
		}
		delete park;
	}
	{
		std::cout << "--- RobotomyRequestForm " << std::endl;
		Bureaucrat				bill("Bill", 5);
		Intern		noname;
		AForm*		roboCat = noname.makeForm("robotomy request", "RoboCat");
		try
		{
			std::cout << bill << std::endl;
			std::cout << *roboCat << std::endl;

			std::cout << std::endl << "- Bill recieved RoboCat form:" << std::endl;
			bill.signForm(roboCat);
			for (size_t i = 0; i < 4; i++)
			{
				std::cout << std::endl << "- Bill to execute :: " << i << std::endl;
				bill.executeForm(roboCat);
			}
		}
		catch(const Bureaucrat::DocDoesntExist& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		delete roboCat;
	}
	{
		std::cout << "--- PresidentialPardonForm " << std::endl;
		Bureaucrat					bill("Bill", 5);
		Intern		noname;
		AForm*		form = noname.makeForm("presidential pardon", "Guilty 100500");
		try {
			std::cout << bill << std::endl;
			std::cout << *form << std::endl;

			std::cout << std::endl << "- Bill recieved form:" << form->getName() << std::endl;
			bill.signForm(form);
			std::cout << std::endl << "- Bill to execute" << std::endl;
			bill.executeForm(form);
		}
		catch(const Bureaucrat::DocDoesntExist& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		delete form;
	}
	{
		std::cout << "--- No Such Name Form " << std::endl;
		Bureaucrat					bill("Bill", 5);
		Intern		noname;
		AForm*		form = noname.makeForm("No Such Name Form", "No Such Name Form");
		try {
			bill.signForm(form);
		}
		catch(const Bureaucrat::DocDoesntExist& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		catch(const std::exception& e) {
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
		delete form;
	}
	return 0;
}