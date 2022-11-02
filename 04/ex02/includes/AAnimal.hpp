#pragma once

#include <iostream>

class	AAnimal {
public:
      virtual AAnimal &operator=(const AAnimal &copy);
      virtual ~AAnimal();

      virtual void setType(const std::string& value);
      std::string getType(void) const;

      virtual void makeSound() const ;

protected:
      AAnimal(const std::string& type);
      AAnimal(const AAnimal &copy);
      std::string m_type;
};
