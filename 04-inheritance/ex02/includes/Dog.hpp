#pragma once

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal {
public:
      Dog();
      Dog(const Dog &copy);
      Dog &operator=(const Dog &copy);
      ~Dog();

      Brain* getBrain(void);

      void makeSound() const;

private:
      Brain* m_brain;

};
