#pragma once

#include <iostream>

class Zombie {
public:
      Zombie();
      Zombie(const Zombie &zombie);
      ~Zombie();
      // Contact & operator = (const Contact &contact);

      void setName( std::string value );
      std::string getName( void );

      void announce( void );
      Zombie* newZombie( std::string name );
      void randomChump( std::string name );

private:
      std::string m_firstName;
      std::string m_lastName;
      std::string m_nickname;
      std::string m_phoneNumber;
      std::string m_darkestSecret;
};
