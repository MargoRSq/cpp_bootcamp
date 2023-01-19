#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

static AForm	*createPresidentialPardonForm(std::string const &target);
static AForm	*createRobotomyRequestForm(std::string const &target);
static AForm	*createShrubberyCreationForm(std::string const &target);

Intern::Intern()
{
	std::cout << "[Intern] DEFAULT constructor called" << std::endl;
}
Intern::Intern(Intern const &copy)
{
	(void) copy;
	std::cout << "[Intern] Copy constructor called" << std::endl;
}
Intern & Intern::operator=(Intern const &copy)
{
	(void) copy;
	return *this;
}
Intern::~Intern()
{
	std::cout << "[Intern] Destructor called" << std::endl;
}
AForm *Intern::makeForm(const std::string & name, const std::string & target)
{
	AForm *form = NULL;
	typedef AForm *(*_func)(std::string const &target);
	typedef struct {
		std::string name;
		_func func;
	}	FormTypes;

	FormTypes	forms[] = {
		{"presidential pardon", &createPresidentialPardonForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"shrubbery creation", &createShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].name == name)
        {
			form = forms[i].func(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern can`t create the form " << name << std::endl;
	return form;
}

static AForm	*createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

static AForm	*createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static AForm	*createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}