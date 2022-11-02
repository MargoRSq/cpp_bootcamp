#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
	ScavTrap st("Kek");
	FragTrap ft("lul");
	ClapTrap* ptr;

	ptr = &st;
	ptr->attack("sada");
	st.attack("Lol");

	ft.highFivesGuys();

	return 0;
}