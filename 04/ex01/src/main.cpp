#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap st("Kek");
	ClapTrap* ptr;

	ptr = &st;
	// ptr = new ScavTrap(st);
	// std::cout << "delete ptr" << std::endl;
	// // delete ptr;
    // std::cout << "after delete ptr" << std::endl;
	// st.guardGate();virtual 
	ptr->attack("sada");
	st.attack("Lol");

	return 0;
}