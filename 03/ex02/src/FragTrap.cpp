#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap("", 100, 50, 20)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 50 ,20)
{
	std::cout << "FragTrap Only name constructor called" << std::endl;
}
FragTrap::FragTrap(std::string& name, int hp, int ep, int dmg)
	: ClapTrap(name, hp, ep, dmg)
{
	std::cout << "All parametres constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	setName(copy.getName());
	setHP(copy.getHP());
	setEP(copy.getEP());
	setDMG(copy.getDMG());
	return (*this);
}
FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called" << std::endl; }

void FragTrap::highFivesGuys(void)
{
	std::cout<<"FragTrap "<< this->getName() 
		<< " says, \"High five, bro!\"" << std::endl;
}
