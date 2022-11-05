#pragma once

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal {
public:
      Cat();
      Cat(const Cat &copy);
      Cat &operator=(const Cat &copy);
      ~Cat();

      Brain* getBrain(void);

      void makeSound() const;

private:
      Brain* m_brain;

};
