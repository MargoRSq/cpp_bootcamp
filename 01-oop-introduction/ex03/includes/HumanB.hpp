#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {
public:
      HumanB(const std::string &name);
      HumanB(const std::string &name, Weapon &w);
      HumanB(const HumanB &HumanB);
      ~HumanB();

      void setName(std::string value);
      void setWeapon(Weapon &w);
      std::string getName(void);

      void attack(void);

private:
      std::string m_name;
      Weapon      *m_w;
};
