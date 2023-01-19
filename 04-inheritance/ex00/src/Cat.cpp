#include <Cat.hpp>

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat] Only type constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy.getType())
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	setType(copy.getType());
	return (*this);
}
Cat::~Cat() { std::cout << "[Cat] Destructor called" << std::endl; }

void Cat::makeSound() const
{
	std::cout << "[Cat] Meeeoooooowwww..." << std::endl;
}
