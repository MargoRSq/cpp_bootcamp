#include <WrongCat.hpp>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat] Only type constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy.getType())
{
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
	setType(copy.getType());
	return (*this);
}
WrongCat::~WrongCat() { std::cout << "[WrongCat] Destructor called" << std::endl; }

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Weird meeeoooooowwww..." << std::endl;
}
