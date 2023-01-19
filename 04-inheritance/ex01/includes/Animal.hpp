#pragma once

#include <iostream>

class	Animal {
public:
      Animal(const std::string& type = "Animal");
      Animal(const Animal &copy);
      Animal &operator=(const Animal &copy);
      virtual ~Animal();

      void setType(const std::string& value);
      std::string getType(void) const;

      virtual void makeSound() const ;

protected:
      std::string m_type;
};
