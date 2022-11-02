#include <ClapTrap.hpp>

ClapTrap::ClapTrap()
	: m_name(""), m_hp(10), m_ep(10), m_dmg(0)
{
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
	: m_name(name), m_hp(10), m_ep(10), m_dmg(0)
{
	std::cout << "[ClapTrap] Only name constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name, int hp, int ep, int dmg)
	: m_name(name), m_hp(hp), m_ep(ep), m_dmg(dmg)
{
	std::cout << "[ClapTrap] All parametres constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy)
	: m_name(copy.getName()), m_hp(copy.getHP()),
	  m_ep(copy.getEP()), m_dmg(copy.getDMG())
{
	std::cout << "[ClapTrap] Copy constructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;
	this->m_name = copy.getName();
	this->m_hp = copy.getHP();
	this->m_ep = copy.getEP();
	this->m_dmg = copy.getDMG();
	return (*this);
}
ClapTrap::~ClapTrap() { std::cout << "[ClapTrap] Destructor called" << std::endl; }

void ClapTrap::setName(const std::string& value) { this->m_name = value; }
void ClapTrap::setHP(int value) { this->m_hp = value; }
void ClapTrap::setEP(int value) { this->m_ep = value; }
void ClapTrap::setDMG(int value) { this->m_dmg = value; }
std::string ClapTrap::getName(void) const { return this->m_name; }
int ClapTrap::getHP(void) const { return this->m_hp; }
int ClapTrap::getEP(void) const { return this->m_ep; }
int ClapTrap::getDMG(void) const { return this->m_dmg; }

void ClapTrap::attack(const std::string& target)
{
	if (this->m_dmg && this->m_ep && this->m_hp)
		std::cout << "Trap " << this->m_name << " attacks " << target <<
		" causing " << this->m_dmg << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hp > (int)amount && this->m_hp > 0)
		std::cout << "Trap " << this->m_name << " takes " 
		<< amount << " damage" << std::endl;
	{
		this->m_hp -= amount;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "Trap " << this->m_name << " repairs " 
	<< amount << " of health points" << std::endl;
	this->m_hp += amount;
}
