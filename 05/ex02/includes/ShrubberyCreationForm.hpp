#pragma once

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
	~ShrubberyCreationForm();

	virtual bool execute(Bureaucrat const &executor) const;
};
