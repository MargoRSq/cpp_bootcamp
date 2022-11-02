#include <Animal.hpp>

Animal::Animal(const std::string& type) : m_type(type)
{
	std::cout << "[Animal] Only type constructor called" << std::endl;
}
Animal::Animal(const Animal &copy) : m_type(copy.getType())
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	this->m_type = copy.getType();
	return (*this);
}
Animal::~Animal() { std::cout << "[Animal] Destructor called" << std::endl; }

void Animal::setType(const std::string& value) { this->m_type = value; }
std::string Animal::getType(void) const { return this->m_type; }

void Animal::makeSound() const
{
	std::cout << "Animal makes some wierd sound" << std::endl;
}
