#include <Form.hpp>

Form::Form() : m_name("DefaultForm"), 
    m_signed(false), m_signGrade(50), m_executeGrade(150)
{
	std::cout << "[Form] Default constructor called" << std::endl;
}
Form::Form(std::string const &name, int toSign, int toExecute) 
	: m_name(name), m_signGrade(toSign), m_executeGrade(toExecute)
{
	std::cout << "[Form] Name and grades constructor called" << std::endl;
    if (toSign < 1 || toExecute < 1)
		throw Form::GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form &copy) : m_name(copy.getName()), m_signed(copy.isSigned()),
        m_signGrade(copy.getSignGrade()), m_executeGrade(copy.getExecuteGrade())
{
	std::cout << "[Form] Copy constructor called" << std::endl;
}
Form &Form::operator=(const Form &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Form] Copy assignment operator called" << std::endl;
    this->m_signed = copy.isSigned();
	const_cast<std::string &>(m_name) = copy.getName();
	const_cast<int &>(m_signGrade) = copy.getSignGrade();
	const_cast<int &>(m_executeGrade) = copy.getExecuteGrade();
	return (*this);
}
Form::~Form() { std::cout << "[Form] Destructor called" << std::endl; }

std::string Form::getName(void) const { return this->m_name; }
const int& Form::getSignGrade(void) const { return this->m_signGrade; }
const int& Form::getExecuteGrade(void) const { return this->m_executeGrade; }

bool Form::isSigned(void) const { return this->m_signed; }

bool Form::beSigned(Bureaucrat const &bur)
{
	if (this->isSigned())
		std::cout << "FORM: Bureaucrat " << bur.getName()
                  << " could not sign the form " << this->getName()
                  << " because it's already signed" << std::endl;
	else if (this->m_signGrade < bur.getGrade())
    {
		std::cout << "FORM: Bureaucrat " << bur.getName()
                  << " could not sign the form " << this->getName()
                  << " because his grade is too low" << std::endl;
		throw Form::GradeTooLowException();
    }
	else
    {
		this->m_signed = true;
		std::cout << "FORM: Bureaucrat " << bur.getName()
                  << " signed the form " << this->getName() << std::endl;
		return true;
	}
	return false;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("The grade is too high for the form!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("The grade is too low for the form!");
}

std::ostream & operator<<(std::ostream &op, Form const &copy)
{
	op	<< "Document name: " << copy.getName()
		<< (copy.isSigned() ? ", is signed, " : ", is not signed, ")
		<< "can be signed starting from " << copy.getSignGrade() << "th grade,"
		<< "can be executed starting from " << copy.getExecuteGrade() << "th grade";
	return op;
}