#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
		: AForm("ShrubberyCreationForm", "void", 137, 145)
{
	std::cout << "[ShrubberyCreationForm] DEFAULT constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
		: AForm("ShrubberyCreationForm", target, 137, 145)
{
	std::cout << "[ShrubberyCreationForm] constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
		: AForm(copy.AForm::getName(), copy.AForm::getTarget(), 137, 145)
{
	std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	AForm::operator=(copy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
	if (!this->AForm::isSigned())
	{
		std::cout << this->AForm::getName()
                  << " form is not signed!" << std::endl;
		return false;
	}
	else if (this->AForm::getExecuteGrade() < executor.getGrade())
	{
        std::cout << this->AForm::getName() << " form can not be executed by "
                  << executor.getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::string		filename(this->getTarget() + "_target");
	std::ofstream	ofs(filename);
	if (!ofs.is_open())
	{
		std::cout << this->AForm::getTarget()
				  << " creation is failed!" << std::endl;
		return false;
	}
	ofs << " 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 🥦 ";
	ofs.close();
	std::cout << this->AForm::getTarget()
				<< " is successfully created!" << std::endl;
	return true;
}