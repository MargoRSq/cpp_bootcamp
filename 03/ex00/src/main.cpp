#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap cl;

	cl.attack("Lol");
	cl.takeDamage(2);
	cl.beRepaired(3);

	std::cout << cl.getHP() << std::endl;
	ClapTrap copy = cl;
	ClapTrap copy2(cl);

	std::cout << copy.getHP() << std::endl;
	std::cout << copy2.getHP() << std::endl;
	return 0;
}