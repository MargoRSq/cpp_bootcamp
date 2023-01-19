#include <Zombie.hpp>

Zombie::Zombie() {};
Zombie::~Zombie()
{
	std::cout << "Goodbye!" << " (c)" << this->m_name << std::endl;
}
Zombie::Zombie(const std::string name)
{
	setName(name);
}

void Zombie::setName(std::string value)
{
	this->m_name = value;
}
std::string Zombie::getName(void)
{
	return (this->m_name);
}

void Zombie::announce(void)
{
	std::cout << this->m_name << std::endl;
};
