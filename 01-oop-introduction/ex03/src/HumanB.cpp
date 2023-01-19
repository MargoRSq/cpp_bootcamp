#include <HumanB.hpp>

HumanB::HumanB(const std::string &name) : m_name(name) { this->m_w = NULL; }
HumanB::HumanB(const std::string &name, Weapon &w) : m_name(name), m_w(&w) {}
HumanB::~HumanB()
{
	// std::cout << "Goodbye!" << " (c)" << this->m_name << std::endl;
}

void HumanB::setName(std::string value) { this->m_name = value; }
void HumanB::setWeapon(Weapon &w) { this->m_w = &w; };

std::string HumanB::getName(void) { return (this->m_name); }

void HumanB::attack(void)
{
    if (this->m_w)
        std::cout << this->m_name << " attacks with their " << m_w->getType() << std::endl;
    else
        std::cout << "No weapon" << std::endl;
}
