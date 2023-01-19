#pragma once

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;

class Intern {
public:
	Intern();
	Intern(Intern const & copy);
	Intern & operator=(Intern const & copy);
	~Intern();

	AForm *makeForm(const std::string & name, const std::string & target);
};

std::ostream & operator<<(std::ostream & o, Intern const & rhs);