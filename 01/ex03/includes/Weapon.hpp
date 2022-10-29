#pragma once

#include <iostream>

class Weapon {
public:
      Weapon();
      Weapon(const std::string name);
      Weapon(const Weapon &Weapon);
      ~Weapon();
      // Contact & operator = (const Contact &contact);

      void setType(std::string value);
      std::string getType(void);

private:
      std::string m_type;
};
