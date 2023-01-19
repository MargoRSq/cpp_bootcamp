#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : m_name("DefaultBureaucrat"), m_grade(150)
{
	std::cout << "[Bureaucrat] Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string const &name, int grade) 
	: m_name(name), m_grade(grade)
{
	std::cout << "[Bureaucrat] Name and grade constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: m_name(copy.getName()), m_grade(copy.getGrade())
{
	std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
	const_cast<std::string &>(m_name) = copy.getName();
	this->m_grade = (copy.getGrade());
	return (*this);
}
Bureaucrat::~Bureaucrat() { std::cout << "[Bureaucrat] Destructor called" << std::endl; }

std::string Bureaucrat::getName(void) const { return this->m_name; }
int Bureaucrat::getGrade(void) const { return this->m_grade; }

void Bureaucrat::incrementGrade(int points)
{
	if ((this->m_grade - points) < 1)
		throw Bureaucrat::GradeTooHighException();
	if ((this->m_grade - points) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade -= points;
	std::cout << "Bureaucrat " << this->m_name << " got promoted to " 
			  << this->m_grade << "th grade." << std::endl;
}
void Bureaucrat::decrementGrade(int points)
{
	if ((this->m_grade + points) < 1)
		throw Bureaucrat::GradeTooHighException();
	if ((this->m_grade + points) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade += points;
	std::cout << "Bureaucrat " << this->m_name << " got downgraded to " 
			  << this->m_grade << "th grade." << std::endl;

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low!");
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const &copy) {
	o << copy.getName() << ", bureaucrat grade " << copy.getGrade();
	return o;
}