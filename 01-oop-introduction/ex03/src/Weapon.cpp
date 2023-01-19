#include <Weapon.hpp>

Weapon::Weapon() {};
Weapon::Weapon(const std::string name) { setType(name); }
Weapon::~Weapon()
{
	// std::cout << "Goodbye!" << " (c)" << this->m_type << std::endl;
}

void Weapon::setType(std::string value) { this->m_type = value; }
std::string Weapon::getType(void) { return (this->m_type); }

