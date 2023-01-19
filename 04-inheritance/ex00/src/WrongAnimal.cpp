#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal(const std::string& type) : m_type(type)
{
	std::cout << "[WrongAnimal] Only type constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : m_type(copy.getType())
{
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
	this->m_type = copy.getType();
	return (*this);
}
WrongAnimal::~WrongAnimal() { std::cout << "[WrongAnimal] Destructor called" << std::endl; }

void WrongAnimal::setType(const std::string& value) { this->m_type = value; }
std::string WrongAnimal::getType(void) const { return this->m_type; }

void WrongAnimal::makeSound() const
{
	// std::cout << "WrongAnimal makes some Weird sound" << std::endl;
}
