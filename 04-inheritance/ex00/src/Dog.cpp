#include <Dog.hpp>

Dog::Dog() : Animal("Dog")
{
	std::cout << "[Dog] Only type constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy.getType())
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	setType(copy.getType());
	return (*this);
}
Dog::~Dog() { std::cout << "[Dog] Destructor called" << std::endl; }

void Dog::makeSound() const
{
	std::cout << "[Dog] Bark bark bark..." << std::endl;
}
