#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
		: AForm("PresidentialPardonForm", "void", 25, 5)
{
	std::cout << "[PresidentialPardonForm] DEFAULT constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
		: AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "[PresidentialPardonForm] constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
		: AForm(copy.AForm::getName(), copy.AForm::getTarget(), 25, 5)
{
	std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	AForm::operator=(copy);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const 
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
	std::cout << this->AForm::getTarget()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return true;
}