#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
      HumanA(Weapon &w);
      HumanA(const HumanA &humanA);
      HumanA(const std::string &name, Weapon &w);
      ~HumanA();

      void setName(std::string value);
      void setWeapon(Weapon &w);
      std::string getName(void);

      void attack(void);

private:
      std::string m_name;
      Weapon      &m_w;
};
