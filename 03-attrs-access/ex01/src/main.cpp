#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap st("Kek");
	ClapTrap* ptr;
	ScavTrap* heap_ptr = new ScavTrap("Mda");

	ptr = &st;
	ptr->attack("sada");
	st.attack("Lol");
	heap_ptr->guardGate();

	delete heap_ptr;
	return 0;
}