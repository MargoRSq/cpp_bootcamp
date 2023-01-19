#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
	std::cout << "[ScavTrap]  Default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50 ,20)
{
	std::cout << "[ScavTrap]  Only name constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string& name, int hp, int ep, int dmg)
	: ClapTrap(name, hp, ep, dmg)
{
	std::cout << "All parametres constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "[ScavTrap]  Copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[ScavTrap]  Copy assignment operator called" << std::endl;
	setName(copy.getName());
	setHP(copy.getHP());
	setEP(copy.getEP());
	setDMG(copy.getDMG());
	return (*this);
}
ScavTrap::~ScavTrap() { std::cout << "[ScavTrap]  Destructor called" << std::endl; }

void ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap]  " 
		<< this->getName() << " is now in Gate keeper mode" << std::endl;
}
