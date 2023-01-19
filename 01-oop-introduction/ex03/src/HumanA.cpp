#include <HumanA.hpp>

HumanA::HumanA(const std::string &name, Weapon &w) 
        : m_name(name), m_w(w) {}
HumanA::~HumanA()
{
	// std::cout << "Goodbye!" << " (c)" << this->m_name << std::endl;
}

void HumanA::setName(std::string value) { this->m_name = value; }
void HumanA::setWeapon(Weapon &w) { this->m_w = w; };

std::string HumanA::getName(void) { return (this->m_name); }

void HumanA::attack(void)
{
    std::cout << this->m_name << " attacks with their " << m_w.getType() << std::endl;
}
