#pragma once

#include <iostream>

class Zombie {
public:
      Zombie();
      Zombie(const std::string name);
      Zombie(const Zombie &zombie);
      ~Zombie();
      // Contact & operator = (const Contact &contact);

      void setName(std::string value);
      std::string getName(void);

      void announce(void);

private:
      std::string m_name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);