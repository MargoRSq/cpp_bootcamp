#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap : public ClapTrap {
public:
      FragTrap();
      FragTrap(const std::string& name);
      FragTrap(std::string& name, int hp, int ep, int dmg);
      FragTrap(const FragTrap &copy);
      FragTrap &operator=(const FragTrap &copy);
      ~FragTrap();

      void highFivesGuys(void);

private:

};
