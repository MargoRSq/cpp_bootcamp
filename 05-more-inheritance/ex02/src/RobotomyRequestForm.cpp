#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
		: AForm("RobotomyRequestForm", "void", 72, 45)
{
	std::cout << "[RobotomyRequestForm] DEFAULT constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
		: AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "[RobotomyRequestForm] constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
		: AForm(copy.AForm::getName(), copy.AForm::getTarget(), 72, 45)
{
	std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	AForm::operator=(copy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const 
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
	std::cout << "** DZZZZZZ VZZZZZZ DRRRRRRRRRRRR**" << std::endl;
	if (rand() % 2)
	{
		std::cout << "FAILURE! "<< this->AForm::getTarget()
				<< " robotomization failed.!" << std::endl;
		return false;
	}
	std::cout << "SUCCESS! "<< this->AForm::getTarget()
			<< " has been robotomized successfully!" << std::endl;
	return true;
}