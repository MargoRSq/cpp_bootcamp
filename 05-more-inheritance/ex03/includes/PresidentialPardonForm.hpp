#pragma once

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
	~PresidentialPardonForm();

	virtual bool execute(Bureaucrat const &executor) const;
};
