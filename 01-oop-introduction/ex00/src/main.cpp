#include "Zombie.hpp"

int main(void)
{
	Zombie* zheap = newZombie("Lucia");
	Zombie	z = Zombie("Sanya");

	z.announce();
	zheap->announce();

	delete zheap;
	return (0);
}