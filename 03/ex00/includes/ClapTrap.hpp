#pragma once

#include <iostream>

class	ClapTrap {
public:
      ClapTrap();
      ClapTrap(std::string& name);
      ClapTrap(std::string& name, int hp, int ep, int dmg);
      ClapTrap(const ClapTrap &copy);
      ClapTrap &operator=(const ClapTrap &copy);
      ~ClapTrap();

      void setName(const std::string& value);
      void setHP(int value);
      void setEP(int value);
      void setDMG(int value);
      std::string getName(void) const;
      int getHP(void) const ;
      int getEP(void) const ;
      int getDMG(void) const ;

      void attack(const std::string& target);
      void takeDamage(unsigned int amount);
      void beRepaired(unsigned int amount);

private:
      std::string m_name;
      int m_hp;
      int m_ep;
      int m_dmg;
};
