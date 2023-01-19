#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class	ScavTrap : public ClapTrap {
public:
      ScavTrap();
      ScavTrap(const std::string& name);
      ScavTrap(std::string& name, int hp, int ep, int dmg);
      ScavTrap(const ScavTrap &copy);
      ScavTrap &operator=(const ScavTrap &copy);
      ~ScavTrap();

      void guardGate(void);
      void attack(const std::string& target);

private:

};
