#include "Zombie.hpp"

int main(void)
{

	int			n;
	Zombie* 	horde;
	std::string name;

	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter amount of zombies: ";
	std::cin >> n;
	horde = zombieHorde(n, name);

	for (int i = 0; i < n; i++)
		horde[i].announce();

	delete [] horde;

	return (0);
}