#include <AForm.hpp>

AForm::AForm(std::string const &name, const std::string &target, int toSign, int toExecute) 
	:  m_signed(false), m_signGrade(toSign), m_executeGrade(toExecute), m_name(name), m_target(target)
{
	std::cout << "[AForm] Name and grades constructor called" << std::endl;
    if (toSign < 1 || toExecute < 1)
		throw AForm::GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &copy) : m_signed(copy.isSigned()), m_signGrade(copy.getSignGrade()),
	m_executeGrade(copy.getExecuteGrade()), m_name(copy.getName())
{
	std::cout << "[AForm] Copy constructor called" << std::endl;
}
AForm &AForm::operator=(const AForm &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[AForm] Copy assignment operator called" << std::endl;
    this->m_signed = copy.isSigned();
	const_cast<std::string &>(m_name) = copy.getName();
	const_cast<std::string &>(m_target) = copy.getTarget();
	const_cast<int &>(m_signGrade) = copy.getSignGrade();
	const_cast<int &>(m_executeGrade) = copy.getExecuteGrade();
	return (*this);
}
AForm::~AForm() { std::cout << "[AForm] Destructor called" << std::endl; }

const std::string& AForm::getName(void) const { return this->m_name; }
const std::string& AForm::getTarget(void) const { return this->m_target; }
const int& AForm::getSignGrade(void) const { return this->m_signGrade; }
const int& AForm::getExecuteGrade(void) const { return this->m_executeGrade; }

void AForm::setSigned(bool flag) { this->m_signed = flag; }

bool AForm::isSigned(void) const { return this->m_signed; }

bool AForm::beSigned(Bureaucrat const &bur)
{
	if (this->isSigned())
		std::cout << "AForm: Bureaucrat " << bur.getName()
                  << " could not sign the AForm " << this->getName()
                  << " because it's already signed" << std::endl;
	else if (this->m_signGrade < bur.getGrade())
    {
		std::cout << "AForm: Bureaucrat " << bur.getName()
                  << " could not sign the AForm " << this->getName()
                  << " because his grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
    }
	else
    {
		this->m_signed = true;
		std::cout << "AForm: Bureaucrat " << bur.getName()
                  << " signed the AForm " << this->getName() << std::endl;
		return true;
	}
	return false;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("The grade is too high for the AForm!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("The grade is too low for the AForm!");
}

std::ostream & operator<<(std::ostream &op, AForm const &copy)
{
	op	<< "Document name: " << copy.getName()
		<< (copy.isSigned() ? ", is signed, " : ", is not signed, ")
		<< "can be signed starting from " << copy.getSignGrade() << "th grade,"
		<< "can be executed starting from " << copy.getExecuteGrade() << "th grade";
	return op;
}