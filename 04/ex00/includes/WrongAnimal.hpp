#pragma once

#include <iostream>

class	WrongAnimal {
public:
      WrongAnimal(const std::string& type = "WrongAnimal");
      WrongAnimal(const WrongAnimal &copy);
      WrongAnimal &operator=(const WrongAnimal &copy);
      virtual ~WrongAnimal();

      void setType(const std::string& value);
      std::string getType(void) const;

      virtual void makeSound() const ;

protected:
      std::string m_type;
};
