#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
	ScavTrap st("Kek");
	FragTrap ft("lul");
	ClapTrap* ptr;

	ptr = &st;
	// ptr = new ScavTrap(st);
	// std::cout << "delete ptr" << std::endl;
	// // delete ptr;
    // std::cout << "after delete ptr" << std::endl;
	// st.guardGate();virtual 
	ptr->attack("sada");
	st.attack("Lol");

	ft.attack("Kiva");
	return 0;
}