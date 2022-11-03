#pragma once

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
	~RobotomyRequestForm();

	virtual bool execute(Bureaucrat const &executor) const;
};
