#include <AAnimal.hpp>

AAnimal::AAnimal(const std::string& type) : m_type(type)
{
	std::cout << "[Animal] Only type constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal &copy) : m_type(copy.getType())
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	this->m_type = copy.getType();
	return (*this);
}
AAnimal::~AAnimal() { std::cout << "[Animal] Destructor called" << std::endl; }

void AAnimal::setType(const std::string& value) { this->m_type = value; }
std::string AAnimal::getType(void) const { return this->m_type; }

void AAnimal::makeSound() const
{
	// std::cout << "Animal makes some Weird sound" << std::endl;
}
